/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Music~ipad-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSNumber, NSMutableDictionary, MusicStoreSocialActionOperation;

__attribute__((visibility("hidden")))
@interface MusicStoreSocialHistory : XXUnknownSuperclass {
	NSNumber* _accountIdentifier;
	dispatch_queue_s* _dispatchQueue;
	dispatch_source_s* _expirationTimer;
	NSMutableDictionary* _performedActions;
	MusicStoreSocialActionOperation* _reloadOperation;
}
-(void)_setHistoryFromResponseDictionary:(id)responseDictionary;
-(void)_setAccountIdentifier:(id)identifier;
-(void)_scheduleExpirationTimerForURLResponse:(id)urlresponse;
-(void)_removePerformedActionType:(id)type forItemIdentifier:(unsigned long long)itemIdentifier;
-(void)_removeOperationFromLocalChanges:(id)localChanges;
-(void)_reloadFromServerIfExpired;
-(void)_postSocialHistoryChanged;
-(void)_performAutomaticReloadFromServer;
-(void)_cancelExpirationTimer;
-(void)_addPerformedActionType:(id)type forItemIdentifier:(unsigned long long)itemIdentifier;
-(void)_addOperationToLocalChanges:(id)localChanges;
-(void)_urlBagDidLoadNotification:(id)_urlBag;
-(void)_networkTypeDidChangeNotification:(id)_networkType;
-(void)_applicationDidBecomeActiveNotification:(id)_application;
-(void)_accountStoreChangedNotification:(id)notification;
-(void)reloadFromServer;
-(BOOL)hasPerformedActionWithActionType:(id)actionType itemIdentifier:(unsigned long long)identifier;
-(void)addChangeOperation:(id)operation;
-(void)dealloc;
-(id)init;
@end

