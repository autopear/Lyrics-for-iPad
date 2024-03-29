/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "MusicGridViewController.h"
#import "MusicGridViewDelegate.h"
#import "UIAlertViewDelegate.h"
#import "Music~ipad-Structs.h"
#import "UITextFieldDelegate.h"

@class UITextField, UIAlertView, MusicHeaderView;

__attribute__((visibility("hidden")))
@interface MusicPlaylistsViewController : MusicGridViewController <MusicGridViewDelegate, UIAlertViewDelegate, UITextFieldDelegate> {
	MusicHeaderView* _headerView;
	UITextField* _newPlaylistAlertTextField;
	UIAlertView* _newPlaylistAlertView;
	BOOL _scrollToPurchasedPlaylist;
}
-(void)_updateNewPlaylistButtonVisibility;
-(id)_playlistFolderTitle;
-(void)_accessorySplashViewWillAppearNotification:(id)_accessorySplashView;
-(float)topScrollInset;
-(void)dataSourceDidInvalidate;
-(void)_newPlaylistAction:(id)action;
-(void)_backButtonAction:(id)action;
-(BOOL)textFieldShouldReturn:(id)textField;
-(void)alertView:(id)view didDismissWithButtonIndex:(int)buttonIndex;
-(void)gridView:(id)view didSelectViewAtIndexPath:(id)indexPath;
-(void)viewWillAppear:(BOOL)view;
-(void)viewDidUnload;
-(void)viewDidLoad;
-(void)selectPurchasedPlaylist;
-(void)dealloc;
-(id)initWithDataSource:(id)dataSource gridConfigurationClass:(Class)aClass;
@end

