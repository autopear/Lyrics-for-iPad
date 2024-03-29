/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class MusicSearchDataSource, MPMediaQuery, MPWeakRef;

__attribute__((visibility("hidden")))
@interface MusicSearchOperation : XXUnknownSuperclass {
	MPWeakRef* _dataSourceRef;
	int _entityType;
	MPMediaQuery* _query;
	double _delay;
	BOOL _didExecuteSearch;
}
@property(assign) BOOL didExecuteSearch;	// @synthesize=_didExecuteSearch
@property(readonly, assign, nonatomic) double delay;	// @synthesize=_delay
@property(readonly, assign, nonatomic) MusicSearchDataSource* dataSource;
// declared property setter: -(void)setDidExecuteSearch:(BOOL)executeSearch;
// declared property getter: -(BOOL)didExecuteSearch;
// declared property getter: -(double)delay;
-(void)main;
-(void)executeSearch;
-(void)cancel;
// declared property getter: -(id)dataSource;
-(void)dealloc;
-(id)description;
-(id)initWithSearchDataSource:(id)searchDataSource delay:(double)delay;
@end

