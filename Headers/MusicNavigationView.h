/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Music~ipad-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class MusicSearchField, UIImageView, UIButton, MusicNavigationBackgroundView, MusicSegmentedControl;

__attribute__((visibility("hidden")))
@interface MusicNavigationView : XXUnknownSuperclass {
	MusicNavigationBackgroundView* _backgroundView;
	int _interfaceOrientation;
	int _layoutStyle;
	UIButton* _leftButton;
	UIButton* _rightButton;
	UIImageView* _shadowView;
	MusicSearchField* _searchField;
	MusicSegmentedControl* _segmentedControl;
	int _style;
}
@property(assign, nonatomic) int layoutStyle;	// @synthesize=_layoutStyle
@property(assign, nonatomic) int style;	// @synthesize=_style
@property(retain, nonatomic) MusicSegmentedControl* segmentedControl;	// @synthesize=_segmentedControl
@property(retain, nonatomic) MusicSearchField* searchField;	// @synthesize=_searchField
@property(retain, nonatomic) UIButton* rightButton;	// @synthesize=_rightButton
@property(retain, nonatomic) UIButton* leftButton;	// @synthesize=_leftButton
@property(assign, nonatomic) int interfaceOrientation;	// @synthesize=_interfaceOrientation
+(float)_defaultHeight;
// declared property getter: -(int)style;
// declared property getter: -(id)segmentedControl;
// declared property setter: -(void)setSearchField:(id)field;
// declared property getter: -(id)searchField;
// declared property getter: -(id)rightButton;
// declared property getter: -(id)leftButton;
// declared property getter: -(int)layoutStyle;
// declared property getter: -(int)interfaceOrientation;
-(void)_initSubviews;
// declared property setter: -(void)setStyle:(int)style;
// declared property setter: -(void)setSegmentedControl:(id)control;
-(void)setRightButton:(id)button animated:(BOOL)animated;
// declared property setter: -(void)setRightButton:(id)button;
-(void)setLeftButton:(id)button animated:(BOOL)animated;
// declared property setter: -(void)setLeftButton:(id)button;
// declared property setter: -(void)setLayoutStyle:(int)style;
// declared property setter: -(void)setInterfaceOrientation:(int)orientation;
-(void)_layoutSubviewsInLandscape;
-(void)_layoutSubviewsInPortrait;
-(void)_layoutInvariantSubviews;
-(void)layoutSubviews;
-(void)dealloc;
-(id)initWithFrame:(CGRect)frame;
-(id)init;
@end

