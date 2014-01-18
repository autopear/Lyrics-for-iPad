/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "MusicPlaybackContext.h"

@class MPMediaQuery, NSArray;

__attribute__((visibility("hidden")))
@interface MusicQueryPlaybackContext : MusicPlaybackContext {
	NSArray* _prefixMediaItems;
	MPMediaQuery* _query;
	unsigned _startIndex;
}
@property(assign, nonatomic) unsigned startIndex;	// @synthesize=_startIndex
@property(copy, nonatomic) NSArray* prefixMediaItems;	// @synthesize=_prefixMediaItems
@property(readonly, assign, nonatomic) MPMediaQuery* query;	// @synthesize=_query
+(Class)queueFeederClass;
// declared property setter: -(void)setStartIndex:(unsigned)index;
// declared property getter: -(unsigned)startIndex;
// declared property getter: -(id)query;
// declared property setter: -(void)setPrefixMediaItems:(id)items;
// declared property getter: -(id)prefixMediaItems;
-(void)dealloc;
-(id)initWithQuery:(id)query;
@end

