//
//  ProjectConfig.h
//  driver
//
//  Created by rrbus-ios on 2020/4/11.
//  Copyright © 2020 MIS2016. All rights reserved.
//

#ifndef ProjectConfig_h
#define ProjectConfig_h

#define KSCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define KSCREEN_WIDTH [UIScreen mainScreen].bounds.size.width

#define IPHONE_X \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})

/*状态栏高度*/
#define kStatusBarHeight (CGFloat)(IPHONE_X?(44.0):(20.0))
/*导航条和Tabbar总高度*/
#define kNavBarHeight       (IPHONE_X ? 88.0f : 64.0f)
/*TabBar高度*/
#define kTabBarHeight (CGFloat)(IPHONE_X?(49.0 + 34.0):(49.0))

#define kSafeAreaHeight (IPHONE_X?34:0)

//  适配比例
#define WIDTHSCALE6 ScreenWidth/375.0f
#define HEIGHTSCALE6 ScreenHeight/667.0f
    
// RGB颜色转换（16进制->10进制）
#define UICOLOR_HEX(hexString) [UIColor colorWithRed:((float)((hexString &0xFF0000) >> 16))/255.0 green:((float)((hexString &0xFF00) >> 8))/255.0 blue:((float)(hexString &0xFF))/255.0 alpha:1.0]

// 带有RGBA的颜色设置
#define UICOLOR_RGB(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

// 随机颜色
#define UICOLOR_RANDOM  [UIColor colorWithRed:(arc4random()%255)/255.0 green:(arc4random()%255)/255.0 blue:(arc4random()%255)/255.0 alpha:1.0]

#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;
#define SS(strongSelf)  __strong __typeof(&*self)strongSelf = self;

//获取系统版本
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]

//字符串是否为空
#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || [(str) isEqual:[NSNull null]] || str == nil || [str length] < 1 ? YES : NO || [@"" isEqualToString:(str)])
//数组是否为空
#define kArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
//字典是否为空
#define kDictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)
//是否是空对象
#define kObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| [(_object) isEqual:[NSNull null]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

//获取沙盒 Document
#define kPathDocument       [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒 Cache
#define kPathCache          [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

// app版本号
#define DEVICE_APP_VERSION      (NSString *)[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"]
// app Build版本号
#define DEVICE_APP_BUILD        (NSString *)[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]
// 系统版本号
#define DEVICE_OS_VERSION  [UIDevice currentDevice].systemVersion.doubleValue


#endif /* ProjectConfig_h */
