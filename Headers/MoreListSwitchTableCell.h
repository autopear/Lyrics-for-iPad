/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSString, UILabel, UISwitch;

__attribute__((visibility("hidden")))
@interface MoreListSwitchTableCell : XXUnknownSuperclass {
	UILabel* _moreTitleLabel;
	UISwitch* _switch;
}
@property(copy, nonatomic) NSString* moreTitle;
// declared property setter: -(void)setMoreTitle:(id)title;
// declared property getter: -(id)moreTitle;
-(void)_switchValueDidChangeAction:(id)_switchValue;
-(void)layoutSubviews;
-(id)initWithStyle:(int)style reuseIdentifier:(id)identifier;
@end
