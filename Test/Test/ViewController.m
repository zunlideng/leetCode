//
//  ViewController.m
//  Test
//
//  Created by iOS on 2019/7/29.
//  Copyright © 2019 iOS. All rights reserved.
//

#import "ViewController.h"

@interface ViewController (){
    NSString *myString;
}

@end

@implementation ViewController

- (void)viewDidLoad

{
    [super viewDidLoad];
    int a = 5 % 3;
    
    [self performSelector:@selector(test)];
    
   
}

-(void)test{
//    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
//    
//    
//    void * context = __autoreleasingPoolPush();
//
//    
//    __autoreleasingPoolPush(context);
//    
//    @autoreleasepool {
//        NSString *string = [[NSString alloc] init];
//        
//        myString = string;
//    }
}

@end
