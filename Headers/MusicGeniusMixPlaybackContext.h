/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "MusicQueryPlaybackContext.h"
#import "MusicGeniusMixQueueFeederDataSource.h"

@class NSMutableArray, MPGeniusMix, MPMediaItem;

__attribute__((visibility("hidden")))
@interface MusicGeniusMixPlaybackContext : MusicQueryPlaybackContext <MusicGeniusMixQueueFeederDataSource> {
	NSMutableArray* _playlistQueries;
	MPMediaItem* _requiredInitialMediaItem;
	MPGeniusMix* _mix;
	BOOL _finite;
}
@property(retain, nonatomic) MPMediaItem* requiredInitialMediaItem;	// @synthesize=_requiredInitialMediaItem
@property(readonly, assign, nonatomic) MPGeniusMix* mix;	// @synthesize=_mix
+(Class)queueFeederClass;
// declared property setter: -(void)setRequiredInitialMediaItem:(id)item;
// declared property getter: -(id)requiredInitialMediaItem;
// declared property getter: -(id)mix;
-(id)_generateNewPlaylistQuery:(id*)query index:(unsigned)index;
-(id)_queryForMediaItemAtIndex:(unsigned)index;
-(unsigned)geniusMixQueueFeeder:(id)feeder indexOfMediaItem:(id)mediaItem;
-(id)geniusMixQueueFeeder:(id)feeder queryForMediaItemAtIndex:(unsigned)index;
-(id)geniusMixQueueFeeder:(id)feeder mediaItemAtIndex:(unsigned)index;
-(unsigned)geniusMixQueueFeederMediaItemCount:(id)count;
-(id)query;
-(void)dealloc;
-(id)initWithGeniusMix:(id)geniusMix requiredInitialMediaItem:(id)item error:(id*)error;
@end

