//
//  XAManager.h
//  XACASampleDemo
//  调用方法类 弹pin
//  Created by jlc on 2017/6/6.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XACASDK.h"
#import "XABaseManager.h"

@class XAEnterpriseInfo;


@interface XAManager : XABaseManager

+ (instancetype)sharedDevice;

/**
 *  申请证书(实时)
 *
 *  @param user           用户信息
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param resultBlock    返回结果
 */
+ (void)applyCert:(XAUserInfo *)user
   businessUserID:(NSString *)businessUserID
     businessCode:(NSString *)businessCode
      resultBlock:(void (^) (XAResultInfo *resultVo)) resultBlock;


/**
 证书查询调用接口
 
 @param businessUserID 业务ID
 @param code 业务编号
 */
+(void)queryCertWithBusinessID:(NSString *)businessUserID
                  businessCode:(NSString *)code;



/**
 *  证书更新接口
 *
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param month          证书有效期
 *  @param startDate      证书生效日期
 *  @param resultBlock    返回回调
 */
+(void) updateCert:(NSString *)businessUserID
      businessCode:(NSString *)businessCode
             month:(NSInteger)month
         startDate:(NSString *)startDate
       resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;

/**
 *  证书延期接口
 *
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param startDate      证书生效日期
 *  @param endDate        证书失效日期
 *  @param resultBlock    返回回调
 */

+(void) extendCertDate:(NSString *)businessUserID
          businessCode:(NSString *)businessCode
             startDate:(NSString *)startDate
               endDate:(NSString *)endDate
           resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;

/**
 *  用户信息变更接口
 *
 *  @param user           用户信息类
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param startDate      证书生效日期
 *  @param endDate        证书失效日期
 *  @param resultBlock    返回回调
 */
+(void) updateCertUserInfo:(XAUserInfo *)user
            businessUserID:(NSString *)businessUserID
              businessCode:(NSString *)businessCode
                 startDate:(NSString *)startDate
                   endDate:(NSString *)endDate
               resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;


/**
 *  变更证书状态
 *
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param certType       证书操作类型(10：证书吊销 20：证书冻结 30：证书解冻)
 *  @param resultBlock    返回回调
 */
+(void) updateCertStatus:(NSString *)businessUserID
            businessCode:(NSString *)businessCode
                certType:(NSInteger)certType
             resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;














/**
 *  原文签名
 *
 *  @param signContent    签名原文
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param businessType   业务操作类型
 *  @param businessNo     业务请求流水号
 *  @param resultBlock    返回结果
 */
+(void)signature:(NSString *)signContent
  businessUserID:(NSString *)businessUserID
    businessCode:(NSString *)businessCode
    businessType:(NSString *)businessType
      businessNo:(NSString *)businessNo
     resultBlock:(void (^) (XAResultInfo *resultVo)) resultBlock;

/**
 *  摘要签名
 *
 *  @param signContent    要签名的数据(经过杂凑算法后的数据)
 *  @param algorithm      杂凑算法标识(301:SM3 302:SHA1)
 *  @param businessUserID 业务APP用户标识
 *  @param businessCode   业务编号
 *  @param businessType   业务操作类型
 *  @param businessNo     业务请求流水号
 *  @param resultBlock    返回回调
 */
+(void) signContentHash:(NSString *)signContent
              algorithm:(NSInteger)algorithm
         businessUserID:(NSString *)businessUserID
           businessCode:(NSString *)businessCode
           businessType:(NSString *)businessType
             businessNo:(NSString *)businessNo
            resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;

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
      resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;



///**
// *  非对称加密
// *
// *  @param businessUserID 业务APP用户标识
// *  @param businessCode   业务编号
// *  @param algorithm      算法标示
// *  @param encryptFlag    加密标识（1:公钥加密 2:X509 证书加密）
// *  @param asykey         公钥或 X509 证 书
// *  @param input          加密原文
// *  @param resultBlock    返回回调
// */
//+(void)asyEncrypt:(NSString *)businessUserID
//     businessCode:(NSString *)businessCode
//        algorithm:(int)algorithm
//      encryptFlag:(int)encryptFlag
//           asykey:(NSString *)asykey
//            input:(NSString *)input
//      resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;












/**
 *  生成CSR
 *
 *  @param user           用户信息
 *  @param businessCode   业务编号
 *  @param algorithm      算法标示（101：RSA 103：SM2）
 *  @param businessUserID 业务APP用户标识
 *  @param resultBlock    返回结果
 */
+ (void)generateCSR:(XAUserInfo *)user
       businessCode:(NSString *)businessCode
          algorithm:(int)algorithm
     businessUserID:(NSString*)businessUserID
        resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;


/**
 *  解析数字信封
 *
 *  @param businessUserID        业务APP用户标识
 *  @param businessCode          业务编号
 *  @param envelopedData         数字信封
 *  param contentEncryAlgorithm 内容加密算法
 *  param encryKeyAlgorithm     对称秘钥加密算法
 *  @param resultBlock           返回回调
 */
+ (void)disEnvelopedData:(NSString *)businessUserID
            businessCode:(NSString *)businessCode
           envelopedData:(NSString *)envelopedData
             resultBlock:(void (^) (XAResultInfo *resultVo)) resultBlock;





















#pragma mark - 企业

/**
 *  申请证书(企业)
 *
 *  @param enterprise      企业客户信息
 *  @param enterpriseID    业务企业标识
 *  @param businessCode    业务编码
 *  @param algorithm       非对称算法标识
 *  @param certType        证书类型
 *  @param extend1         扩展字段1
 *  @param resultBlock     block回调
 */
+ (void)applyCertWithEnterprise:(XAEnterpriseInfo *)enterprise
                   enterpriseID:(NSString *)enterpriseID
                   businessCode:(NSString *)businessCode
                      algorithm:(NSString *)algorithm
                       certType:(NSString *)certType
                        extend1:(NSString *)extend1
                    resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;


/**
 *  生成企业CSR
 *
 *  @param enterprise     企业信息
 *  @param businessCode   业务编号
 *  @param algorithm      算法标示(101:RSA 103:SM2)
 *  @param businessUserID 业务APP用户标识
 *  @param extend1        扩展字段
 *  @param resultBlock    返回结果
 */
+ (void)generateCompanyCSR:(XAEnterpriseInfo *)enterprise
              businessCode:(NSString *)businessCode
                 algorithm:(NSString *)algorithm
            businessUserID:(NSString*)businessUserID
                   extend1:(NSString *)extend1
               resultBlock:(void (^)(XAResultInfo *resultVo)) resultBlock;







@end
