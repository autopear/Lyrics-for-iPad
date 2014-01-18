/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "MusicGridViewController.h"
#import "Music~ipad-Structs.h"
#import "MusicScalingFlipViewControllerDelegate.h"

@class MusicScalingFlipViewController, MPMediaEntity, MusicStandardGridView;

__attribute__((visibility("hidden")))
@interface MusicAlbumsViewController : MusicGridViewController <MusicScalingFlipViewControllerDelegate> {
	MPMediaEntity* _flippedAlbum;
	MusicStandardGridView* _flippedView;
	MusicScalingFlipViewController* _flipViewController;
}
+(id)flipViewControllerType;
-(id)_frontViewControllerForView:(id)view;
-(id)_backViewControllerForEntity:(id)entity;
-(void)_keyboardWillShowNotification:(id)_keyboard;
-(void)scalingFlipViewControllerDidFlipBack:(id)scalingFlipViewController;
-(void)scalingFlipViewControllerWillFlipBack:(id)scalingFlipViewController;
-(void)gridView:(id)view didSelectViewAtIndexPath:(id)indexPath;
-(BOOL)beginPlaybackForVisibleContent;
-(void)didRotateFromInterfaceOrientation:(int)interfaceOrientation;
-(void)willAnimateRotationToInterfaceOrientation:(int)interfaceOrientation duration:(double)duration;
-(void)dealloc;
-(id)initWithDataSource:(id)dataSource gridConfigurationClass:(Class)aClass;
@end
