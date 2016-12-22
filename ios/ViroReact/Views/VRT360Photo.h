//
//  VRT360Photo.h
//  React
//
//  Created by Vik Advani on 3/3/16.
//  Copyright © 2016 Viro Media. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RCTImageSource.h"
#import "VRTControl.h"
#import "VRTImageAsyncLoaderEventDelegate.h"

@interface VRT360Photo : VRTControl<VRTImageAsyncLoaderEventDelegate>

@property (nonatomic, copy) RCTImageSource *source;
@property (nonatomic, copy) RCTDirectEventBlock onLoadStartViro;
@property (nonatomic, copy) RCTDirectEventBlock onLoadEndViro;

- (instancetype)initWithBridge:(RCTBridge *)bridge;

@end
