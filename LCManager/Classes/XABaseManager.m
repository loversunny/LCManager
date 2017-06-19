//
//  XABaseManager.m
//  XACASampleDemo
//
//  Created by jlc on 2017/6/6.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import "XABaseManager.h"
#import "XACASDK.h"

@implementation XABaseManager



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
           symkey:(NSString *)symkey
            input:(NSString *)input
      resultBlock:(void (^) (XAResultInfo *resultVo))resultBlock{
    
    [[XACASDK defaultDevice] callSDKWithInfo:nil methodID:@"108" otherParmaters:@{@"originalstr":input,@"m_key":symkey,@"algorithm":xa_Int(algorithm),@"businessUserID":businessUserID,@"businessCode":businessCode} feedBack:^(XAResultInfo *info) {
        
    }];
    
    
}

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
      resultBlock:(void (^)(XAResultInfo *resultVo))resultBlock{
    
    [[XACASDK defaultDevice] callSDKWithInfo:nil methodID:@"109" otherParmaters:@{@"originalstr":input,@"m_key":symkey,@"algorithm":xa_Int(algorithm),@"businessUserID":businessUserID,@"businessCode":businessCode} feedBack:^(XAResultInfo *info) {
        
    }];
}


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
+(void)asyEncrypt:(NSString *)businessUserID
     businessCode:(NSString *)businessCode
        algorithm:(int)algorithm
      encryptFlag:(int)encryptFlag
           asykey:(NSString *)asykey
            input:(NSString *)input
      resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock{
    
    [[XACASDK defaultDevice] callSDKWithInfo:nil methodID:@"110" otherParmaters:@{@"originalstr":input,@"m_key":asykey,@"algorithm":xa_Int(algorithm),@"encryptFlag":xa_Int(encryptFlag),@"businessUserID":businessUserID,@"businessCode":businessCode} feedBack:^(XAResultInfo *info) {
        
    }];
}


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
      resultBlock:(void (^)(XAResultInfo *resultVo))resultBlock{
    
    NSString *methodID = @"111";
    
    if ([[XACASDK defaultDevice].currentBusinessType isEqualToString:@"1"]) {
        
//        [ShieldSDK asyDecrypt:businessUserID businessCode:businessCode algorithm:algorithm encryptData:encryptData resultBlock:^(ResultVo *resultVo) {
//            NSLog(@"%@",resultVo.resultDecs);
//        }];
    }
    
    
    
    
    
    
    
    
    
    
}

#warning 标记--业务app方法没有实现 -112 

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
    resultBlock:(void (^) (XAResultInfo *resultVo)) resultBlock{
    
    [[XACASDK defaultDevice]callSDKWithInfo:nil methodID:@"112" otherParmaters:@{@"businessUserID":businessUserID,@"businessCode":businessCode,@"originalstr":input,@"algorithm":algorithm} feedBack:^(XAResultInfo *info) {
        
    }];
    
}

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
          resultBlock: (void (^) (XAResultInfo * resultVo)) resultBlock{
    if ([[XACASDK defaultDevice].currentBusinessType isEqualToString:@"1"]) {
//        [BaseShieldSDK envelopedData:businessUserID businessCode:businessCode contentEncryAlgorithm:contentEncryAlgorithm encryKeyAlgorithm:encryKeyAlgorithm input:input cert:cert resultBlock:^(ResultVo *resultVo) {
//            
//        }];
    }
}



@end
