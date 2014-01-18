#import <UIKit/UIKit.h>
#import <UIKit/UIPageController.h>
#import <UIKit/UIScrollViewPagingSwipeGestureRecognizer.h>
#import <CaptainHook/CaptainHook.h>
#import <MediaPlayer/MediaPlayer.h>
#import <AVFoundation/AVFoundation.h>
#import <QuartzCore/QuartzCore.h>

#ifdef NSTextAlignmentCenter // iOS6 and later
#   define lyricsAlignmentCenter    NSTextAlignmentCenter
#   define lyricsAlignmentLeft      NSTextAlignmentLeft
#   define lyricsAlignmentRight     NSTextAlignmentRight
#else // older versions
#   define lyricsAlignmentCenter    UITextAlignmentCenter
#   define lyricsAlignmentLeft      UITextAlignmentLeft
#   define lyricsAlignmentRight     UITextAlignmentRight
#endif

#define PreferencesChangedNotification "com.autopear.lyricsforipad.preferenceschanged"
#define PreferencesFilePath [NSHomeDirectory() stringByAppendingPathComponent:@"Library/Preferences/com.autopear.lyricsforipad.plist"]

%config(generator=internal)

@interface MusicPlaybackView : UIView {
	UIImageView* _albumView;
}
@end

@interface MusicQueryNowPlayingItem
- (unsigned long long)persistentID;
@end

@interface MusicPlaybackViewController : UIViewController {
	MusicQueryNowPlayingItem* _item;
	UIPageController* _pageController;
	UITapGestureRecognizer* _doubleTapGestureRecognizer;
	UIPinchGestureRecognizer* _pinchGestureRecognizer;
	UITapGestureRecognizer* _tapGestureRecognizer;
}
- (void)_setItem:(id)item;
- (void)_itemDidChangeNotification:(id)_item;
- (void)_viewDidRecognizeTap:(id)_view;
- (void)_viewDidRecognizeDoubleTap:(id)_view;
- (void)willAnimateRotationToInterfaceOrientation:(int)interfaceOrientation duration:(double)duration;
- (void)viewWillDisappear:(BOOL)animated;
- (void)viewDidLoad;
@end

@interface MusicPlaybackItemViewController : UIViewController {
	MusicPlaybackView* _playbackView;
}
@end

@interface UIPlaybackLyricsView : UITextView <UITextViewDelegate, UIActionSheetDelegate> {
    BOOL _allowChangeEncoding;
    NSStringEncoding _encoding;
    unsigned long long _persistentID;
    NSString *_lyrics;
    UIButton *longPressButton;
    CAGradientLayer *_upperLayer;
    CAGradientLayer *_lowerLayer;
}
@property(nonatomic) BOOL allowChangeEncoding;
@property(nonatomic) unsigned long long persistentID;
- (id)initWithFrame:(CGRect)frame;
- (BOOL)canBecomeFirstResponder;
- (void)changeEncoding:(UIGestureRecognizer *)sender;
- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)setLyrics:(NSString *)text;
- (void)setViewFrame:(CGRect)frame;
- (void)dealloc;
@end

@implementation UIPlaybackLyricsView

@synthesize allowChangeEncoding = _allowChangeEncoding;
@synthesize persistentID = _persistentID;

- (void)dealloc {
    [_lyrics release];
    [super dealloc];
}

- (BOOL)canBecomeFirstResponder {
    return NO;
}

- (void)setViewFrame:(CGRect)frame {
    self.frame = frame;
    longPressButton.frame = CGRectMake(0, 0, frame.size.width, frame.size.height);
    _upperLayer.frame = CGRectMake(0, 0, frame.size.width, 15.0f);
    _lowerLayer.frame = CGRectMake(0, frame.size.height-15.0f, frame.size.width, 15.0f);
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    longPressButton.frame = CGRectMake(0, scrollView.contentOffset.y, scrollView.frame.size.width, scrollView.frame.size.height);
}

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self)
    {
        self.editable = NO;
        self.textAlignment = lyricsAlignmentCenter;
        self.backgroundColor = [UIColor clearColor];
        self.showsHorizontalScrollIndicator = NO;
        self.directionalLockEnabled = YES;
        self.userInteractionEnabled = YES;
        self.dataDetectorTypes = UIDataDetectorTypeNone;
        self.bounces = YES;
        self.alwaysBounceVertical = YES;
        self.delegate = self;

        UILongPressGestureRecognizer *_longPressGestureRecognizer = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(changeEncoding:)];
        _longPressGestureRecognizer.cancelsTouchesInView = NO;

        longPressButton = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, frame.size.width, frame.size.height)];

        _upperLayer = [CAGradientLayer layer];
        _upperLayer.frame = CGRectMake(0, 0, longPressButton.frame.size.width, 15.0f);
        _upperLayer.colors = [NSArray arrayWithObjects:(id)[[UIColor blackColor] CGColor], (id)[[UIColor clearColor] CGColor], nil];
        [longPressButton.layer insertSublayer:_upperLayer atIndex:0];

        _lowerLayer = [CAGradientLayer layer];
        _lowerLayer.frame = CGRectMake(0, frame.size.height - 15.0f, frame.size.width, 15.0f);
        _lowerLayer.colors = [NSArray arrayWithObjects:(id)[[UIColor clearColor] CGColor], (id)[[UIColor blackColor] CGColor], nil];
        [longPressButton.layer insertSublayer:_lowerLayer atIndex:0];

		[longPressButton addGestureRecognizer:_longPressGestureRecognizer];
        [self addSubview:longPressButton];

        [longPressButton addGestureRecognizer:_longPressGestureRecognizer];
        [_longPressGestureRecognizer release];

        _allowChangeEncoding = YES;

        _encoding = NSUTF8StringEncoding;

        [longPressButton release];
    }
    return self;
}

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer {
    return YES;
}

