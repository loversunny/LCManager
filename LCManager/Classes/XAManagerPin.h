//
//  XAManagerPin.h
//  XACASampleDemo
// 调用方法类 传pin
//  Created by jlc on 2017/6/6.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XACASDK.h"
#import "XABaseManager.h"



@interface XAManagerPin : XABaseManager


/**
 *  申请证书（实时）
 *
 *  @param user           用户信息
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param pin            密码
 *  @param resultBlock    返回回调
 */
+ (void)applyCert:(XAResultInfo *)user
   businessUserID:(NSString *)businessUserID
     businessCode:(NSString *)businessCode
              pin:(NSString *)pin
      resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;

/**
 *  原文签名
 *
 *  @param signContent    签名原文
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param businessType   业务操作类型
 *  @param businessNo     业务请求流水号
 *  @param pin            密码
 *  @param resultBlock    返回回调
 */
+(void)signature:(NSData*)signContent
  businessUserID:(NSString *)businessUserID
    businessCode:(NSString *)businessCode
    businessType:(NSString *)businessType
      businessNo:(NSString *)businessNo
             pin:(NSString *)pin
     resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;

/**
 *  摘要签名
 *
 *  @param signContent    签名原文经过杂凑算法后的内容
 *  @param algorithm      杂凑算法
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param businessType   业务操作类型
 *  @param businessNo     业务请求流水号
 *  @param pin            密码
 *  @param resultBlock    返回回调
 */
+(void) signContentHash:(NSData*)signContent
              algorithm:(NSInteger)algorithm
         businessUserID:(NSString *)businessUserID
           businessCode:(NSString *)businessCode
           businessType:(NSString *)businessType
             businessNo:(NSString *)businessNo
                    pin:(NSString *)pin
            resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;


/**
 *  非对称解密
 *
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param algorithm      算法标示
 *  @param encryptData    加密数据
 *  @param pin            密码
 *  @param resultBlock    返回回调
 */
+(void)asyDecrypt:(NSString *)businessUserID
     businessCode:(NSString *)businessCode
        algorithm:(int)algorithm
      encryptData:(NSData*)encryptData
              pin:(NSString *)pin
      resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;


/**
 *  解析数字信封
 *
 *  @param businessUserID        业务APP用户标识
 *  @param businessCode          业务编号
 *  @param envelopedData         数字信封
 *  @param contentEncryAlgorithm 内容加密算法
 *  @param encryKeyAlgorithm     对称秘钥加密算法
 *  @param resultBlock           返回回调
 */
+ (void)disEnvelopedData:(NSString *)businessUserID
            businessCode:(NSString *)businessCode
           envelopedData:(NSString *)envelopedData
                     pin:(NSString *)pin
             resultBlock:(void (^) (XAResultInfo *resultVo)) resultBlock;



@end
