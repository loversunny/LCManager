//
//  NSObject+LCCategory.h
//  XACASampleDemo
//
//  Created by jlc on 2017/6/7.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (LCCategory)

/**
 每一个方法添加一个特定的标识符
 */
//@property(nonatomic,strong) NSMutableArray * identifiers;



/**
 字典转化为model
 
 @param parmaters 字典 参数
 */
- (void)modelFromIdctionary:(NSDictionary *)parmaters;


/**
 model类转字典
 
 @param model model类
 @return 转化为字典类型
 */
- (id)dictionaryFromModel:(id)model;

/**
 获取类名
 
 @return 类名
 */
- (NSString *)getClassName;


/**
 获取方法名字
 
 @return 全部方法名
 */
- (NSArray *)allClassMethods;



/**
 获取当前被调用的方法

 @return 方法名字
 */
-(NSString *)currentMethodName;

/**
 为操作添加唯一标识符
 @param identifier 标识符
 @return 标识符
 */
- (NSString *)registIdentifierForMethod:(NSString *)identifier;

/**
 取消当前方法标识符
 */
-(void)deregisterIdent;



/**
 获取当前方法的标识符

 @return 标识符
 */
-(NSString *)currentMethodIdentifier;


@end
