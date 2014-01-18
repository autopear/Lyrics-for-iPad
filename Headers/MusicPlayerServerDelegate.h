/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "MPMusicPlayerControllerServerDelegate.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class MPAVController, MusicNowPlayingObserver, MusicAVPlayer, MPMediaItem;

__attribute__((visibility("hidden")))
@interface MusicPlayerServerDelegate : XXUnknownSuperclass <MPMusicPlayerControllerServerDelegate> {
	MusicAVPlayer* _applicationPlayer;
	MPMediaItem* _firstItem;
	MusicNowPlayingObserver* _nowPlayingObserver;
	int _playbackShuffleMode;
	id _repeatChangeHandler;
	MPAVController* _repeatChangeHandlerPlayer;
	int _repeatMode;
	id _shuffleChangeHandler;
	MPAVController* _shuffleChangeHandlerPlayer;
	int _shuffleMode;
}
-(void)_appDefaultsChanged;
-(void)musicPlayerServer:(id)server prepareQueueWithGeniusMixPlaylist:(id)geniusMixPlaylist;
-(void)musicPlayerServer:(id)server prepareQueueWithQuery:(id)query;
-(void)musicPlayerServer:(id)server setShuffleMode:(int)mode;
-(void)musicPlayerServer:(id)server setFirstItem:(id)item;
-(id)currentMediaQueryForMusicPlayerServer:(id)musicPlayerServer;
-(BOOL)isNowPlayingItemFromGeniusMixForMusicPlayerServer:(id)musicPlayerServer;
-(unsigned)unshuffledIndexOfNowPlayingItemForMusicPlayerServer:(id)musicPlayerServer;
-(unsigned)indexOfNowPlayingItemForMusicPlayerServer:(id)musicPlayerServer;
-(id)nowPlayingItemForMusicPlayerServer:(id)musicPlayerServer;
-(void)musicPlayerServer:(id)server setNowPlayingItem:(id)item;
-(int)playbackSpeedForMusicPlayerServer:(id)musicPlayerServer;
-(void)musicPlayerServer:(id)server setPlaybackSpeed:(int)speed;
-(id)playerForMusicPlayerServer:(id)musicPlayerServer usingApplicationSpecificQueue:(BOOL)queue;
-(void)musicPlayerServer:(id)server registerForShuffleModeChangesWithChangeHandler:(id)changeHandler;
-(void)musicPlayerServer:(id)server registerForRepeatModeChangesWithChangeHandler:(id)changeHandler;
-(void)dealloc;
-(id)init;
@end

