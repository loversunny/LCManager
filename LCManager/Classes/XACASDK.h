//
//  XACASDK.h
//  XACASampleDemo
//
//  Created by wangxq on 2017/5/26.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "XAResultInfo.h"
#import "XAUserInfo.h"
#import "XAManager.h"
#import "XAManagerPin.h"
#import "XAEnterpriseInfo.h"
#import "NSObject+LCCategory.h"




#define xa_URL(url) [NSURL URLWithString:url]
#define xa_string(str1,str2) [NSString stringWithFormat:@"%@%@",str1,str2]
#define xa_str(str1) [NSString stringWithFormat:@"%@",str1]
#define xa_Num(num1) [NSString stringWithFormat:@"%d",num1]
#define xa_Integer(num1) [NSString stringWithFormat:@"%ld",num1]
#define xa_Int(num1) [NSString stringWithFormat:@"%d",num1]


/**
 业务类型 - 数字证书
 
 - BusindessTypeXACA: 信安CA
 - BusindessTypeCYCA: 创园CA
 - BusindessTypeNormal: 默认类型
 */
typedef NS_ENUM(NSUInteger, BusindessType) {
    BusindessTypeXACA = 0,
    BusindessTypeCYCA,
    BusindessTypeNormal = BusindessTypeXACA,
};


@interface XACASDK : NSObject


@property(nonatomic,copy)  void(^completedBlock)(XAResultInfo * info);


/**
 初始化实例对象
 
 @return 实例对象
 */
+ (instancetype)defaultDevice;


/**
 必须调用该方法
 type   业务类型
 @param appID 开发平台生成的appID 根据id进行验证appid的合法性
 */

-(void)registerApp:(NSString *)appID
      businessType:(NSString *)type;


/**
 获取当前SDK版本号
 */
- (NSString *)getVersion;


/**
 获取当前数字证书类型
 */
- (NSString *)currentBusinessType;



/**
 根据实际项目整体色调,调整SDK整体色调
 
 @param color 色值
 */
+ (void)changeColor:(UIColor *)color;




/**
 发起调用,传入参数-
 
 @param info 用户信息或者公司信息实例对象,发起调用的操作对象,和方法名字,
 @param methodID 方法唯一标识,用来判断具体操作
 @param param 添加其他的一些参数
 @param feedBlock 回调结果
 */
- (void)callSDKWithInfo:(id)info
               methodID:(NSString *)methodID
         otherParmaters:(id)param
               feedBack:(void(^)(XAResultInfo * info))feedBlock;

/**
 用于跳转操作完成之后,回调回来的时候,处理这个
 
 @param url 回调进来传递的url
 @param result 处理结果
 */
- (BOOL)handleUrl:(NSURL *)url
           result:(void(^)(XAResultInfo * resultInfo))result;




@end
