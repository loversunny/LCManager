//
//  XAEnterpriseInfo.h
//  XACASampleDemo
//
//  Created by jlc on 2017/6/6.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XAEnterpriseInfo : NSObject



/**
 *  企业名称
 */
@property (nonnull, nonatomic, copy) NSString *entName;
/**
 *  工商注册号
 */
@property (nonnull, nonatomic, copy) NSString *busiRegNo;
/**
 *  企业组织机构代码
 */
@property (nonnull, nonatomic, copy) NSString *entOrgCode;

/**
 *  企业税务登记号
 */
@property (nullable, nonatomic, copy) NSString *entTaxRegNo;

/**
 *  三证合一社会信用代码
 */
@property (nullable, nonatomic, copy) NSString *socialCreditCode;

/**
 *  企业所在城市
 */
@property (nullable, nonatomic, copy) NSString *city;

/**
 *  企业所在省份
 */
@property (nullable, nonatomic, copy) NSString *province;

/**
 *  国家
 */
@property (nullable, nonatomic, copy) NSString *countryName;

/**
 *  企业邮箱地址
 */
@property (nullable, nonatomic, copy) NSString *email;

/**
 *  企业联系电话
 */
@property (nullable, nonatomic, copy) NSString *phoneNumber;

/**
 *  企业传真
 */
@property (nullable, nonatomic, copy) NSString *fax;

/**
 *  企业邮政编码
 */
@property (nullable, nonatomic, copy) NSString *zip;

/**
 *  企业地址
 */
@property (nullable, nonatomic, copy) NSString *address;

/**
 *  联系人
 */
@property (nullable, nonatomic, copy) NSString *userName;

/**
 *  联系人证件类型
 */
@property (nullable, nonatomic, copy) NSString *userCardType;

/**
 *  联系人证件号码
 */
@property (nullable, nonatomic, copy) NSString *userCardNum;

/**
 *  联系人性别
 */
@property (nullable, nonatomic, copy) NSString *userGender;

/**
 *  联系人手机号
 */
@property (nullable, nonatomic, copy) NSString *userMobile;


/**
 *  联系人通讯地址
 */
@property (nullable, nonatomic, copy) NSString *userAddress;

/**
 *  联系人邮编
 */
@property (nullable, nonatomic, copy) NSString *userZip;

/**
 *  联系人email
 */
@property (nullable, nonatomic, copy) NSString *userEmail;

/**
 *  联系人所在省份
 */
@property (nullable, nonatomic, copy) NSString *userProvince;

/**
 *  联系人所在城市
 */
@property (nullable, nonatomic, copy) NSString *userCity;

/**
 *  联系人所在单位
 */
@property (nullable, nonatomic, copy) NSString *userCompany;

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
