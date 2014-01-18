/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class SUStorePageViewController, MusicStoreSocialURLResolutionOperation, NSString;

__attribute__((visibility("hidden")))
@interface MusicStoreSocialPageViewController : XXUnknownSuperclass {
	NSString* _actionType;
	unsigned long long _itemIdentifier;
	MusicStoreSocialURLResolutionOperation* _resolutionOperation;
	SUStorePageViewController* _storePageViewController;
	NSString* _socialActionType;
}
@property(readonly, assign, nonatomic) NSString* socialActionType;	// @synthesize=_socialActionType
@property(readonly, assign, nonatomic) unsigned long long itemIdentifier;	// @synthesize=_itemIdentifier
// declared property getter: -(id)socialActionType;
// declared property getter: -(unsigned long long)itemIdentifier;
-(void)storePage:(id)page finishedWithSuccess:(BOOL)success;
-(void)viewWillDisappear:(BOOL)view;
-(void)viewWillAppear:(BOOL)view;
-(id)viewControllerFactory;
-(void)loadView;
-(void)dealloc;
-(id)initWithSocialActionType:(id)socialActionType itemIdentifier:(unsigned long long)identifier;
-(id)init;
@end
