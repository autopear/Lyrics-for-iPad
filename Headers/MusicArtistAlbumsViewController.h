/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "MusicTableViewController.h"
#import "Music~ipad-Structs.h"
#import "UIGestureRecognizerDelegate.h"

@class UITapGestureRecognizer, UIView, MusicArtistAlbumsHeaderView, NSArray, NSMutableDictionary, MPImageCache, NSMutableArray;

__attribute__((visibility("hidden")))
@interface MusicArtistAlbumsViewController : MusicTableViewController <UIGestureRecognizerDelegate> {
	UIView* _albumArtworkView;
	NSArray* _albums;
	MPImageCache* _imageCache;
	MusicArtistAlbumsHeaderView* _headerView;
	NSMutableArray* _sectionAlbumHeaderViews;
	NSMutableArray* _sectionAlbumImageViews;
	NSMutableDictionary* _departingSectionAlbumImageViewsByCacheKey;
	NSMutableArray* _sectionFooterViews;
	UITapGestureRecognizer* _tapGestureRecognizer;
}
-(void)_updateDownloadAllButton;
-(void)_updateAlbumsFromDataSource;
-(void)_layoutHeaderViewsForVisibleSections;
-(void)_loadArtworkImageForSection:(unsigned)section;
-(id)_albumImageViewForSection:(unsigned)section;
-(void)_viewWasTapped:(id)tapped;
-(void)_downloadAllAction:(id)action;
-(void)_backButtonAction:(id)action;
-(BOOL)gestureRecognizer:(id)recognizer shouldReceiveTouch:(id)touch;
-(id)tableView:(id)view viewForFooterInSection:(int)section;
-(float)tableView:(id)view heightForFooterInSection:(int)section;
-(float)tableView:(id)view heightForHeaderInSection:(int)section;
-(id)tableView:(id)view viewForHeaderInSection:(int)section;
-(int)numberOfSectionsInTableView:(id)tableView;
-(int)tableView:(id)view numberOfRowsInSection:(int)section;
-(void)scrollViewDidScroll:(id)scrollView;
-(void)reloadData;
-(void)viewWillAppear:(BOOL)view;
-(void)viewDidUnload;
-(void)viewDidLoad;
-(void)loadView;
-(void)dealloc;
@end

