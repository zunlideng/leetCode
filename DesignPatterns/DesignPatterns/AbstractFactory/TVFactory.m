//
//  TVFactory.m
//  DesignPatterns
//
//  Created by iOS on 2019/7/25.
//  Copyright © 2019 iOS. All rights reserved.
//

#import "TVFactory.h"

@implementation TVFactory

- (id<MachineProtol>)makeIconModel {
    return [IconTV new];
}

- (id<MachineProtol>)makeAlModel {
    return [ALTV new];
}

@end
