//
//  XAUserInfo.m
//  XACASampleDemo
//
//  Created by jlc on 2017/6/6.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import "XAUserInfo.h"


@interface XAUserInfo ()


@end


@implementation XAUserInfo

-(void)encodeWithCoder:(NSCoder *)aCoder{
    [aCoder encodeObject:self.userName forKey:@"userName"];
    [aCoder encodeObject:self.gender forKey:@"gender"];
    [aCoder encodeObject:self.mobilePhone forKey:@"mobilePhone"];
    [aCoder encodeObject:self.cardType forKey:@"cardType"];
    [aCoder encodeObject:self.cardNum forKey:@"cardNum"];
    [aCoder encodeObject:self.address forKey:@"address"];
    [aCoder encodeObject:self.postalCode forKey:@"postalCode"];
    [aCoder encodeObject:self.email forKey:@"email"];
    [aCoder encodeObject:self.province forKey:@"province"];
    [aCoder encodeObject:self.city forKey:@"city"];
    [aCoder encodeObject:self.unitName forKey:@"unitName"];
    [aCoder encodeObject:self.userOrg forKey:@"userOrg"];
    [aCoder encodeObject:self.countryName forKey:@"countryName"];
    [aCoder encodeObject:self.extend1 forKey:@"extend1"];
    [aCoder encodeObject:self.extend2 forKey:@"extend2"];
    [aCoder encodeObject:self.extend3 forKey:@"extend3"];
    [aCoder encodeObject:self.extend4 forKey:@"extend4"];
    
    [aCoder encodeObject:self.extend5 forKey:@"extend5"];
    
}


-(instancetype)initWithCoder:(NSCoder *)aDecoder{
    if (self = [super init]) {
        self.userName = [aDecoder decodeObjectForKey:@"userName"];
        self.gender = [aDecoder decodeObjectForKey:@"gender"];
        self.mobilePhone = [aDecoder decodeObjectForKey:@"mobilePhone"];
        self.cardType = [aDecoder decodeObjectForKey:@"cardType"];
        self.cardNum = [aDecoder decodeObjectForKey:@"cardNum"];
        self.address = [aDecoder decodeObjectForKey:@"address"];
        self.postalCode = [aDecoder decodeObjectForKey:@"postalCode"];
        self.email = [aDecoder decodeObjectForKey:@"email"];
        self.province = [aDecoder decodeObjectForKey:@"province"];
        self.city = [aDecoder decodeObjectForKey:@"city"];
        self.unitName = [aDecoder decodeObjectForKey:@"unitName"];
        self.userOrg = [aDecoder decodeObjectForKey:@"userOrg"];
        self.countryName = [aDecoder decodeObjectForKey:@"countryName"];
        self.extend1 = [aDecoder decodeObjectForKey:@"extend1"];
        self.extend2 = [aDecoder decodeObjectForKey:@"extend2"];
        self.extend3 = [aDecoder decodeObjectForKey:@"extend3"];
        self.extend4 = [aDecoder decodeObjectForKey:@"extend4"];
        self.extend5 = [aDecoder decodeObjectForKey:@"extend5"];
    }
    return self;
}










@end
