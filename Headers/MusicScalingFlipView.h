/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Music~ipad-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class UIView, UITapGestureRecognizer;
@protocol MusicScalingFlipViewDelegate;

__attribute__((visibility("hidden")))
@interface MusicScalingFlipView : XXUnknownSuperclass {
	UIView* _backView;
	id<MusicScalingFlipViewDelegate> _delegate;
	int _direction;
	double _duration;
	CGRect _fromFrame;
	UIView* _frontView;
	BOOL _isFlipped;
	UITapGestureRecognizer* _tapGestureRecognizer;
	CGRect _toFrame;
}
@property(assign, nonatomic) double duration;	// @synthesize=_duration
@property(assign, nonatomic) int direction;	// @synthesize=_direction
@property(retain, nonatomic) UIView* backView;	// @synthesize=_backView
@property(retain, nonatomic) UIView* frontView;	// @synthesize=_frontView
@property(assign, nonatomic) id<MusicScalingFlipViewDelegate> delegate;	// @synthesize=_delegate
// declared property getter: -(id)frontView;
// declared property setter: -(void)setDuration:(double)duration;
// declared property getter: -(double)duration;
// declared property setter: -(void)setDirection:(int)direction;
// declared property getter: -(int)direction;
// declared property setter: -(void)setDelegate:(id)delegate;
// declared property getter: -(id)delegate;
// declared property getter: -(id)backView;
-(id)_transformAnimationWithStart:(CATransform3D)start middle:(CATransform3D)middle end:(CATransform3D)end;
-(void)_performFlipReversed:(BOOL)reversed animated:(BOOL)animated;
-(id)_inputColorAnimation;
-(id)_frontLayerAnimationReversed:(BOOL)reversed;
-(id)_fixedAnimationForAnimation:(id)animation duration:(double)duration;
-(id)_backLayerAnimationReversed:(BOOL)reversed;
-(void)_viewWasTapped:(id)tapped;
-(void)animationDidStop:(id)animation finished:(BOOL)finished;
-(void)performHideForKeyboardAnimated:(BOOL)keyboardAnimated;
-(void)performFlipBackAnimated:(BOOL)animated;
-(void)performFlipAnimated:(BOOL)animated;
// declared property setter: -(void)setFrontView:(id)view;
// declared property setter: -(void)setBackView:(id)view;
-(void)dealloc;
-(id)initWithFrame:(CGRect)frame;
@end
