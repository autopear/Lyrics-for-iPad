/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Music~ipad-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSArray, NSString, MusicNavigationBackButton, UILabel, MusicNavigationButton;

__attribute__((visibility("hidden")))
@interface MusicPlaylistSongsHeaderView : XXUnknownSuperclass {
	MusicNavigationButton* _addSongsButton;
	BOOL _allowsEditing;
	BOOL _allowsAddingSongs;
	BOOL _allowsRefresh;
	BOOL _allowsSave;
	MusicNavigationBackButton* _backButton;
	MusicNavigationButton* _editDoneButton;
	BOOL _editing;
	MusicNavigationButton* _refreshButton;
	NSArray* _rightButtons;
	MusicNavigationButton* _saveButton;
	UILabel* _songCountAndDurationLabel;
	UILabel* _titleLabel;
}
@property(assign, nonatomic, getter=isEditing) BOOL editing;	// @synthesize=_editing
@property(assign, nonatomic) BOOL allowsSave;	// @synthesize=_allowsSave
@property(assign, nonatomic) BOOL allowsRefresh;	// @synthesize=_allowsRefresh
@property(assign, nonatomic) BOOL allowsAddingSongs;	// @synthesize=_allowsAddingSongs
@property(assign, nonatomic) BOOL allowsEditing;	// @synthesize=_allowsEditing
@property(copy, nonatomic) NSString* title;
@property(copy, nonatomic) NSString* songCountAndDuration;
@property(retain, nonatomic) NSArray* rightButtons;	// @synthesize=_rightButtons
@property(copy, nonatomic) NSString* backButtonTitle;
// declared property getter: -(id)rightButtons;
// declared property getter: -(BOOL)isEditing;
// declared property getter: -(BOOL)allowsSave;
// declared property getter: -(BOOL)allowsRefresh;
// declared property getter: -(BOOL)allowsEditing;
// declared property getter: -(BOOL)allowsAddingSongs;
// declared property setter: -(void)setTitle:(id)title;
// declared property getter: -(id)title;
// declared property setter: -(void)setSongCountAndDuration:(id)duration;
// declared property getter: -(id)songCountAndDuration;
// declared property setter: -(void)setRightButtons:(id)buttons;
-(void)setEditing:(BOOL)editing animated:(BOOL)animated;
// declared property setter: -(void)setEditing:(BOOL)editing;
-(void)setBackButtonTarget:(id)target action:(SEL)action forControlEvents:(unsigned)controlEvents;
// declared property setter: -(void)setBackButtonTitle:(id)title;
// declared property getter: -(id)backButtonTitle;
// declared property setter: -(void)setAllowsSave:(BOOL)save;
// declared property setter: -(void)setAllowsRefresh:(BOOL)refresh;
// declared property setter: -(void)setAllowsAddingSongs:(BOOL)songs;
// declared property setter: -(void)setAllowsEditing:(BOOL)editing;
-(void)layoutSubviews;
-(void)drawRect:(CGRect)rect;
-(void)dealloc;
-(id)initWithFrame:(CGRect)frame;
@end

