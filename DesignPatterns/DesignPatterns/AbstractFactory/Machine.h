//
//  Machine.h
//  DesignPatterns
//
//  Created by iOS on 2019/7/25.
//  Copyright © 2019 iOS. All rights reserved.
//

@protocol MachineProtol <NSObject>

- (void)run;

@end

@interface ALWash : NSObject <MachineProtol>

@end

@implementation ALWash

- (void)run {
    
}

@end

@interface ALTV : NSObject <MachineProtol>

@end

@implementation ALTV

- (void)run {
    
}

@end

@interface IconWash : NSObject <MachineProtol>

@end

@implementation IconWash

- (void)run {
    
}

@end

@interface IconTV : NSObject <MachineProtol>

@end

@implementation IconTV

- (void)run {
    
}

@end
