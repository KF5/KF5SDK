//
//  AppDelegate.m
//  SampleSDKApp
//
//  Created by admin on 15/2/2.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <KF5SDK/KF5SDK.h>

@interface AppDelegate ()

@end

#define KFColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]

#define khostName  @"http://tianxiang.kf5.com"
#define kbaseEmail @"iossdk@kf5.com"
#define kAppId     @"001552ba3d1cc2efc711d065650f90d99eb6dded16d80a17"
#define kpassword  @"iossdk"

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    self.window.backgroundColor = [UIColor whiteColor];
    ViewController *view = [[ViewController alloc] init];
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:view];
    self.window.rootViewController = nav;
    
    [self.window makeKeyAndVisible];
    
    // 设置日志状态
#ifdef DEBUG
    [KFLogger enable:YES];
#else
    [KFLogger enable:NO];
#endif
    
    // 初始化配置信息
    [[KFConfig instance]initializeWithHostName:khostName appId:kAppId];
    
    [[KFConfig instance]setEmail:kbaseEmail andUserName:nil PassWord:kpassword WithFailure:nil];
    
    
    // UI配置
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];

    [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
  
    [[UINavigationBar appearance]setBarTintColor:[UIColor redColor]];
    NSDictionary *navbarAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
                                      [UIColor whiteColor] ,NSForegroundColorAttributeName, nil];
    [[UINavigationBar appearance] setTitleTextAttributes:navbarAttributes];
    

    [[KFCreateRequestView appearance]setTextViewFont:[UIFont systemFontOfSize:18.f]];
    
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
    
    [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];

    [[UINavigationBar appearance]setBarTintColor:KFColor(0, 155, 239)];


    
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