- (void)setLyrics:(NSString *)text {
    if ([text length] <= 0) {
        _lyrics = @"";
        self.text = @"";
        return;
    }

    text = [text stringByReplacingOccurrencesOfString:@"\u2028" withString:@"\n"]; //UTF-8 line break
    text = [text stringByReplacingOccurrencesOfString:@"\r\n" withString:@"\n"];
    text = [text stringByReplacingOccurrencesOfString:@"\r" withString:@"\n"];
    text = [@"\n" stringByAppendingString:text];
    text = [text stringByAppendingString:@"\n"];

    _lyrics = [[NSString stringWithString:text] retain];

    NSDictionary *lyricsDict = [NSDictionary dictionaryWithContentsOfFile:PreferencesFilePath];
    NSString *strPersistentID = [NSString stringWithFormat:@"MusicID-%llu", _persistentID];
    if (lyricsDict && [lyricsDict objectForKey:strPersistentID]) {
        NSString *encodingName = [lyricsDict objectForKey:strPersistentID];
        if ([encodingName isEqualToString:@"ASCII"])
            _encoding = NSASCIIStringEncoding;
        else if ([encodingName isEqualToString:@"NEXTSTEP"])
            _encoding = NSNEXTSTEPStringEncoding;
        else if ([encodingName isEqualToString:@"JapaneseEUC"])
            _encoding = NSJapaneseEUCStringEncoding;
        else if ([encodingName isEqualToString:@"ISOLatin1"])
            _encoding = NSISOLatin1StringEncoding;
        else if ([encodingName isEqualToString:@"Symbol"])
            _encoding = NSSymbolStringEncoding;
        else if ([encodingName isEqualToString:@"NonLossyASCII"])
            _encoding = NSNonLossyASCIIStringEncoding;
        else if ([encodingName isEqualToString:@"ShiftJIS"])
            _encoding = NSShiftJISStringEncoding;
        else if ([encodingName isEqualToString:@"ISOLatin2"])
            _encoding = NSISOLatin2StringEncoding;
        else if ([encodingName isEqualToString:@"Unicode"])
            _encoding = NSUnicodeStringEncoding;
        else if ([encodingName isEqualToString:@"WindowsCP1251"])
            _encoding = NSWindowsCP1251StringEncoding;
        else if ([encodingName isEqualToString:@"WindowsCP1252"])
            _encoding = NSWindowsCP1252StringEncoding;
        else if ([encodingName isEqualToString:@"WindowsCP1253"])
            _encoding = NSWindowsCP1253StringEncoding;
        else if ([encodingName isEqualToString:@"WindowsCP1254"])
            _encoding = NSWindowsCP1254StringEncoding;
        else if ([encodingName isEqualToString:@"WindowsCP1250"])
            _encoding = NSWindowsCP1250StringEncoding;
        else if ([encodingName isEqualToString:@"ISO2022JP"])
            _encoding = NSISO2022JPStringEncoding;
        else if ([encodingName isEqualToString:@"MacOSRoman"])
            _encoding = NSMacOSRomanStringEncoding;
        else if ([encodingName isEqualToString:@"UTF16BigEndian"])
            _encoding = NSUTF16BigEndianStringEncoding;
        else if ([encodingName isEqualToString:@"UTF16LittleEndian"])
            _encoding = NSUTF16LittleEndianStringEncoding;
        else if ([encodingName isEqualToString:@"UTF32"])
            _encoding = NSUTF32StringEncoding;
        else if ([encodingName isEqualToString:@"UTF32BigEndian"])
            _encoding = NSUTF32BigEndianStringEncoding;
        else if ([encodingName isEqualToString:@"UTF32LittleEndian"])
            _encoding = NSUTF32LittleEndianStringEncoding;
        else if ([encodingName isEqualToString:@"Proprietary"])
            _encoding = NSProprietaryStringEncoding;
        else if ([encodingName isEqualToString:@"ISO2022JP"])
            _encoding = NSISO2022JPStringEncoding;
        else if ([encodingName isEqualToString:@"ISO2022JP"])
            _encoding = NSISO2022JPStringEncoding;
        else if ([encodingName isEqualToString:@"ISO2022JP"])
            _encoding = NSISO2022JPStringEncoding;
        else
            _encoding = NSUTF8StringEncoding;

	    NSData *lyricsData = [text dataUsingEncoding:NSUTF8StringEncoding];
        NSString *lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:_encoding];

        self.text = lyricsConverted;
        [lyricsConverted release];
    }
    else
        self.text = text;
}

