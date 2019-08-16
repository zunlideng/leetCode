//
//  AppDelegate.m
//  DesignPatterns
//
//  Created by iOS on 2019/7/25.
//  Copyright © 2019 iOS. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;

@property (nonatomic, strong) NSString *str;

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
    @autoreleasepool {
        NSString *s = [NSString stringWithFormat:@"%@", @"ssa000"];
        self.str = s;
    }
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        NSLog(@"%@", self.str);
    });
    // Insert code here to initialize your application
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
