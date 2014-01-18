#import <Preferences/Preferences.h>
#import <CaptainHook/CaptainHook.h>
#import <objc/runtime.h>

#define PREFS_PATH  [NSString stringWithFormat:@"%@/Library/Preferences/com.autopear.lyricsforipad.plist", NSHomeDirectory()]

#define settingsChanged @"com.autopear.lyricsforipad.preferenceschanged"

static NSBundle *localizedBundle;

@interface LyricsforiPadPreferencesListController: PSListController {
}
@end

@implementation LyricsforiPadPreferencesListController

- (id)specifiers {
	if(_specifiers == nil) {
		_specifiers = [[self loadSpecifiersFromPlistName:@"LyricsforiPad" target:self] retain];
	}

	return _specifiers;
}

- (id)init {
	if ((self = [super init])) {
        localizedBundle = [[NSBundle alloc] initWithPath:@"/Library/PreferenceBundles/LyricsforiPadPreferences.bundle/"];
	}
	return self;
}

- (void)dealloc {
    [localizedBundle release];
    localizedBundle = nil;
	[super dealloc];
}

-(void)resetPreferences:(PSSpecifier*)specifier {
    NSDictionary *defaultPrefs = [NSDictionary dictionaryWithObjectsAndKeys:
                                  [NSNumber numberWithBool:YES], @"lyricsEnabled",
                                  [NSNumber numberWithBool:NO], @"lyricsSwipeEnabled",
                                  @"Helvetica-Bold", @"lyricsFontName",
                                  [NSNumber numberWithInteger:18], @"lyricsTextSize",
                                  [NSNumber numberWithInteger:3], @"lyricsTextColor",
                                  [NSNumber numberWithInteger:1], @"lyricsTextAlignment",
                                  [NSNumber numberWithBool:NO], @"lyricsEncodingEnabled",
                                  [NSNumber numberWithFloat:60.0f], @"lyricsBackgroundTransparency",
                                  [NSNumber numberWithInteger:0], @"lyricsBackgroundColor",
                                  [NSNumber numberWithInteger:6], @"lyricsShowAnimation",
                                  [NSNumber numberWithInteger:7], @"lyricsDismissAnimation",
                                  nil];

    NSData *data = [NSPropertyListSerialization dataFromPropertyList:defaultPrefs format:NSPropertyListBinaryFormat_v1_0 errorDescription:NULL];

    if (!data)
        return;

    if (![data writeToFile:PREFS_PATH atomically:YES])
        return;

    CFNotificationCenterRef r = CFNotificationCenterGetDarwinNotifyCenter();
    CFNotificationCenterPostNotification(r, (CFStringRef)settingsChanged, NULL, (CFDictionaryRef)defaultPrefs, true);

    system("killall Preferences");
}

@end

@interface LyricsforiPadMoreInfoListController: PSListController {
}
@end

@implementation LyricsforiPadMoreInfoListController

- (id)init {
	if ((self = [super init])) {
	}
	
	return self;
}

- (void)dealloc {
	[super dealloc];
}

- (id)specifiers {
	if(_specifiers == nil) {
		_specifiers = [[self loadSpecifiersFromPlistName:@"MoreInfo" target:self] retain];
    }

    [self setTitle:[localizedBundle localizedStringForKey:@"More Information" value:@"More Information" table:@"LyricsforiPad"]];

    for (PSSpecifier *spec in _specifiers) {
        if ([spec propertyForKey:@"footerText"]) {
            NSString *originalText = [spec propertyForKey:@"footerText"];

            [spec setProperty:[localizedBundle localizedStringForKey:originalText value:originalText table:@"LyricsforiPad"] forKey:@"footerText"];
        }

        if (spec.name) {
            NSString *originalText = spec.name;
            spec.name = [localizedBundle localizedStringForKey:originalText value:originalText table:@"LyricsforiPad"];
        }
    }
	return _specifiers;
}

-(void)openActionSlider:(PSSpecifier*)specifier {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"cydia://package/org.thebigboss.actionslider"]];
}

-(void)openWeeCloseApps:(PSSpecifier*)specifier {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"cydia://package/com.autopear.weecloseapps"]];
}

-(void)openIPAInstaller:(PSSpecifier*)specifier {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"cydia://package/com.autopear.installipa"]];
}

-(void)openLunarCalendar:(PSSpecifier*)specifier {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"cydia://package/com.autopear.lunarcalendar"]];
}

-(void)openRemoveBadges:(PSSpecifier*)specifier {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"cydia://package/com.autopear.removebadges"]];
}

-(void)openQuickShare:(PSSpecifier*)specifier {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"cydia://package/org.thebigboss.quickshare"]];
}
@end

@interface LyricsforiPadFontListController: PSViewController <UITableViewDelegate, UITableViewDataSource> {
	UITableView *_tableView;
	NSMutableArray *_fontList;
	NSInteger selectedRow;
}
@property (nonatomic, retain) NSMutableArray *fontList;
- (id)initForContentSize:(CGSize)size;
- (id)view;
- (void)refreshList;
@end