- (void)changeEncoding:(UIGestureRecognizer *)sender {
    if (_allowChangeEncoding && sender.state == UIGestureRecognizerStateEnded) {
        if ([_lyrics length] > 0) {
            NSData *lyricsData = [_lyrics dataUsingEncoding:NSUTF8StringEncoding];

            if (lyricsData) {
                UIActionSheet *_encodingsSheet = [[UIActionSheet alloc] init];

                _encodingsSheet.title = nil;
                _encodingsSheet.delegate = self;

                NSString *lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSASCIIStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"ASCII"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSISOLatin1StringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"ISOLatin1"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSISOLatin2StringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"ISOLatin2"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSISO2022JPStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"ISO2022JP"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSJapaneseEUCStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"JapaneseEUC"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSMacOSRomanStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"MacOSRoman"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSNEXTSTEPStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"NEXTSTEP"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSNonLossyASCIIStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"NonLossyASCII"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSProprietaryStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"Proprietary"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSShiftJISStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"ShiftJIS"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSSymbolStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"Symbol"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSUnicodeStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"Unicode"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSUTF16BigEndianStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"UTF16BigEndian"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSUTF16LittleEndianStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"UTF16LittleEndian"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSUTF32StringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"UTF32"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSUTF32BigEndianStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"UTF32BigEndian"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSUTF32LittleEndianStringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"UTF32LittleEndian"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSWindowsCP1251StringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"WindowsCP1251"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSWindowsCP1250StringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"WindowsCP1250"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSWindowsCP1252StringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"WindowsCP1251"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSWindowsCP1253StringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"WindowsCP1253"];
                }

                lyricsConverted = nil;
                lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:NSWindowsCP1254StringEncoding];
                if (lyricsConverted) {
                    [lyricsConverted release];
                    [_encodingsSheet addButtonWithTitle:@"WindowsCP1254"];
                }

                //Must have UTF8
                [_encodingsSheet addButtonWithTitle:@"UTF8"];

                _encodingsSheet.actionSheetStyle = UIActionSheetStyleDefault;
                [_encodingsSheet showInView:longPressButton];
                [_encodingsSheet release];
            }
        }
    }
}

-(void) actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex {
    if (buttonIndex != [actionSheet cancelButtonIndex]) {
        NSString *encodingName = [actionSheet buttonTitleAtIndex:buttonIndex];

        if ([encodingName isEqualToString:@"ASCII"])
            _encoding = NSASCIIStringEncoding;
        else if ([encodingName isEqualToString:@"NEXTSTEP"])
            _encoding = NSNEXTSTEPStringEncoding;
        else if ([encodingName isEqualToString:@"JapaneseEUC"])
            _encoding = NSJapaneseEUCStringEncoding;
        else if ([encodingName isEqualToString:@"ISOLatin1"])
            _encoding = NSISOLatin1StringEncoding;
        else if ([encodingName isEqualToString:@"Symbol"])
            _encoding = NSSymbolStringEncoding;
        else if ([encodingName isEqualToString:@"NonLossyASCII"])
            _encoding = NSNonLossyASCIIStringEncoding;
        else if ([encodingName isEqualToString:@"ShiftJIS"])
            _encoding = NSShiftJISStringEncoding;
        else if ([encodingName isEqualToString:@"ISOLatin2"])
            _encoding = NSISOLatin2StringEncoding;
        else if ([encodingName isEqualToString:@"Unicode"])
            _encoding = NSUnicodeStringEncoding;
        else if ([encodingName isEqualToString:@"WindowsCP1251"])
            _encoding = NSWindowsCP1251StringEncoding;
        else if ([encodingName isEqualToString:@"WindowsCP1252"])
            _encoding = NSWindowsCP1252StringEncoding;
        else if ([encodingName isEqualToString:@"WindowsCP1253"])
            _encoding = NSWindowsCP1253StringEncoding;
        else if ([encodingName isEqualToString:@"WindowsCP1254"])
            _encoding = NSWindowsCP1254StringEncoding;
        else if ([encodingName isEqualToString:@"WindowsCP1250"])
            _encoding = NSWindowsCP1250StringEncoding;
        else if ([encodingName isEqualToString:@"ISO2022JP"])
            _encoding = NSISO2022JPStringEncoding;
        else if ([encodingName isEqualToString:@"MacOSRoman"])
            _encoding = NSMacOSRomanStringEncoding;
        else if ([encodingName isEqualToString:@"UTF16BigEndian"])
            _encoding = NSUTF16BigEndianStringEncoding;
        else if ([encodingName isEqualToString:@"UTF16LittleEndian"])
            _encoding = NSUTF16LittleEndianStringEncoding;
        else if ([encodingName isEqualToString:@"UTF32"])
            _encoding = NSUTF32StringEncoding;
        else if ([encodingName isEqualToString:@"UTF32BigEndian"])
            _encoding = NSUTF32BigEndianStringEncoding;
        else if ([encodingName isEqualToString:@"UTF32LittleEndian"])
            _encoding = NSUTF32LittleEndianStringEncoding;
        else if ([encodingName isEqualToString:@"Proprietary"])
            _encoding = NSProprietaryStringEncoding;
        else if ([encodingName isEqualToString:@"ISO2022JP"])
            _encoding = NSISO2022JPStringEncoding;
        else if ([encodingName isEqualToString:@"ISO2022JP"])
            _encoding = NSISO2022JPStringEncoding;
        else if ([encodingName isEqualToString:@"ISO2022JP"])
            _encoding = NSISO2022JPStringEncoding;
        else
            _encoding = NSUTF8StringEncoding;

	    NSData *lyricsData = [_lyrics dataUsingEncoding:NSUTF8StringEncoding];
        NSString *lyricsConverted = [[NSString alloc] initWithData:lyricsData encoding:_encoding];

        self.text = lyricsConverted;
        [lyricsConverted release];

        //Save preferences
        NSMutableDictionary *lyricsDict = [NSMutableDictionary dictionaryWithContentsOfFile:PreferencesFilePath];

        NSString *strPersistentID = [NSString stringWithFormat:@"MusicID-%llu", _persistentID];

        BOOL shouldWritePreferences = NO;
        if (![lyricsDict objectForKey:strPersistentID]) {
            if (![encodingName isEqualToString:@"UTF8"]) {
                [lyricsDict setObject:encodingName forKey:strPersistentID];
                shouldWritePreferences= YES;
            }
        } else {
            if ([encodingName isEqualToString:@"UTF8"]) {
                [lyricsDict removeObjectForKey:strPersistentID];
                shouldWritePreferences= YES;
            } else {
                if (![[lyricsDict objectForKey:strPersistentID] isEqualToString:encodingName]) {
                    [lyricsDict setObject:encodingName forKey:strPersistentID];
                    shouldWritePreferences= YES;
                }
            }
        }
        if (shouldWritePreferences)
            [lyricsDict writeToFile:PreferencesFilePath atomically:YES];

        [actionSheet dismissWithClickedButtonIndex:[actionSheet cancelButtonIndex] animated:YES];
    }
}

