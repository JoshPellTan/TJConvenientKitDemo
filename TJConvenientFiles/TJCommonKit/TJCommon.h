//
//  TJCommon.h
//
//  Created by JoshPell on 16/9/1.
//  Copyright © 2016年 JoshPell. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


#pragma mark - Device Frame
// 设备高度
#define kScreenHeight ([UIScreen mainScreen].bounds.size.height)

// 设备宽
#define kScreenWidth ([UIScreen mainScreen].bounds.size.width)

// 设备bounds
#define kScreenBounds ([UIScreen mainScreen].bounds)

//设计图按照6s，6设计，适配时可能需要加入的系数
#define KScale (kScreenWidth/375.0f)

//设计图按照6s，6设计，适配时可能需要加入的系数
#define KHeightScale (kScreenHeight/667.0f)

//X除开常用的statusbar=20的高度后，刘海还应适配的高度,宏定义自带判断
#define KiPhoneXTopMarginFloat ([WZCommon height] == 812?24.0:0)

//X屏幕底部会被圆弧影响的高度
#define KiPhoneXBottomMarginFloat ([WZCommon height] == 812?34.0:0)

//-----------------------------------------------------------------------------

// 弱引用对象
#define kWeakObject(object) __weak __typeof(object) weakObject = object;

// 强引用对象
#define kStrongObject(object) __strong __typedef(object) strongObject = object;

// 获取主线程队列
#define kMainThread (dispatch_get_main_queue())

// 获取全局队列
#define kGlobalThread dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)

// 弧度转角度
#define kRadiansToDegrees(radians) ((radians) * (180.0 / M_PI))

// 角度转弧度
#define kDegreesToRadians(angle) ((angle) / 180.0 * M_PI)

// 获取本机iOS版本
#define kIOSVersion ([UIDevice currentDevice].systemVersion.floatValue)

//-----------------------------------------------------------------------------

#pragma mark - System Singletons
// Application delegate
#define kAppDelegate ((AppDelegate *)[[UIApplication  sharedApplication] delegate])

// UserDefault单例对象
#define kUserDefaults [NSUserDefaults standardUserDefaults]

// 系统通知中心
#define kNotificationCenter  [NSNotificationCenter defaultCenter]

// 发通知简便宏
#define kPostNotificationWithNameAndUserInfo(notificationName, userInfo) \
[kNotificationCenter postNotificationName:notificationName object:nil userInfo:userInfo]

//-----------------------------------------------------------------------------

#pragma mark - Judge
// 判断是否为空字符串或null字符串
#define kIsEmptyString(s) (s == nil || [s isKindOfClass:[NSNull class]] || ([s isKindOfClass:[NSString class]] && s.length == 0))

// 判断是否为空对象或null对象
#define kIsEmptyObject(obj) (obj == nil || [obj isKindOfClass:[NSNull class]])

// 判断字典对象是否合法
#define kIsDictionary(objDict) (objDict != nil && [objDict isKindOfClass:[NSDictionary class]])

// 判断数组对象是否合法
#define kIsArray(objArray) (objArray != nil && [objArray isKindOfClass:[NSArray class]])

// 判断是否为iPad
#define kIsIPad \
([[UIDevice currentDevice] respondsToSelector:@selector(userInterfaceIdiom)]\
&& [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)

// 判断设备是否是旋转过
#define kIsLandscape (UIInterfaceOrientationIsLandscape([[UIApplication sharedApplication] statusBarOrientation]))

//-----------------------------------------------------------------------------

#pragma mark - Blocks
//携带错误信息的block
typedef void (^TJErrorBlock)(NSError *error);

//携带空信息的block
typedef void (^TJVoidBlock)(void);

//携带字符串信息的block
typedef void (^TJStringBlock)(NSString *result);

//携带通知信息的block
typedef void (^TJNotificationBlock)(NSNotification *sender);

//携带bool信息的block
typedef void (^TJBOOLBlock)(BOOL result);

//携带数组信息的block
typedef void (^TJArrayBlock)(NSArray *list);

//携带数组和字符串信息的block
typedef void (^TJArrayMessageBlock)(NSArray *list, NSString *msg);

//携带字典信息的block
typedef void (^TJDictionaryBlock)(NSDictionary *response);

//携带字典和字符串信息的block
typedef void (^TJDictionaryMessageBlock)(NSDictionary *response, NSString *msg);

//携带数值对象信息的block
typedef void (^TJNumberBlock)(NSNumber *resultNumber);

//携带数值对象和字符串信息的block
typedef void (^TJNumberMessageBlock)(NSNumber *resultNumber, NSString *msg);

//携带id类型对象信息的block
typedef void (^TJIdBlock)(id result);

//携带button信息的block
typedef void(^TJButtonBlock)(UIButton *sender);

//携带手势对象信息的block
typedef void(^TJGestureBlock)(UIGestureRecognizer *sender);

//携带长按手势对象信息的block
typedef void(^TJLongGestureBlock)(UILongPressGestureRecognizer *sender);

//携带单击手势对象信息的block
typedef void(^TJTapGestureBlock)(UITapGestureRecognizer *sender);

//其他类型block根据实际情况自行添加


@interface TJCommon : NSObject




+ (NSRegularExpression *)regexUrl;
+ (NSRegularExpression *)regexTopic;

//获取当前视图控制器
+ (UIViewController *)topViewController;

/**
 判断相册的使用权限

 @param isNeedManual 某些方法不会自动调用系统权限请求，需要手动请求权限后继续逻辑操作，传YES，其他能自动调用的地方传NO即可
 @param block 需要手动请求权限时的后续逻辑
 @return 是否能根据权限继续逻辑流程
 */
+ (BOOL)isAllowPhotoLibraryNeedManualAuthorizationRequest:(BOOL)isNeedManual block:(void(^)())block;
/**
 判断视频的使用权限
 
 @return 是否有视频权限
 */
+ (BOOL)isAllowCamera;
/**
 判断录音使用权限

 @return 是否有视频权限
 */
+ (BOOL)isAllowAudioRecord;
/**
 判断定位权限

 @return 是否有定位权限
 */
+ (BOOL)isAllowLocationNeedTipsView:(BOOL)needTips;

NSString * getSafeString(id object);
NSString * getNoSpaceString(id object);

@end
