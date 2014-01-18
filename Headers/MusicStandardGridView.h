/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "Music~ipad-Structs.h"

@class UIImage, NSString, UIView, UILabel, UIImageView, UIButton, UILongPressGestureRecognizer, MPImageCacheRequest;

__attribute__((visibility("hidden")))
@interface MusicStandardGridView : XXUnknownSuperclass {
	UIImageView* _backgroundImageView;
	UIImageView* _cloudImageView;
	BOOL _editing;
	UIButton* _editingButton;
	id _eventHandlers[2];
	BOOL _hasCloudContent;
	CGSize _imageOffset;
	MPImageCacheRequest* _imageRequest;
	UIImage* _image;
	UIImageView* _imageView;
	CGSize _imageSize;
	UILongPressGestureRecognizer* _longPressGestureRecognizer;
	UILabel* _subtitleLabel;
	UILabel* _titleLabel;
	BOOL _shouldUseSubviews;
	BOOL _originalShouldUseSubviews;
}
@property(readonly, assign, nonatomic) UIView* imageView;	// @synthesize=_imageView
@property(assign, nonatomic) BOOL hasCloudContent;	// @synthesize=_hasCloudContent
@property(copy, nonatomic) NSString* title;
@property(copy, nonatomic) NSString* subtitle;
@property(assign, nonatomic) CGSize imageSize;	// @synthesize=_imageSize
@property(assign, nonatomic) CGSize imageOffset;	// @synthesize=_imageOffset
@property(retain, nonatomic) MPImageCacheRequest* imageRequest;	// @synthesize=_imageRequest
@property(retain, nonatomic) UIImage* image;	// @synthesize=_image
@property(assign, nonatomic, getter=isEditing) BOOL editing;	// @synthesize=_editing
// declared property getter: -(id)imageView;
// declared property getter: -(CGSize)imageSize;
// declared property getter: -(id)imageRequest;
// declared property getter: -(CGSize)imageOffset;
// declared property getter: -(id)image;
// declared property getter: -(BOOL)hasCloudContent;
// declared property getter: -(BOOL)isEditing;
-(void)_setShouldUseSubviews:(BOOL)_set;
-(BOOL)_shouldUseSubviews;
-(void)showWithDuration:(double)duration;
-(void)showForFlipWithDuration:(double)duration;
-(void)hideForFlipWithDuration:(double)duration;
// declared property setter: -(void)setTitle:(id)title;
// declared property getter: -(id)title;
-(void)setHandlerForEvent:(int)event withHandlerBlock:(id)handlerBlock;
// declared property setter: -(void)setSubtitle:(id)subtitle;
// declared property getter: -(id)subtitle;
// declared property setter: -(void)setImageSize:(CGSize)size;
// declared property setter: -(void)setImageRequest:(id)request;
// declared property setter: -(void)setImageOffset:(CGSize)offset;
// declared property setter: -(void)setImage:(id)image;
// declared property setter: -(void)setHasCloudContent:(BOOL)content;
// declared property setter: -(void)setEditing:(BOOL)editing;
-(void)_longPressGestureRecognized:(id)recognized;
-(void)_deleteAction:(id)action;
-(void)drawRect:(CGRect)rect;
-(void)layoutSubviews;
-(void)dealloc;
-(id)initWithGridConfigurationClass:(Class)gridConfigurationClass;
@end