@end

//Preferences
static BOOL LyricsEnabled = YES;
static NSString *FontName = @"Helvetica-Bold";
static int FontSize = 18;
static UIColor *FontColor = [UIColor whiteColor];
static CGFloat OverlayAlpha = 0.4f;
static UIColor *OverlayColor = [UIColor blackColor];
static int TextAlignment = 1;
static BOOL SwipeEnabled = NO;
static UIViewAnimationOptions LyricsShowAnimation = UIViewAnimationOptionTransitionFlipFromTop;
static UIViewAnimationOptions LyricsDimissAnimation = UIViewAnimationOptionTransitionFlipFromBottom;
static BOOL AllowChangeEncoding = NO;

static UIPlaybackLyricsView *lyricsView = nil;
static UIView *backgroundView = nil;

static void LoadPreferences() {
    NSDictionary *preferences = [[NSDictionary alloc] initWithContentsOfFile:PreferencesFilePath];
	if (preferences) {
        if ([[preferences allKeys] containsObject:@"lyricsEnabled"])
            LyricsEnabled = [[preferences objectForKey:@"lyricsEnabled"] boolValue];
        else
            LyricsEnabled = YES;

        if ([[preferences allKeys] containsObject:@"lyricsSwipeEnabled"])
            SwipeEnabled = [[preferences objectForKey:@"lyricsSwipeEnabled"] boolValue];
        else
            SwipeEnabled = NO;

        if ([[preferences allKeys] containsObject:@"lyricsTextSize"]) {
            int readFontSize = [[preferences objectForKey:@"lyricsTextSize"] intValue];
            if (readFontSize < 10)
                FontSize = 10;
            else if (readFontSize > 40)
                FontSize = 40;
            else
                FontSize = readFontSize;
        } else
            FontSize = 18;

        if ([[preferences allKeys] containsObject:@"lyricsFontName"])
            FontName = [[preferences objectForKey:@"lyricsFontName"] retain];
        else
            FontName = [[NSString stringWithFormat:@"Helvetica"] retain];

        NSArray *colorArray = [[NSArray alloc] initWithObjects:[UIColor blackColor], [UIColor darkGrayColor], [UIColor lightGrayColor], [UIColor whiteColor], [UIColor grayColor], [UIColor redColor], [UIColor greenColor], [UIColor blueColor], [UIColor cyanColor], [UIColor yellowColor], [UIColor magentaColor], [UIColor orangeColor], [UIColor purpleColor], [UIColor brownColor], nil];

        if ([[preferences allKeys] containsObject:@"lyricsTextColor"]) {
            int readFontColor = [[preferences objectForKey:@"lyricsTextColor"] intValue];
            if (readFontColor < 0 || readFontColor > 13)
                FontColor = [UIColor whiteColor];
            else
                FontColor = [colorArray objectAtIndex:readFontColor];
        } else
            FontColor = [UIColor whiteColor];

        if ([[preferences allKeys] containsObject:@"lyricsTextAlignment"]) {
            int readTextAlignment = [[preferences objectForKey:@"lyricsTextAlignment"] intValue];
            if (readTextAlignment < 0 || readTextAlignment > 2)
                TextAlignment = 1;
            else
                TextAlignment = readTextAlignment;
        } else
            TextAlignment = 1;

        if ([[preferences allKeys] containsObject:@"lyricsBackgroundTransparency"]) {
            CGFloat readAlpha = [[preferences objectForKey:@"lyricsBackgroundTransparency"] floatValue];
            if (readAlpha < 0.0f)
                OverlayAlpha = 1.0f;
            else if (readAlpha > 100.0f)
                OverlayAlpha = 0.0f;
            else
                OverlayAlpha = (100.0f - readAlpha) / 100;
        } else
            OverlayAlpha = 0.4f;

        if ([[preferences allKeys] containsObject:@"lyricsBackgroundColor"]) {
            int readOverlayColor = [[preferences objectForKey:@"lyricsBackgroundColor"] intValue];
            if (readOverlayColor < 0 || readOverlayColor > 13)
                OverlayColor = [UIColor blackColor];
            else
                OverlayColor = [colorArray objectAtIndex:readOverlayColor];
        } else
            OverlayColor = [UIColor blackColor];

        [colorArray release];

        if ([[preferences allKeys] containsObject:@"lyricsShowAnimation"]) {
            int readLyricsShowAnimation = [[preferences objectForKey:@"lyricsShowAnimation"] intValue];
            if (readLyricsShowAnimation == 1)
                LyricsShowAnimation = UIViewAnimationOptionTransitionFlipFromLeft;
            else if (readLyricsShowAnimation == 2)
                LyricsShowAnimation = UIViewAnimationOptionTransitionFlipFromRight;
            else if (readLyricsShowAnimation == 3)
                LyricsShowAnimation = UIViewAnimationOptionTransitionCurlUp;
            else if (readLyricsShowAnimation == 4)
                LyricsShowAnimation = UIViewAnimationOptionTransitionCurlDown;
            else if (readLyricsShowAnimation == 5)
                LyricsShowAnimation = UIViewAnimationOptionTransitionCrossDissolve;
            else if (readLyricsShowAnimation == 6)
                LyricsShowAnimation = UIViewAnimationOptionTransitionFlipFromTop;
            else if (readLyricsShowAnimation == 7)
                LyricsShowAnimation = UIViewAnimationOptionTransitionFlipFromBottom;
            else
                LyricsShowAnimation = UIViewAnimationOptionTransitionNone;
        } else
            LyricsShowAnimation = UIViewAnimationOptionTransitionFlipFromTop;

        if ([[preferences allKeys] containsObject:@"lyricsDismissAnimation"]) {
            int readLyricsDimissAnimation = [[preferences objectForKey:@"lyricsDismissAnimation"] intValue];
            if (readLyricsDimissAnimation == 1)
                LyricsDimissAnimation = UIViewAnimationOptionTransitionFlipFromLeft;
            else if (readLyricsDimissAnimation == 2)
                LyricsDimissAnimation = UIViewAnimationOptionTransitionFlipFromRight;
            else if (readLyricsDimissAnimation == 3)
                LyricsDimissAnimation = UIViewAnimationOptionTransitionCurlUp;
            else if (readLyricsDimissAnimation == 4)
                LyricsDimissAnimation = UIViewAnimationOptionTransitionCurlDown;
            else if (readLyricsDimissAnimation == 5)
                LyricsDimissAnimation = UIViewAnimationOptionTransitionCrossDissolve;
            else if (readLyricsDimissAnimation == 6)
                LyricsDimissAnimation = UIViewAnimationOptionTransitionFlipFromTop;
            else if (readLyricsDimissAnimation == 7)
                LyricsDimissAnimation = UIViewAnimationOptionTransitionFlipFromBottom;
            else
                LyricsDimissAnimation = UIViewAnimationOptionTransitionNone;
        } else
            LyricsShowAnimation = UIViewAnimationOptionTransitionFlipFromBottom;

        if ([[preferences allKeys] containsObject:@"lyricsEncodingEnabled"]) {
            AllowChangeEncoding = [[preferences objectForKey:@"lyricsEncodingEnabled"] boolValue];
        } else
            AllowChangeEncoding = NO;
    } else {
        LyricsEnabled = YES;
        SwipeEnabled = NO;

        FontColor = [UIColor whiteColor];
        FontName = [[NSString stringWithFormat:@"Helvetica"] retain];
        FontSize = 18;
        TextAlignment = 1;
        OverlayColor = [UIColor blackColor];
        OverlayAlpha = 0.4f;
        AllowChangeEncoding = NO;

        LyricsShowAnimation = UIViewAnimationOptionTransitionFlipFromTop;
        LyricsDimissAnimation = UIViewAnimationOptionTransitionFlipFromBottom;
    }

    [preferences release];

    if (LyricsEnabled) {
        if (lyricsView) {
            lyricsView.textColor = FontColor;
            [lyricsView setFont:[UIFont fontWithName:FontName size:FontSize]];
            lyricsView.allowChangeEncoding = AllowChangeEncoding;
            if (TextAlignment == 0) //Left
                lyricsView.textAlignment = lyricsAlignmentLeft;
            else if (TextAlignment == 2) //Right
                lyricsView.textAlignment = lyricsAlignmentRight;
            else //Center
                lyricsView.textAlignment = lyricsAlignmentCenter;
        }

        if (backgroundView) {
            backgroundView.alpha = OverlayAlpha;
            backgroundView.backgroundColor = OverlayColor;
        }
    } else {
        if (backgroundView) {
            if (backgroundView.superview)
                [backgroundView removeFromSuperview];
            [backgroundView release];
            backgroundView = nil;
        }

        if (lyricsView) {
            if (lyricsView.superview)
                [lyricsView removeFromSuperview];
            [lyricsView release];
            lyricsView = nil;
        }
    }
}

