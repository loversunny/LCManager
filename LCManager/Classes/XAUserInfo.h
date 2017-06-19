//
//  UserInfo.h
//  XASDK
//  个人用户信息类
//  Created by wangxq on 2017/5/23.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface XAUserInfo : NSObject<NSCoding>

/**
 *  申请人名字
 */
@property (nonnull, nonatomic, copy) NSString *userName;
/**
 *  申请人性别
 */
@property (nonnull, nonatomic, copy) NSString *gender;
/**
 *  手机号
 */
@property (nonnull, nonatomic, copy) NSString *mobilePhone;

/**
 *  证件类型
 */
@property (nullable, nonatomic, copy) NSString *cardType;

/**
 *  证件号码
 */
@property (nullable, nonatomic, copy) NSString *cardNum;

/**
 *  通讯地址
 */
@property (nullable, nonatomic, copy) NSString *address;

/**
 *  邮编
 */
@property (nullable, nonatomic, copy) NSString *postalCode;

/**
 *  用户email
 */
@property (nullable, nonatomic, copy) NSString *email;

/**
 *  省份代码
 */
@property (nullable, nonatomic, copy) NSString *province;

/**
 *  城市
 */
@property (nullable, nonatomic, copy) NSString *city;

/**
 *  部门
 */
@property (nullable, nonatomic, copy) NSString *unitName;

/**
 *  单位
 */
@property (nullable, nonatomic, copy) NSString *userOrg;

/**
 *  国家
 */
@property (nullable, nonatomic, copy) NSString *countryName;

/**
 *  扩展项 1
 */
@property (nullable, nonatomic, copy) NSString *extend1;

/**
 *  扩展项 2
 */
@property (nullable, nonatomic, copy) NSString *extend2;

/**
 *  扩展项 3
 */
@property (nullable, nonatomic, copy) NSString *extend3;

/**
 *  扩展项 4
 */
@property (nullable, nonatomic, copy) NSString *extend4;

/**
 *  扩展项 5
 */
@property (nullable, nonatomic, copy) NSString *extend5;

@end

