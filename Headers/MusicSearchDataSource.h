/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Music~ipad-Structs.h"
#import "MusicQueryDataSource.h"

@class NSArray, NSString, NSMutableArray, NSOperationQueue;

__attribute__((visibility("hidden")))
@interface MusicSearchDataSource : MusicQueryDataSource {
	NSOperationQueue* _operationQueue;
	NSMutableArray* _searchOperations;
	NSArray* _searchResults;
	NSString* _searchString;
}
@property(readonly, assign, nonatomic) NSString* searchString;	// @synthesize=_searchString
// declared property getter: -(id)searchString;
-(id)_searchPropertiesForGroupingType:(int)groupingType;
-(void)_searchDidFinishWithResults:(id)_search;
-(id)filterResultsUsingSearchString:(id)string operationToFollow:(id)follow delay:(double)delay;
-(void)_removeFinishedSearchOperations;
-(void)_addSearchOperation:(id)operation toQueue:(id)queue;
-(id)entities;
-(unsigned)count;
-(void)dealloc;
-(id)initWithDataSource:(id)dataSource;
@end