static void PreferencesChangedCallback(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo) {
    LoadPreferences();
}


%hook MusicPlaybackViewController

static int isLyricsViewFront = -1; //not init = -1, showing = 1, dismiss = 0

-(void)dealloc {
    if (backgroundView)
    {
        if (backgroundView.superview)
            [backgroundView removeFromSuperview];
        backgroundView = nil;
    }
    [backgroundView release];

    if (lyricsView) {
        if (lyricsView.superview)
            [lyricsView removeFromSuperview];
        lyricsView = nil;
    }
    [lyricsView release];

    [FontName release];
    [FontColor release];
    [OverlayColor release];

    %orig;
}

-(void)_setItem:(id)item {
    %orig(item);

    if (!LyricsEnabled || !item)
        return;

    BOOL isLandscape = NO;

    if ([self.view.subviews count] == 4) {
        UIView *resizedView = [self.view.subviews objectAtIndex:1];

        isLandscape = (resizedView.frame.size.width == 1024.0f);

        if ((resizedView.frame.size.width == 1024.0f && resizedView.frame.size.height == 768.0f) || (resizedView.frame.size.width == 768.0f && resizedView.frame.size.height == 1024.0f)) {
            if (isLyricsViewFront == 1)
                isLyricsViewFront = 0;
        } else {
            if (isLyricsViewFront == 0)
                isLyricsViewFront = 1;
        }
    }

    MusicQueryNowPlayingItem *playingItem = (MusicQueryNowPlayingItem *)item;

    NSNumber *numberID = [[NSNumber alloc] initWithUnsignedLongLong:[playingItem persistentID]];

    MPMediaPropertyPredicate *persistentIDPredicate = [MPMediaPropertyPredicate predicateWithValue:numberID forProperty:MPMediaItemPropertyPersistentID];
    [numberID release];

    MPMediaQuery *lyricsQuery = [[MPMediaQuery alloc] init];
    [lyricsQuery addFilterPredicate: persistentIDPredicate];

    NSArray *obtainedItems = [lyricsQuery items];
    [lyricsQuery release];

    NSURL* songURL = [(MPMediaItem *)[obtainedItems objectAtIndex:0] valueForProperty:MPMediaItemPropertyAssetURL];
    AVAsset* songAsset = [AVURLAsset URLAssetWithURL:songURL options:nil];
    NSString *lyrics = [songAsset lyrics];

    UIPageController *_pageController = (UIPageController *)CHIvar(self, _pageController, UIPageController *);

    NSMutableArray *_viewControllers = (NSMutableArray *)CHIvar(_pageController, _viewControllers, NSMutableArray *);

    MusicPlaybackItemViewController *itemViewController = (MusicPlaybackItemViewController*)[_viewControllers objectAtIndex:1];

    MusicPlaybackView* _playbackView = (MusicPlaybackView *)CHIvar(itemViewController, _playbackView, MusicPlaybackView *);

    UIImageView *_albumView = (UIImageView *)CHIvar(_playbackView, _albumView, UIImageView *);

    CGRect lyricsViewFrame;
    if (isLandscape)
        lyricsViewFrame = CGRectMake(192.0f, 10.0f, 640.0f, 640.0f);
    else
        lyricsViewFrame = CGRectMake(0.0f, 74.0f, 768.0f, 768.0f);

    if (lyricsView) {
        if (lyricsView.superview)
            [lyricsView removeFromSuperview];
        if (backgroundView.superview)
            [backgroundView removeFromSuperview];

        [lyricsView setViewFrame:lyricsViewFrame];
        backgroundView.frame = lyricsViewFrame;

        lyricsView.persistentID = [playingItem persistentID];
        [lyricsView setLyrics:lyrics];

        if (isLyricsViewFront == 1) {
            lyricsView.hidden = NO;
            backgroundView.hidden = NO;
            [UIView transitionWithView:_playbackView duration:1.0
                               options:(LyricsShowAnimation | UIViewAnimationOptionLayoutSubviews)
                            animations:^ {
                                [_playbackView insertSubview:backgroundView aboveSubview:_albumView];
                                [_playbackView insertSubview:lyricsView aboveSubview:backgroundView];
                            }
                            completion:nil];
        } else {
            [UIView transitionWithView:_playbackView duration:1.0
                               options:(LyricsDimissAnimation | UIViewAnimationOptionLayoutSubviews)
                            animations:^ {
                                [_playbackView insertSubview:lyricsView belowSubview:_albumView];
                                [_playbackView insertSubview:backgroundView belowSubview:lyricsView];
                            }
                            completion:nil];

            backgroundView.hidden = YES;
            lyricsView.hidden = YES;
        }
    } else {
        lyricsView = [[UIPlaybackLyricsView alloc] initWithFrame:lyricsViewFrame];
        lyricsView.textColor = FontColor;
        [lyricsView setFont:[UIFont fontWithName:FontName size:FontSize]];
        lyricsView.allowChangeEncoding = AllowChangeEncoding;
        if (TextAlignment == 0) //Left
            lyricsView.textAlignment = lyricsAlignmentLeft;
        else if (TextAlignment == 2) //Right
            lyricsView.textAlignment = lyricsAlignmentRight;
        else //Center
            lyricsView.textAlignment = lyricsAlignmentCenter;

        lyricsView.persistentID = [playingItem persistentID];

        [lyricsView setLyrics:lyrics];

        backgroundView = [[UIView alloc] initWithFrame:lyricsViewFrame];
        backgroundView.backgroundColor = OverlayColor;
        backgroundView.alpha = OverlayAlpha;
        backgroundView.userInteractionEnabled = YES;

        if (isLyricsViewFront < 1) {
            [UIView transitionWithView:_playbackView duration:1.0
                               options:(LyricsDimissAnimation | UIViewAnimationOptionLayoutSubviews)
                            animations:^ {
                                [_playbackView insertSubview:lyricsView belowSubview:_albumView];
                                [_playbackView insertSubview:backgroundView belowSubview:lyricsView];
                            }
                            completion:nil];

            isLyricsViewFront = 0;
            lyricsView.hidden = YES;
            backgroundView.hidden = YES;
        } else {
            backgroundView.hidden = NO;
            lyricsView.hidden = NO;
            isLyricsViewFront = 1;

            [UIView transitionWithView:_playbackView duration:1.0
                               options:(LyricsShowAnimation | UIViewAnimationOptionLayoutSubviews)
                            animations:^ {
                                [_playbackView insertSubview:backgroundView aboveSubview:_albumView];
                                [_playbackView insertSubview:lyricsView aboveSubview:backgroundView];
                            }
                            completion:nil];
        }
    }
}

