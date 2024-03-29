/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "UIGestureRecognizerDelegate.h"
#import "Music~ipad-Structs.h"
#import "MusicTableViewController.h"

@class UITapGestureRecognizer, NSArray, NSMutableArray, UIView;

__attribute__((visibility("hidden")))
@interface MusicAlbumFlipViewController : MusicTableViewController <UIGestureRecognizerDelegate> {
	UIView* _albumArtworkView;
	NSArray* _albums;
	NSMutableArray* _sectionAlbumImageViews;
	NSMutableArray* _sectionFooterViews;
	UITapGestureRecognizer* _tapGestureRecognizer;
}
+(id)_imageCache;
-(void)_setupAddAllEntitiesButton;
-(void)_updateDownloadAllButton;
-(void)_updateAlbumsFromDataSource;
-(void)_layoutHeaderViewsForVisibleSections;
-(id)_albumImageViewForSection:(unsigned)section;
-(void)_viewWasTapped:(id)tapped;
-(void)_downloadAllAction:(id)action;
-(id)tableView:(id)view viewForFooterInSection:(int)section;
-(float)tableView:(id)view heightForFooterInSection:(int)section;
-(int)numberOfSectionsInTableView:(id)tableView;
-(int)tableView:(id)view numberOfRowsInSection:(int)section;
-(void)scrollViewDidScroll:(id)scrollView;
-(BOOL)gestureRecognizer:(id)recognizer shouldReceiveTouch:(id)touch;
-(void)dataSourceDidInvalidate;
-(void)viewWillAppear:(BOOL)view;
-(void)viewDidUnload;
-(void)viewDidLoad;
-(void)loadView;
-(void)dealloc;
@end

