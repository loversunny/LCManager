//
//  XAResultInfo.h
//  XACASampleDemo
//
//  Created by jlc on 2017/6/6.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XAResultInfo : NSObject

/**
 结果编码
 */
@property(nonatomic,strong) NSString * resultCode;

/**
 结果描述
 */
@property(nonatomic,strong) NSString * resultDes;

/**
 *  业务用户标识
 */
@property (nonatomic, copy) NSString *businessUserID;
/**
 *  签名证书
 */
@property (nonatomic, copy) NSString *signCert;

/**
 *  加密证书
 */
@property (nonatomic, copy) NSString * encryptCert;

/**
 *  签名值
 */
@property (nonatomic, copy) NSString *signData;

/**
 *  业务请求流水号
 */
@property (nonatomic, copy) NSString *businessNo;

/**
 *  手机U盾签名流水号
 */
@property (nonatomic, copy) NSString *signNo;

/**
 *  加密密文
 */
@property (nonatomic, copy) NSData *encData;

/**
 *  解密明文
 */
@property (nonatomic, copy) NSData *decData;
@property (nonatomic, copy) NSData *envelopedData;
/**
 *  P10结构的CSR文件
 */
@property (nonatomic, copy) NSString * csr;
/**
 *  手机盾设备ID
 */
@property(nonatomic,copy)NSString *equipmentId;

@end
