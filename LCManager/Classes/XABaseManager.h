//
//  XABaseManager.h
//  XACASampleDemo
//  计算基类  包含一些共同的算法
//  Created by jlc on 2017/6/6.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@class XAResultInfo;

@interface XABaseManager : NSObject

/**
 *  对称加密
 *
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param algorithm      算法标示
 *  @param symkey         对称密钥
 *  @param input          加密原文
 *  @param resultBlock    返回回调
 */
+(void)symEncrypt:(NSString *)businessUserID
     businessCode:(NSString *)businessCode
        algorithm:(int)algorithm
           symkey:(NSData*)symkey
            input:(NSData *)input
      resultBlock:(void (^) (XAResultInfo *resultVo))resultBlock;

/**
 *  对称解密
 *
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param algorithm      算法标示
 *  @param symkey         对称密钥
 *  @param input          加密原文
 *  @param resultBlock    返回回调
 */
+(void)symDecrypt:(NSString *)businessUserID
     businessCode:(NSString *)businessCode
        algorithm:(int)algorithm
           symkey:(NSString *)symkey
            input:(NSString *)input
      resultBlock:(void (^)(XAResultInfo *resultVo))resultBlock;

/**
 *  非对称加密
 *
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param algorithm      算法标示
 *  @param encryptFlag    加密标识（1:公钥加密 2:X509 证书加密）
 *  @param asykey         公钥或 X509 证 书
 *  @param input          加密原文
 *  @param resultBlock    返回回调
 */
+ (void)asyEncrypt:(NSString *)businessUserID
     businessCode:(NSString *)businessCode
        algorithm:(int)algorithm
      encryptFlag:(int)encryptFlag
           asykey:(NSString *)asykey
            input:(NSString *)input
      resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;

/**
 *  非对称解密
 *
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param algorithm      算法标示
 *  @param encryptData    待解密密文
 *  @param resultBlock    返回回调
 */
+(void)asyDecrypt:(NSString *)businessUserID
     businessCode:(NSString *)businessCode
        algorithm:(int)algorithm
      encryptData:(NSData *)encryptData
      resultBlock:(void (^)(XAResultInfo *resultVo))resultBlock;










/**
 *  摘要
 *
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param algorithm      算法标识(SHA256、MD5、SM3)
 *  @param input          摘要原文
 *  @param resultBlock    返回回调
 */
+ (void)getHash:(NSString *)businessUserID
   businessCode:(NSString *)businessCode
      algorithm:(NSString *)algorithm
          input:(NSString *)input
    resultBlock:(void (^) (XAResultInfo *resultVo)) resultBlock;

/**
 *  验签
 *
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param algorithm      算法标识
 *  @param input          签名原文
 *  @param cert           证书
 *  @param sign           签名值
 *  @param resultBlock    返回回调
 */
+ (void)verifySignature:(NSString *)businessUserID
           businessCode:(NSString *)businessCode
              algorithm:(NSString *)algorithm
                  input:(NSData *)input
                   cert:(NSString *)cert
                   sign:(NSData *)sign
            resultBlock:(void (^) (XAResultInfo *resultVo))resultBlock;



/**
 *  封装数字信封
 *
 *  @param businessUserID        业务APP用户标识
 *  @param businessCode          业务编号
 *  @param contentEncryAlgorithm 内容加密算法
 *  @param encryKeyAlgorithm     对称秘钥加密算法
 *  @param input                 原文
 *  @param cert                  证书
 *  @param resultBlock           返回回调
 */
+ (void)envelopedData:(NSString *)businessUserID
         businessCode:(NSString *)businessCode
contentEncryAlgorithm:(NSString *)contentEncryAlgorithm
    encryKeyAlgorithm:(NSString *)encryKeyAlgorithm
                input:(NSData *)input
                 cert:(NSString *)cert
          resultBlock: (void (^) (XAResultInfo * resultVo)) resultBlock;



@end
