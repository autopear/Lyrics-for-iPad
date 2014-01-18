/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "Music~ipad-Structs.h"

@class NSString, MPDownloadProgressIndicator, UIImageView, UIButton, MPMediaDownloadObserver, UIColor;
@protocol NSObject;

__attribute__((visibility("hidden")))
@interface MusicSongTableViewCell : XXUnknownSuperclass {
	UIButton* _downloadButton;
	MPDownloadProgressIndicator* _downloadProgressIndicator;
	UIImageView* _nowPlayingImageView;
	NSString* _album;
	NSString* _artist;
	BOOL _directDrawingDisabled;
	id<NSObject> _downloadableAsset;
	NSString* _downloadIdentifier;
	MPMediaDownloadObserver* _downloadObserver;
	int _downloadStatus;
	NSString* _duration;
	UIEdgeInsets _edgeInsets;
	int _interfaceOrientation;
	BOOL _isTemporaryCloudDownload;
	long long _itemPersistentID;
	BOOL _playing;
	BOOL _preparingToDownload;
	NSString* _title;
	UIColor* _titleColor;
}
@property(assign, nonatomic) BOOL directDrawingDisabled;	// @synthesize=_directDrawingDisabled
@property(assign, nonatomic) UIEdgeInsets edgeInsets;	// @synthesize=_edgeInsets
@property(assign, nonatomic, getter=isPreparingToDownload) BOOL preparingToDownload;	// @synthesize=_preparingToDownload
@property(retain, nonatomic) id<NSObject> downloadableAsset;	// @synthesize=_downloadableAsset
@property(retain, nonatomic) UIColor* titleColor;	// @synthesize=_titleColor
@property(copy, nonatomic) NSString* title;	// @synthesize=_title
@property(assign, nonatomic, getter=isPlaying) BOOL playing;	// @synthesize=_playing
@property(copy, nonatomic) NSString* duration;	// @synthesize=_duration
@property(copy, nonatomic) NSString* artist;	// @synthesize=_artist
@property(copy, nonatomic) NSString* album;	// @synthesize=_album
@property(assign, nonatomic) int interfaceOrientation;	// @synthesize=_interfaceOrientation
+(void)initialize;
// declared property getter: -(id)titleColor;
// declared property getter: -(id)title;
// declared property getter: -(BOOL)isPreparingToDownload;
// declared property getter: -(BOOL)isPlaying;
// declared property getter: -(int)interfaceOrientation;
// declared property setter: -(void)setEdgeInsets:(UIEdgeInsets)insets;
// declared property getter: -(UIEdgeInsets)edgeInsets;
// declared property getter: -(id)duration;
// declared property getter: -(id)downloadableAsset;
// declared property getter: -(BOOL)directDrawingDisabled;
// declared property getter: -(id)artist;
// declared property getter: -(id)album;
-(id)textForLabelAtIndex:(unsigned)index;
-(int)textAlignmentForLabelAtIndex:(unsigned)index;
-(id)shadowColorForLabelAtIndex:(unsigned)index;
-(unsigned)numberOfLabels;
-(CGRect)frameForLabelAtIndex:(unsigned)index;
-(CGRect)frameForLabelAtIndex:(unsigned)index inView:(id)view;
-(id)fontForLabelAtIndex:(unsigned)index;
-(void)drawForegroundInRect:(CGRect)rect selected:(BOOL)selected;
-(void)drawBackgroundInRect:(CGRect)rect;
-(id)colorForLabelAtIndex:(unsigned)index selected:(BOOL)selected;
-(id)bottomSeparatorFeatheredBottomColor;
-(id)bottomSeparatorFeatheredTopColor;
-(id)topSeparatorFeatheredBottomColor;
-(id)topSeparatorFeatheredTopColor;
-(id)bottomSeparatorColor;
-(id)topSeparatorColor;
-(CGRect)_nowPlayingImageViewFrame;
-(BOOL)_isDownloading;
-(float)_downloadViewFrameStartingPoint;
-(CGRect)_downloadProgressIndicatorFrame;
-(CGRect)_downloadButtonFrame;
-(void)_downloadButtonPressed:(id)pressed;
-(void)_cancelDownloadButtonPressed:(id)pressed;
// declared property setter: -(void)setTitleColor:(id)color;
// declared property setter: -(void)setTitle:(id)title;
// declared property setter: -(void)setPreparingToDownload:(BOOL)download;
// declared property setter: -(void)setPlaying:(BOOL)playing;
// declared property setter: -(void)setInterfaceOrientation:(int)orientation;
// declared property setter: -(void)setDuration:(id)duration;
-(void)setDownloadIdentifier:(id)identifier downloadStatus:(int)status isTemporaryCloudDownload:(BOOL)download itemPersistentID:(long long)anId;
// declared property setter: -(void)setDownloadableAsset:(id)asset;
// declared property setter: -(void)setDirectDrawingDisabled:(BOOL)disabled;
// declared property setter: -(void)setArtist:(id)artist;
// declared property setter: -(void)setAlbum:(id)album;
-(id)backgroundColor;
-(void)setEditing:(BOOL)editing animated:(BOOL)animated;
-(void)prepareForReuse;
-(void)_drawContentInRect:(CGRect)rect selected:(BOOL)selected;
-(id)_contentString;
-(void)layoutSubviews;
-(void)drawRect:(CGRect)rect;
-(void)dealloc;
@end
