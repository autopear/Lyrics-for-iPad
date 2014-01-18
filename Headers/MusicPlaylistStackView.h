/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Music~ipad-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class UIImage, NSArray, MusicPlaylistStackAlbumView;

__attribute__((visibility("hidden")))
@interface MusicPlaylistStackView : XXUnknownSuperclass {
	MusicPlaylistStackAlbumView* _albumViews[3];
	NSArray* _images;
	UIImage* _panImage;
}
@property(retain, nonatomic) UIImage* panImage;	// @synthesize=_panImage
@property(retain, nonatomic) NSArray* images;	// @synthesize=_images
+(void)setPlaceholderImage:(id)image;
// declared property getter: -(id)panImage;
// declared property getter: -(id)images;
-(id)_newAlbumView;
// declared property setter: -(void)setPanImage:(id)image;
// declared property setter: -(void)setImages:(id)images;
-(void)displayPlaceholders;
-(void)layoutSubviews;
-(void)dealloc;
-(id)initWithFrame:(CGRect)frame;
@end

