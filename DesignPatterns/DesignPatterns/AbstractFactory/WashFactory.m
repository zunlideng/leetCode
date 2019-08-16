//
//  WashFactory.m
//  DesignPatterns
//
//  Created by iOS on 2019/7/25.
//  Copyright © 2019 iOS. All rights reserved.
//

#import "WashFactory.h"

@implementation WashFactory

- (id<MachineProtol>)makeIconModel {
    return [IconWash new];
}
- (id<MachineProtol>)makeAlModel {
    return [ALWash new];
}
@end
