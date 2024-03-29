/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "MusicPickerOverlay.h"

@class MPMediaPlaylist, NSArray;

__attribute__((visibility("hidden")))
@interface MusicPlaylistEditingPickerOverlay : MusicPickerOverlay {
	NSArray* _pickedEntities;
	MPMediaPlaylist* _playlist;
}
@property(readonly, assign, nonatomic) NSArray* pickedEntities;	// @synthesize=_pickedEntities
// declared property getter: -(id)pickedEntities;
-(void)viewController:(id)controller didPickAllEntitiesFromDataSource:(id)dataSource;
-(void)viewController:(id)controller didPickEntity:(id)entity;
-(id)title;
-(BOOL)allowsMultipleSelections;
-(BOOL)shouldDisplayEntityAsDisabled:(id)disabled;
-(id)rightButtons;
-(id)addAllEntitiesButton;
-(id)dismissButton;
-(id)newAccessoryView;
-(void)loadViewController;
-(void)finish;
-(void)dealloc;
-(id)initWithPlaylist:(id)playlist;
-(id)init;
@end

