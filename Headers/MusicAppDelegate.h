/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "MusicPlaybackViewControllerDelegate.h"
#import "MusicSegmentedViewControllerDelegate.h"
#import "MusicBrowserViewControllerDelegate.h"
#import "AccessorySplashHandler.h"
#import "UIApplicationDelegate.h"
#import "Music~ipad-Structs.h"
#import "MusicAppDelegate.h"

@class NSDate, MusicPlayerServerDelegate, MusicViewController, MusicPlaybackViewController, UIWindow, MusicNowPlayingObserver, MusicSegmentedViewController, MusicBrowserViewController, AccessorySplashViewController;

__attribute__((visibility("hidden")))
@interface MusicAppDelegate : XXUnknownSuperclass <MusicPlaybackViewControllerDelegate, MusicSegmentedViewControllerDelegate, MusicBrowserViewControllerDelegate, AccessorySplashHandler, UIApplicationDelegate> {
	unsigned _backgroundTask;
	NSDate* _lastArchivedPlaybackQueueDate;
	MusicBrowserViewController* _musicBrowserViewController;
	MusicPlayerServerDelegate* _musicPlayerServerDelegate;
	MusicViewController* _musicViewController;
	MusicNowPlayingObserver* _nowPlayingObserver;
	MusicPlaybackViewController* _playbackViewController;
	MusicSegmentedViewController* _segmentedViewController;
	UIWindow* _window;
	AccessorySplashViewController* _accessorySplashController;
	BOOL _wantsSplashScreen;
}
@property(retain, nonatomic) UIWindow* window;
+(id)_archivedPlaybackQueuePath;
+(id)_archivedNavigationPath;
-(id)_storeClientController;
-(BOOL)_restoreRootObjects;
-(void)_restorePlaybackQueue;
-(id)_newSegmentedViewController;
-(id)_newStoreButton;
-(void)_endDiscoveringMediaLibrariesIfNecessary;
-(void)_archivePlaybackQueue;
-(void)_archiveRootObjects;
-(void)_keyboardWillShowNotification:(id)_keyboard;
-(void)_keyboardWillHideNotification:(id)_keyboard;
-(void)_itemDidChangeNotification:(id)_item;
-(void)_availableMediaLibrariesDidChangeNotification:(id)_availableMediaLibraries;
-(void)_storeButtonAction:(id)action;
-(void)_nowPlayingBackButtonAction:(id)action;
-(void)musicBrowserViewControllerRequestsTransitionToNowPlaying:(id)nowPlaying;
-(void)playbackViewController:(id)controller didSelectViewControllerAtIndex:(unsigned)index;
-(void)playbackViewControllerDidSelectMoreViewController:(id)playbackViewController;
-(void)playbackViewControllerDidRequestExit:(id)playbackViewController;
-(void)hideAccessoryController;
-(void)showAccessoryController:(BOOL)controller;
-(BOOL)application:(id)application openURL:(id)url sourceApplication:(id)application3 annotation:(id)annotation;
-(void)applicationWillResignActive:(id)application;
-(void)applicationWillEnterForeground:(id)application;
-(void)applicationDidEnterBackground:(id)application;
-(void)applicationDidBecomeActive:(id)application;
-(BOOL)application:(id)application didFinishLaunchingWithOptions:(id)options;
-(void)dealloc;
@end

@interface MusicAppDelegate (MusicAppTesting)
-(BOOL)application:(id)application runTest:(id)test options:(id)options;
-(void)_startScrollTestWithOptions:(id)options;
-(void)didChangeOrientation:(id)orientation;
-(void)_startScrollTest;
@end

