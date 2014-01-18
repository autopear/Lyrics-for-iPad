/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "UIGestureRecognizerDelegate.h"
#import "Music~ipad-Structs.h"

@class UIImage, NSArray, NSString, UILabel, UIImageView, UIButton, UILongPressGestureRecognizer, MusicPlaylistStackView, UIPanGestureRecognizer;
@protocol MusicPlaylistPanningDataSource;

__attribute__((visibility("hidden")))
@interface MusicPlaylistGridView : XXUnknownSuperclass <UIGestureRecognizerDelegate> {
	void* _context;
	id<MusicPlaylistPanningDataSource> _dataSource;
	BOOL _editing;
	UIButton* _editingButton;
	BOOL _enabled;
	id _eventHandlers[2];
	UIImageView* _iconView;
	UILongPressGestureRecognizer* _longPressGestureRecognizer;
	UILabel* _nameLabel;
	BOOL _nowPlaying;
	UIImageView* _nowPlayingSpeakerView;
	BOOL _panGestureActive;
	UIPanGestureRecognizer* _panGestureRecognizer;
	UILabel* _songCountLabel;
	MusicPlaylistStackView* _stackView;
}
@property(copy, nonatomic) NSString* songCountAndDuration;
@property(assign, nonatomic, getter=isNowPlaying) BOOL nowPlaying;	// @synthesize=_nowPlaying
@property(copy, nonatomic) NSString* name;
@property(copy, nonatomic) NSArray* images;
@property(copy, nonatomic) UIImage* icon;
@property(assign, nonatomic) void* context;	// @synthesize=_context
@property(retain, nonatomic) id<MusicPlaylistPanningDataSource> dataSource;	// @synthesize=_dataSource
@property(assign, nonatomic, getter=isEnabled) BOOL enabled;	// @synthesize=_enabled
@property(assign, nonatomic, getter=isEditing) BOOL editing;	// @synthesize=_editing
// declared property getter: -(BOOL)isNowPlaying;
// declared property getter: -(BOOL)isEnabled;
// declared property getter: -(BOOL)isEditing;
// declared property setter: -(void)setDataSource:(id)source;
// declared property getter: -(id)dataSource;
// declared property setter: -(void)setContext:(void*)context;
// declared property getter: -(void*)context;
// declared property getter: -(id)songCountAndDuration;
// declared property setter: -(void)setSongCountAndDuration:(id)duration;
// declared property setter: -(void)setNowPlaying:(BOOL)playing;
// declared property setter: -(void)setName:(id)name;
// declared property setter: -(void)setImages:(id)images;
// declared property setter: -(void)setIcon:(id)icon;
-(void)setHandlerForEvent:(int)event withHandlerBlock:(id)handlerBlock;
// declared property setter: -(void)setEnabled:(BOOL)enabled;
// declared property setter: -(void)setEditing:(BOOL)editing;
// declared property getter: -(id)name;
// declared property getter: -(id)images;
// declared property getter: -(id)icon;
-(void)displayPlaceholders;
-(void)_viewDidPan:(id)_view;
-(void)_longPressGestureRecognized:(id)recognized;
-(void)_deleteAction:(id)action;
-(BOOL)gestureRecognizer:(id)recognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(id)gestureRecognizer;
-(void)layoutSubviews;
-(void)dealloc;
-(id)initWithFrame:(CGRect)frame;
@end

