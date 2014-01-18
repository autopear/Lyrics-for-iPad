/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Music~ipad-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class UIImage, MusicSearchViewController, MPMediaPredicate, NSString, MusicPickerOverlay, NSURL, MPMediaItem;

@interface XXUnknownSuperclass (MusicAppTesting)
-(id)firstScrollViewDescendant;
-(id)_firstDescendantOfKind:(Class)kind;
@end

@interface XXUnknownSuperclass (MusicAdditions)
-(void)sizeToFitWithMinimumWidth:(float)minimumWidth;
-(void)setFrameHeight:(float)height;
-(void)setFrameWidth:(float)width;
-(void)setFrameSize:(CGSize)size;
-(void)setFrameY:(float)y;
-(void)setFrameX:(float)x;
-(void)setFrameOrigin:(CGPoint)origin;
@end

@interface XXUnknownSuperclass (MusicTableViewControllerAdditions)
@property(assign, nonatomic, getter=isPlaying) BOOL playing;
@property(assign, nonatomic, getter=isExpanded) BOOL expanded;
// declared property setter: -(void)setPlaying:(BOOL)playing;
// declared property getter: -(BOOL)isPlaying;
// declared property setter: -(void)setExpanded:(BOOL)expanded;
// declared property getter: -(BOOL)isExpanded;
@end

@interface XXUnknownSuperclass (MusicApplicationAdditions)
-(void)cancelDownloadOfAsset:(id)asset;
-(void)downloadAsset:(id)asset completionHandler:(id)handler;
@end

@interface XXUnknownSuperclass (MusicAdditions)
@property(readonly, assign, nonatomic) int statusBarStyle;
@property(readonly, assign, nonatomic, getter=isStatusBarHidden) BOOL statusBarHidden;
@property(readonly, assign, nonatomic) NSString* identifier;
+(id)_viewControllerForIdentifier:(id)identifier forSearch:(BOOL)search withQuery:(id)query;
+(id)_sanitizedQueryForQuery:(id)query;
+(id)_queryForIdentifier:(id)identifier;
+(id)viewControllersForIdentifiers:(id)identifiers;
+(id)viewControllerForIdentifier:(id)identifier withQuery:(id)query;
+(id)searchViewControllersForIdentifiers:(id)identifiers;
+(id)searchViewControllerForIdentifier:(id)identifier withQuery:(id)query;
-(BOOL)beginPlaybackForVisibleContent;
// declared property getter: -(int)statusBarStyle;
// declared property getter: -(BOOL)isStatusBarHidden;
// declared property getter: -(id)identifier;
-(void)setIdentifier:(id)identifier;
@end

@interface XXUnknownSuperclass (MusicSegmentedViewControllerAdditions)
@property(readonly, assign, nonatomic) BOOL showInlineInMorePopover;
@property(readonly, assign, nonatomic) BOOL isVisibleInMorePopover;
// declared property getter: -(BOOL)showInlineInMorePopover;
// declared property getter: -(BOOL)isVisibleInMorePopover;
@end

@interface XXUnknownSuperclass (MusicQueryNowPlayingItemAdditions)
@property(readonly, assign, nonatomic) MPMediaItem* mediaItem;
// declared property getter: -(id)mediaItem;
@end

@interface XXUnknownSuperclass (MusicQueryNowPlayingItemAdditions)
@property(readonly, assign, nonatomic) NSURL* protectedContentSupportStorageURL;
// declared property getter: -(id)protectedContentSupportStorageURL;
@end

@interface XXUnknownSuperclass (MusicMoreViewControllerAdditions)
@property(readonly, assign, nonatomic) int accessoryType;
@property(retain, nonatomic, getter=_selectedMoreListImage, setter=_setSelectedMoreListImage:) UIImage* selectedMoreListImage;
@property(retain, nonatomic, getter=_moreListImage, setter=_setMoreListImage:) UIImage* moreListImage;
// declared property getter: -(int)accessoryType;
// declared property getter: -(id)_selectedMoreListImage;
// declared property setter: -(void)_setSelectedMoreListImage:(id)image;
// declared property getter: -(id)_moreListImage;
// declared property setter: -(void)_setMoreListImage:(id)image;
@end

@interface XXUnknownSuperclass (MusicPickerOverlayAdditions)
@property(retain, nonatomic) MusicPickerOverlay* pickerOverlay;
-(void)dismissPickerOverlay;
-(void)presentPickerOverlay:(id)overlay;
// declared property setter: -(void)setPickerOverlay:(id)overlay;
// declared property getter: -(id)pickerOverlay;
@end

@interface XXUnknownSuperclass (MusicSearchViewControllerAdditions)
@property(retain, nonatomic) MusicSearchViewController* searchViewController;
// declared property setter: -(void)setSearchViewController:(id)controller;
// declared property getter: -(id)searchViewController;
@end

@interface XXUnknownSuperclass (MusicGeniusMixQueueFeederAdditions)
@property(retain) id mix;	// converted property
// converted property getter: -(id)mix;
// converted property setter: -(void)setMix:(id)mix;
@end

@interface XXUnknownSuperclass (MusicAdditions)
+(id)activeGeniusPlaylist;
@end

@interface XXUnknownSuperclass (MusicSharedViewControllerAdditions)
-(int)compareMediaLibrary:(id)library;
@end

@interface XXUnknownSuperclass (MusicAdditions)
@property(readonly, assign, nonatomic) NSString* shortcutIdentifier;
@property(readonly, assign, nonatomic) BOOL isPlayImmediatelyURL;
// declared property getter: -(id)shortcutIdentifier;
// declared property getter: -(BOOL)isPlayImmediatelyURL;
@end

@interface XXUnknownSuperclass (MusicPlaylistDataSourceAdditions)
-(int)_sortPlaylistByName:(id)name;
@end

@interface XXUnknownSuperclass (MusicQueryDataSourceAdditions)
@property(readonly, assign, nonatomic) MPMediaPredicate* searchPredicate;
// declared property getter: -(id)searchPredicate;
@end

@interface XXUnknownSuperclass (MusicArtistAlbumsViewController)
-(int)_compareAlbumsByYear:(id)year;
@end

@interface XXUnknownSuperclass (MusicAdditions)
+(id)musicQueryWithFilterPredicates:(id)filterPredicates;
-(BOOL)isEqualToNowPlayingQuery:(id)nowPlayingQuery;
-(id)nowPlayingComparableQuery;
@end

@interface XXUnknownSuperclass (MusicAdditions)
@property(readonly, assign, nonatomic) BOOL hasDeletableContent;
// declared property getter: -(BOOL)hasDeletableContent;
@end

@interface XXUnknownSuperclass (MusicAdditions)
-(BOOL)hasDeletableContent;
@end