@implementation LyricsforiPadFontListController
@synthesize fontList = _fontList;
- (id)initForContentSize:(CGSize)size {
	if ((self = [super initForContentSize:size])) {
		_tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, size.width, size.height) style:UITableViewStyleGrouped];
		[_tableView setDataSource:self];
		[_tableView setDelegate:self];
		[_tableView setEditing:NO];
		if ([self respondsToSelector:@selector(setView:)])
			[self performSelectorOnMainThread:@selector(setView:) withObject:_tableView waitUntilDone:YES];

        if (![[NSFileManager defaultManager] fileExistsAtPath:PREFS_PATH isDirectory:NO]) {
            NSMutableDictionary *defaultPrefs =  [NSMutableDictionary dictionaryWithObjectsAndKeys:@"Helvetica", @"lyricsFontName", nil];
            NSData *data = [NSPropertyListSerialization dataFromPropertyList:defaultPrefs format:NSPropertyListBinaryFormat_v1_0 errorDescription:NULL];
            [defaultPrefs release];
            if (!data)
                return nil;
            if (![data writeToFile:PREFS_PATH atomically:YES])
                return nil;
        }

		[self refreshList];
	}
	return self;
}

- (void)refreshList {
	self.fontList = [NSMutableArray array];

    for (NSString *familyName in [UIFont familyNames]) {
        for (NSString *fontName in [UIFont fontNamesForFamilyName:familyName]) {
            [self.fontList addObject:fontName];
        }
    }

    [self.fontList sortUsingSelector:@selector(localizedCaseInsensitiveCompare:)];

    NSMutableDictionary *_settings = [NSMutableDictionary dictionaryWithContentsOfFile:PREFS_PATH];

	selectedRow = [self.fontList indexOfObject:[_settings objectForKey:@"lyricsFontName"]];

	if (selectedRow == NSNotFound)
		selectedRow = [self.fontList indexOfObject:@"Helvetica"];

    if (selectedRow == NSNotFound)
        selectedRow = 0;
}

- (void)viewWillAppear:(BOOL)animated {
	[self refreshList];
}

- (void)dealloc {
	self.fontList = nil;
	[super dealloc];
}

- (id)view {
	return _tableView;
}

- (int) numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSString *) title {
    return [localizedBundle localizedStringForKey:@"Lyrics Font" value:@"Lyrics Font" table:@"LyricsforiPad"];
}

- (id) tableView:(UITableView *)tableView titleForHeaderInSection:(int)section {
    return nil;
}

- (int) tableView:(UITableView *)tableView numberOfRowsInSection:(int)section {
	return _fontList.count;
}

- (id) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell *cell = (UITableViewCell*)[tableView dequeueReusableCellWithIdentifier:@"FontCell"];
    if (!cell)
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"FontCell"] autorelease];

	cell.textLabel.text = [self.fontList objectAtIndex:indexPath.row];
    cell.textLabel.font = [UIFont fontWithName:[self.fontList objectAtIndex:indexPath.row] size:[UIFont labelFontSize]];

	if (indexPath.row == (NSInteger)selectedRow)
		cell.accessoryType = UITableViewCellAccessoryCheckmark;
    else
        cell.accessoryType = UITableViewCellAccessoryNone;

    return cell;
}

- (void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	// deselect old one
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
	UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];

	// check it off
	cell.accessoryType = UITableViewCellAccessoryCheckmark;
	// uncheck prev
	UITableViewCell *old = [tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:selectedRow inSection:0]];
	if (old != cell)
		old.accessoryType = UITableViewCellAccessoryNone;

    if (selectedRow != indexPath.row) {
        NSMutableDictionary *_settings = [NSMutableDictionary dictionaryWithContentsOfFile:PREFS_PATH];

        [_settings setObject:[self.fontList objectAtIndex:indexPath.row] forKey:@"lyricsFontName"];

        NSData *data = [NSPropertyListSerialization dataFromPropertyList:_settings format:NSPropertyListBinaryFormat_v1_0 errorDescription:NULL];

        if (!data)
            return;
        if (![data writeToFile:PREFS_PATH atomically:YES])
            return;

        CFNotificationCenterRef r = CFNotificationCenterGetDarwinNotifyCenter();
        CFNotificationCenterPostNotification(r, (CFStringRef)settingsChanged, NULL, (CFDictionaryRef)_settings, true);

        // make the title changes
        LyricsforiPadPreferencesListController *ctrl = (LyricsforiPadPreferencesListController*)self.parentController;

        UITableView *table = (UITableView *)ctrl.table;

        NSString *fontTitle = [localizedBundle localizedStringForKey:@"Lyrics Font" value:@"Lyrics Font" table:@"LyricsforiPad"];

        for (unsigned int i = 0; i < [table visibleCells].count; i++) {
            UITableViewCell *cell =  (UITableViewCell *)[table.visibleCells objectAtIndex:i];
            //Should use isEqualToString here, and it is not a good idea to use title strings compare to determine the cell, use '-(id)cachedCellForSpecifierID' method instead
            if (cell.textLabel.text == fontTitle) {
                cell.detailTextLabel.text = [self.fontList objectAtIndex:indexPath.row];
                break;
            }
        }
    }

	selectedRow = indexPath.row;
}
@end

#define WBSAddMethod(_class, _sel, _imp, _type) \
if (![[_class class] instancesRespondToSelector:@selector(_sel)]) \
class_addMethod([_class class], @selector(_sel), (IMP)_imp, _type)

void $PSViewController$hideNavigationBarButtons(PSRootController *self, SEL _cmd) {
}

id $PSViewController$initForContentSize$(PSRootController *self, SEL _cmd, CGRect contentSize) {
    return [self init];
}

static __attribute__((constructor)) void __wbsInit() {
    WBSAddMethod(PSViewController, hideNavigationBarButtons, $PSViewController$hideNavigationBarButtons, "v@:");
    WBSAddMethod(PSViewController, initForContentSize:, $PSViewController$initForContentSize$, "@@:{ff}");
}