- (void)viewWillDisappear:(BOOL)animated {
    %orig(animated);

    if (!LyricsEnabled)
        return;

    if (lyricsView.superview)
        [lyricsView removeFromSuperview];
    [lyricsView release];
    lyricsView = nil;

    if (backgroundView.superview)
        [backgroundView removeFromSuperview];
    [backgroundView release];
    backgroundView = nil;

    [FontName release];
    [FontColor release];
    [OverlayColor release];
}

-(void)_itemDidChangeNotification:(id)_item {
    %orig(_item);

    if (!LyricsEnabled)
        return;

    if (lyricsView) {
        BOOL isLandscape = NO;
        if ([self.view.subviews count] == 4) {
            UIView *resizedView = [self.view.subviews objectAtIndex:1];

            isLandscape = (resizedView.frame.size.width == 1024.0f);

            if (((resizedView.frame.size.width == 1024.0f && resizedView.frame.size.height == 768.0f) || (resizedView.frame.size.width == 768.0f && resizedView.frame.size.height == 1024.0f))  && isLyricsViewFront > 0)
                isLyricsViewFront = 0;
        }

        CGRect lyricsViewFrame;
        if (isLandscape)
            lyricsViewFrame = CGRectMake(192.0f, 10.0f, 640.0f, 640.0f);
        else
            lyricsViewFrame = CGRectMake(0.0f, 74.0f, 768.0f, 768.0f);

        UIPageController *_pageController = (UIPageController *)CHIvar(self, _pageController, UIPageController *);

        NSMutableArray *_viewControllers = (NSMutableArray *)CHIvar(_pageController, _viewControllers, NSMutableArray *);

        MusicPlaybackItemViewController *itemViewController = (MusicPlaybackItemViewController*)[_viewControllers objectAtIndex:1];

        MusicPlaybackView* _playbackView = (MusicPlaybackView *)CHIvar(itemViewController, _playbackView, MusicPlaybackView *);

        UIImageView *_albumView = (UIImageView *)CHIvar(_playbackView, _albumView, UIImageView *);

        if (lyricsView.superview)
            [lyricsView removeFromSuperview];
        if (backgroundView.superview)
            [backgroundView removeFromSuperview];

        if (isLyricsViewFront == 1) {
            [lyricsView setViewFrame:lyricsViewFrame];
            backgroundView.frame = lyricsViewFrame;

            backgroundView.hidden = NO;
            lyricsView.hidden = NO;

            [UIView transitionWithView:_playbackView duration:1.0
                               options:(LyricsShowAnimation | UIViewAnimationOptionLayoutSubviews)
                            animations:^ {
                                [_playbackView insertSubview:backgroundView aboveSubview:_albumView];
                                [_playbackView insertSubview:lyricsView aboveSubview:backgroundView];
                            }
                            completion:nil];
        }
        if (isLyricsViewFront == 0) {
            [lyricsView setViewFrame:lyricsViewFrame];
            backgroundView.frame = lyricsViewFrame;

            [UIView transitionWithView:_playbackView duration:1.0
                               options:(LyricsDimissAnimation | UIViewAnimationOptionLayoutSubviews)
                            animations:^ {
                                [_playbackView insertSubview:lyricsView belowSubview:_albumView];
                                [_playbackView insertSubview:backgroundView belowSubview:lyricsView];
                            }
                            completion:nil];

            lyricsView.hidden = YES;
            backgroundView.hidden = YES;
        }
    }
}

