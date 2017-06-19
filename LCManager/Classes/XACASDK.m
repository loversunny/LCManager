//
//  XACASDK.m
//  XACASampleDemo
//
//  Created by wangxq on 2017/5/26.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import "XACASDK.h"

static  NSString *XACACALLBACKRESULT = @"XACACALLBACKRESULT";

#define XACAScheme @"hninfo"

@interface XACASDK ()


@property(nonatomic,strong) NSString * BusinessType;


@property(nonatomic,strong) NSString * appid;

@end

/*
 该项目对应主色调,调整,以便于项目一致,一般先给一个默认色值,以免开发者没有设置,导致崩溃
 */


@implementation XACASDK



//注册app
-(void)registerApp:(NSString *)appID businessType:(NSString *)type{
    //获取项目bundleID,根据相关算法或者加密传输到服务器去验证该APPID的合法性
    
    //如果合法,就赋值
    [XACASDK defaultDevice].appid = appID;

    
    [XACASDK defaultDevice].BusinessType = type;
    
}

+(instancetype)defaultDevice{
    static dispatch_once_t onceToken;
    static XACASDK *xaca = nil;
    dispatch_once(&onceToken, ^{
        xaca = [XACASDK new];
    });
    return xaca;
}



/**
 获取当前SDK版本号
 */
- (NSString *)getVersion{
    
    //版本号本地填写 开发平台应该包含各个版本,淘汰的版本不再提供下载
    
    return @"1.0.1";
}

- (NSString *)currentBusinessType{
    
    
    return [XACASDK defaultDevice].BusinessType;
}


/**
 根据实际项目整体色调,调整SDK整体色调
 
 @param color 色值
 */
+ (void)changeColor:(UIColor *)color{
    NSAssert(color, @"color is nil");
}


/**
 发起调用,传入参数-
 
 @param info 用户信息或者公司信息实例对象,发起调用的操作对象,和方法名字,
 @param feedBlock 回调结果
 */
- (void)callSDKWithInfo:(id)info
               methodID:(NSString *)methodID
         otherParmaters:(id)param
               feedBack:(void(^)(XAResultInfo * info))feedBlock
{
    
    NSAssert(methodID, @"不能为空");
    
    //传入scheme和数字证书类型
    NSMutableString *urlStr = [NSMutableString stringWithFormat:@"%@://?scheme=%@&businesstype=%@&method=%@&businesscode=%@&isAllowedCallBack=%@&appName=%@",XACAScheme,self.appid,[XACASDK defaultDevice].BusinessType,methodID,self.appid,@"1",[[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"] stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]]];
    
    if (info) {
        NSDictionary *keyvalues = [self dictionaryFromModel:info];
        
        [keyvalues enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
            
            obj = [obj stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];
            
            
            
            NSLog(@"key = %@ value = %@",key,obj);
            
            [urlStr appendFormat:@"&%@=%@",key,obj];
        }];
    }
    
    if (param) {
        [param enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
            obj = [obj stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];
            [urlStr appendFormat:@"&%@=%@",key,obj];
        }];
    }
    
    
    if ([[UIApplication sharedApplication]canOpenURL:[NSURL URLWithString:urlStr]]) {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:urlStr] options:@{} completionHandler:^(BOOL success) {
            NSLog(@"%d",success);
        }];
        
    }else{
        //跳转到appstore
        [[UIApplication sharedApplication]openURL:[NSURL URLWithString:[NSString stringWithFormat:@"http://www.baidu.com?name=%@",@""]] options:@{} completionHandler:^(BOOL success) {
            
        }];
        
    }
    
    [self passResultBlock:feedBlock];
    
    
}

- (BOOL)handleUrl:(NSURL *)url result:(void(^)(XAResultInfo * resultInfo))result{
    NSAssert(url, @"url is nil!");

    //判断urlscheme 如果有匹配
    NSURLComponents *components = [NSURLComponents componentsWithURL:url resolvingAgainstBaseURL:YES];

     //类似支付完成过来的回调  根据相关字段,比如url.host (http:host/)来断定这个回调是不是来自支付的(因为有可能存在其他的回调,比如第三方分享的回调,微信支付的回调)
    if (![components.scheme isEqualToString:@"xacamethod"]) {
        return NO;
    }
    

    /** 3. 获取页面参数 */
    NSMutableDictionary *params = [NSMutableDictionary dictionary];
    /** iOS8.0+
     for (NSURLQueryItem *item in components.queryItems) {
     [params addEntriesFromDictionary:@{item.name: item.value}];
     }
     */
    /** iOS7.0 */
    NSArray *itemStringArray = [components.query componentsSeparatedByString:@"&"];
    for (NSString *itemString in itemStringArray) {
        NSRange range = [itemString rangeOfString:@"="];
        if (range.location != NSNotFound) {
            NSString *key = [itemString substringToIndex:range.location];
            NSString *val = [itemString substringFromIndex:range.location + range.length];
            [params addEntriesFromDictionary:@{key:val}];
        }
    }
    
    //此处可以根据相关参数,向开发者平台服务器请求数据,查看此次调用的处理结果,block返回
    //responseobject 后期更换为 ResultInfo类  返回这个类的实例
    NSAssert(result, @"block is nil");
    XAResultInfo *info = [XAResultInfo new];
    info.resultCode = @"203";
    [info setValuesForKeysWithDictionary:params];
    result(info);
    if ([XACASDK defaultDevice].completedBlock) {
        [XACASDK defaultDevice].completedBlock(info);
    }
    
    
    [[NSNotificationCenter defaultCenter]postNotificationName:XACACALLBACKRESULT object:info];
    
    
    
    
    return YES;
    
}

-(void)jjj{
    NSLog(@"gggg");
}

#pragma mark  用于获取回调的block,传递给对应的算法

- (void)passResultBlock:(void(^)(XAResultInfo * result))block{
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(jjj) name:XACACALLBACKRESULT object:nil];
    
    
    
    [XACASDK defaultDevice].completedBlock = ^(XAResultInfo *info) {
        if (block) {
            block(info);
        }
    };
}



@end
