/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Music~ipad-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class UIImageView;

__attribute__((visibility("hidden")))
@interface MusicNavigationTabButton : XXUnknownSuperclass {
	UIImageView* _pressedImageView;
	int _type;
}
@property(assign, nonatomic) int type;	// @synthesize=_type
// declared property getter: -(int)type;
// declared property setter: -(void)setType:(int)type;
-(void)setHighlighted:(BOOL)highlighted;
-(id)initWithFrame:(CGRect)frame;
@end
