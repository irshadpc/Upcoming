//
//  EKEventManager.h
//  EventKitTest
//
//  Created by Brendan Lynch on 13-04-11.
//  Copyright (c) 2013 Teehan+Lax. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <EventKit/EventKit.h>

extern NSString *const EKEventManagerAccessibleKeyPath;
extern NSString *const EKEventManagerSourcesKeyPath;

@interface EKEventManager : NSObject

@property (nonatomic, strong) EKEventStore *store;

@property (nonatomic, assign) BOOL accessible;
@property (nonatomic, strong) RACSignal *eventsSignal;
@property (nonatomic, strong) RACSignal *nextEventSignal;

@property (nonatomic, readonly) NSMutableArray *sources;
@property (nonatomic, readonly) NSMutableArray *selectedCalendars;

@property (nonatomic, readonly) NSCalendar *calendar;

+(EKEventManager *)sharedInstance;
-(void)refresh;
-(void)toggleCalendarWithIdentifier:(NSString *)calendarIdentifier;

-(void)promptForAccess;

@end