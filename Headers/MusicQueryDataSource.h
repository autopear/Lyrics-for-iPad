/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Music~ipad-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class MPMediaQuery, NSArray, MPMediaQuerySectionInfo, NSString;

__attribute__((visibility("hidden")))
@interface MusicQueryDataSource : XXUnknownSuperclass {
	NSArray* _entities;
	int _entityType;
	BOOL _invalidateWhenEnteringForeground;
	MPMediaQuery* _query;
	MPMediaQuerySectionInfo* _sectionInfo;
}
@property(readonly, assign, nonatomic) BOOL showsEntityCountFooter;
@property(readonly, assign, nonatomic) NSString* titleForGlobalHeader;
@property(readonly, assign, nonatomic) BOOL allowsDownloadingAllEntities;
@property(readonly, assign, nonatomic) NSArray* localizedSectionIndexTitles;
@property(readonly, assign, nonatomic) unsigned numberOfSections;
@property(readonly, assign, nonatomic) BOOL showsIndexBar;
@property(readonly, assign, nonatomic) unsigned count;
@property(readonly, assign, nonatomic) BOOL isEmpty;
@property(readonly, assign, nonatomic) int entityType;	// @synthesize=_entityType
@property(readonly, assign, nonatomic) MPMediaQuery* query;	// @synthesize=_query
@property(readonly, retain) NSArray* entities;	// converted property
// declared property getter: -(id)query;
// declared property getter: -(int)entityType;
-(id)_sectionInfo;
-(void)_postInvalidationNotification;
-(void)_mediaLibraryDynamicPropertiesDidChangeNotification:(id)_mediaLibraryDynamicProperties;
-(void)_mediaLibraryDisplayValuesDidChangeNotification:(id)_mediaLibraryDisplayValues;
-(void)_mediaLibraryDidChangeNotification:(id)_mediaLibrary;
-(void)_isCloudEnabledDidChangeNotification:(id)_isCloudEnabled;
-(void)_defaultsDidChangeNotification;
-(void)_defaultMediaLibraryDidChangeNotification:(id)_defaultMediaLibrary;
-(void)_applicationWillEnterForegroundNotification:(id)_application;
// converted property getter: -(id)entities;
// declared property getter: -(id)titleForGlobalHeader;
// declared property getter: -(BOOL)showsEntityCountFooter;
// declared property getter: -(BOOL)allowsDownloadingAllEntities;
-(BOOL)entityIsNowPlayingAtIndex:(unsigned)index;
-(NSRange)rangeOfSectionAtIndex:(unsigned)index;
-(unsigned)indexOfSectionForSectionTitleAtIndex:(unsigned)index;
-(id)localizedSectionTitleAtIndex:(unsigned)index;
// declared property getter: -(id)localizedSectionIndexTitles;
// declared property getter: -(unsigned)numberOfSections;
// declared property getter: -(BOOL)showsIndexBar;
-(void)deleteEntityAtIndex:(unsigned)index;
-(BOOL)canDeleteEntityAtIndex:(unsigned)index;
-(id)playbackContextForIndex:(unsigned)index;
-(void)invalidate;
// declared property getter: -(BOOL)isEmpty;
-(id)entityAtIndex:(unsigned)index;
-(BOOL)canSelectEntityAtIndex:(unsigned)index;
// declared property getter: -(unsigned)count;
-(void)dealloc;
-(id)initWithQuery:(id)query entityType:(int)type;
@end

