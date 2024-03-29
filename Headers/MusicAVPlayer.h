/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "MusicAVPlayer.h"

@class MPMediaItem, MPMediaQuery;

__attribute__((visibility("hidden")))
@interface MusicAVPlayer : XXUnknownSuperclass {
	int _extendedModeNotifyToken;
}
@property(readonly, assign, nonatomic) MPMediaQuery* currentMediaQuery;
@property(readonly, assign, nonatomic) MPMediaItem* currentMediaItem;
+(id)sharedAVPlayer;
// declared property getter: -(id)currentMediaQuery;
// declared property getter: -(id)currentMediaItem;
-(void)beginOrTogglePlayback;
-(BOOL)isInExtendedMode;
-(void)_musicPlayer_defaultsDidChangeNotification;
-(void)dealloc;
-(id)init;
@end

@interface MusicAVPlayer (MusicQueryQueueFeederAdditions)
-(void)reloadWithPlaybackContext:(id)playbackContext keepPlayingCurrentItemIfPossible:(BOOL)possible;
@end

