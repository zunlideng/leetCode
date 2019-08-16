//
//  Factory.h
//  DesignPatterns
//
//  Created by iOS on 2019/7/25.
//  Copyright © 2019 iOS. All rights reserved.
//
#import "Machine.h"

@protocol FactoryProtocol <NSObject>

- (id<MachineProtol>)makeIconModel;

- (id<MachineProtol>)makeAlModel;

@end
