//
//  TSBGTask.h
//  TSBackgroundFetch
//
//  Created by Christopher Scott on 2020-01-23.
//  Copyright © 2020 Christopher Scott. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <BackgroundTasks/BackgroundTasks.h>

@interface TSBGTask : NSObject

@property (nonatomic) BGTask* task API_AVAILABLE(ios(13.0));

@property (nonatomic) NSString* identifier;
@property (copy) void (^callback) (NSString*);
@property (nonatomic) NSTimeInterval delay;
@property (nonatomic, readonly) BOOL executed;
@property (nonatomic) BOOL periodic;
@property (nonatomic) BOOL enabled;
@property (nonatomic) BOOL stopOnTerminate; 

+(void)load;
+(NSMutableArray *)tasks;
+(void) add:(TSBGTask*)tsTask;
+(void) remove:(TSBGTask*)tsTask;
+(TSBGTask*) get:(NSString*)identifier;
+(int) countFetch;
+(void)registerForTaskWithIdentifier:(NSString*)identifier isFetch:(BOOL)isFetch;
+(BOOL)useFetchTaskScheduler;
+(BOOL)useProcessingTaskScheduler;

-(instancetype) initWithIdentifier:(NSString*)identifier delay:(NSTimeInterval)delay periodic:(BOOL)periodic callback:(void (^)(NSString* taskId))callback;
-(instancetype) initWithDictionary:(NSDictionary*)config;

-(BOOL) execute;
-(void) finish:(BOOL)success;
-(NSError*) scheduleFetchTask;
-(NSError*) scheduleProcessingTask;
-(void) stop;
-(void) setTask:(BGTask*)task API_AVAILABLE(ios(13));
-(BOOL) isFetchTask;
-(void) destroy;
-(void) save;

@end