-(void)_viewDidRecognizeTap:(id)_view {
    %orig(_view);

    if (!LyricsEnabled)
        return;

    BOOL isLandscape = NO;
    if ([self.view.subviews count] == 4) {
        UIView *resizedView = [self.view.subviews objectAtIndex:1];

        isLandscape = (resizedView.frame.size.width == 1024.0f);

        if ((resizedView.frame.size.width == 1024.0f && resizedView.frame.size.height == 768.0f) || (resizedView.frame.size.width == 768.0f && resizedView.frame.size.height == 1024.0f)) {
            if (isLyricsViewFront == 0)
                isLyricsViewFront = 1;
        }
        else
        {
            if (isLyricsViewFront == 1)
                isLyricsViewFront = 0;
        }
    }

    UIPageController *_pageController = (UIPageController *)CHIvar(self, _pageController, UIPageController *);

    NSMutableArray *_viewControllers = (NSMutableArray *)CHIvar(_pageController, _viewControllers, NSMutableArray *);

    MusicPlaybackItemViewController *itemViewController = (MusicPlaybackItemViewController*)[_viewControllers objectAtIndex:1];

    MusicPlaybackView* _playbackView = (MusicPlaybackView *)CHIvar(itemViewController, _playbackView, MusicPlaybackView *);

    UIImageView *_albumView = (UIImageView *)CHIvar(_playbackView, _albumView, UIImageView *);

    CGRect lyricsViewFrame;
    if (isLandscape)
        lyricsViewFrame = CGRectMake(192.0f, 10.0f, 640.0f, 640.0f);
    else
        lyricsViewFrame = CGRectMake(0.0f, 74.0f, 768.0f, 768.0f);

    if (lyricsView) {
        backgroundView.frame = lyricsViewFrame;
        [lyricsView setViewFrame:lyricsViewFrame];

        if (isLyricsViewFront == 1) {
            [UIView transitionWithView:_playbackView duration:1.0
                               options:(LyricsDimissAnimation | UIViewAnimationOptionLayoutSubviews)
                            animations:^ {
                                [_playbackView sendSubviewToBack:lyricsView];
                                [_playbackView sendSubviewToBack:backgroundView];
                            }
                            completion:nil];

            isLyricsViewFront = 0;
            lyricsView.hidden = YES;
            backgroundView.hidden = YES;
        } else {
            backgroundView.hidden = NO;
            lyricsView.hidden = NO;
            isLyricsViewFront = 1;

            [UIView transitionWithView:_playbackView duration:1.0
                               options:(LyricsShowAnimation | UIViewAnimationOptionLayoutSubviews)
                            animations:^ {
                                [_playbackView bringSubviewToFront:backgroundView];
                                [_playbackView bringSubviewToFront:lyricsView];
                            }
                            completion:nil];
        }
    } else {
        MusicQueryNowPlayingItem *playingItem = (MusicQueryNowPlayingItem *)CHIvar(self, _item, MusicQueryNowPlayingItem *);

        NSNumber *numberID = [[NSNumber alloc] initWithUnsignedLongLong:[playingItem persistentID]];

        MPMediaPropertyPredicate *persistentIDPredicate = [MPMediaPropertyPredicate predicateWithValue:numberID forProperty:MPMediaItemPropertyPersistentID];
        [numberID release];

        MPMediaQuery *lyricsQuery = [[MPMediaQuery alloc] init];
        [lyricsQuery addFilterPredicate: persistentIDPredicate];

        NSArray *obtainedItems = [lyricsQuery items];
        [lyricsQuery release];

        NSURL* songURL = [(MPMediaItem *)[obtainedItems objectAtIndex:0] valueForProperty:MPMediaItemPropertyAssetURL];
        AVAsset* songAsset = [AVURLAsset URLAssetWithURL:songURL options:nil];

        NSString *lyrics = [songAsset lyrics];

        backgroundView = [[UIView alloc] initWithFrame:lyricsViewFrame];
        backgroundView.backgroundColor = OverlayColor;
        backgroundView.alpha = OverlayAlpha;
        backgroundView.hidden = NO;
        backgroundView.userInteractionEnabled = YES;

        lyricsView = [[UIPlaybackLyricsView alloc] initWithFrame:lyricsViewFrame];

        lyricsView.hidden = NO;
        lyricsView.textColor = FontColor;
        [lyricsView setFont:[UIFont fontWithName:FontName size:FontSize]];
        lyricsView.allowChangeEncoding = AllowChangeEncoding;
        if (TextAlignment == 0) //Left
            lyricsView.textAlignment = lyricsAlignmentLeft;
        else if (TextAlignment == 2) //Right
            lyricsView.textAlignment = lyricsAlignmentRight;
        else //Center
            lyricsView.textAlignment = lyricsAlignmentCenter;
        lyricsView.persistentID = [playingItem persistentID];

        [lyricsView setLyrics:lyrics];

        [UIView transitionWithView:_playbackView duration:1.0
                           options:(LyricsShowAnimation | UIViewAnimationOptionLayoutSubviews)
                        animations:^ {
                            [_playbackView insertSubview:backgroundView aboveSubview:_albumView];
                            [_playbackView insertSubview:lyricsView aboveSubview:backgroundView];
                        }
                        completion:nil];

        isLyricsViewFront = 1;
    }
}

