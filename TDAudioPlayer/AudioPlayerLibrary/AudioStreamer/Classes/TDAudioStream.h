//
//  TDAudioStream.h
//  Console.fm
//
//  Created by Tony DiPasquale on 10/4/13.
//  Copyright (c) 2013 Simple Casual. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum TDAudioStreamEvent {
    TDAudioStreamEventHasData = 0,
    TDAudioStreamEventEnd,
    TDAudioStreamEventError
} TDAudioStreamEvent;

@class TDAudioStream;

@protocol TDAudioStreamDelegate <NSObject>

@required
- (void)audioStream:(TDAudioStream *)audioStream didRaiseEvent:(TDAudioStreamEvent)event;

@end

@interface TDAudioStream : NSObject

@property (weak, nonatomic) id<TDAudioStreamDelegate> delegate;

- (instancetype)initWithInputStream:(NSInputStream *)inputStream;
- (instancetype)initWithURL:(NSURL *)url;

- (void)open;
- (UInt32)readData:(uint8_t *)data maxLength:(UInt32)maxLength;

@end