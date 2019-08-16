//
//  ViewController.m
//  ssd
//
//  Created by iOS on 2019/7/30.
//  Copyright © 2019 iOS. All rights reserved.
//

#import "ViewController.h"
#import <objc/runtime.h>
#import <objc/message.h>


void fooMethod(id obj, SEL _cmd, ...)
{
    NSLog(@"Doing foo");
}

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self performSelector:@selector(reloadData) withObject:nil afterDelay:0];
    // Do any additional setup after loading the view.
}


@end

@implementation ViewController (MessageResolve)


+ (BOOL)resolveClassMethod:(SEL)sel {
    return NO;
}
+ (BOOL)resolveInstanceMethod:(SEL)sel {
    
    if ([NSStringFromSelector(sel) isEqualToString:@"updateAction:"]) {
        class_addMethod(self, sel, (IMP)fooMethod, "v@:");
        return YES;
    }
    
    
    return [super resolveInstanceMethod:sel];
    
    
}

- (id)forwardingTargetForSelector:(SEL)aSelector {
//    return [UITableView new];
    return [super forwardingTargetForSelector:aSelector];
}






- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector {
    NSMethodSignature *m = [NSMethodSignature signatureWithObjCTypes:"v@:"];
    return m;
}


- (void)forwardInvocation:(NSInvocation *)anInvocation {
    UITableView* tab = [UITableView new];
    anInvocation.target = tab;
    [anInvocation setReturnValue:(__bridge void * _Nonnull)(tab)];
    [anInvocation setArgument:@"a" atIndex:0];
    
//    [self doesNotRecognizeSelector:anInvocation.selector];
//    [anInvocation invokeWithTarget:[UITableView new]];
}




@end