-(void)willAnimateRotationToInterfaceOrientation:(int)interfaceOrientation duration:(double)duration {
    %orig(interfaceOrientation, duration);

    if (!LyricsEnabled)
        return;

    if (lyricsView) {
        CGRect lyricsViewFrame;
        if (interfaceOrientation >= 3) //Landscape
            lyricsViewFrame = CGRectMake(192.0f, 10.0f, 640.0f, 640.0f);
        else
            lyricsViewFrame = CGRectMake(0.0f, 74.0f, 768.0f, 768.0f);

        [lyricsView setViewFrame:lyricsViewFrame];
        backgroundView.frame = lyricsViewFrame;
    }
}

%end

%hook UIPageControllerScrollView

- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer {
    CGPoint tapPoint = [gestureRecognizer locationInView:gestureRecognizer.view];
    UIView *tapView = [gestureRecognizer.view hitTest:tapPoint withEvent:nil];
    if (LyricsEnabled && !SwipeEnabled && [tapView isKindOfClass:[UIButton class]])
        return NO;
    else
        return %orig(gestureRecognizer);
}

%end

%ctor {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	%init;
    CFNotificationCenterAddObserver(CFNotificationCenterGetDarwinNotifyCenter(), NULL, PreferencesChangedCallback, CFSTR(PreferencesChangedNotification), NULL, CFNotificationSuspensionBehaviorCoalesce);
    LoadPreferences();
	[pool drain];
}