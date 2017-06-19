//
//  NSObject+LCCategory.m
//  XACASampleDemo
//
//  Created by jlc on 2017/6/7.
//  Copyright © 2017年 河南省信息化有限公司. All rights reserved.
//

#import "NSObject+LCCategory.h"
#import <objc/runtime.h>


@interface NSObject ()

@property(nonatomic,strong) NSMutableDictionary * identDict;

@end


@implementation NSObject (LCCategory)

/**
 字典转化为model
 
 @param parmaters 字典 参数
 */
- (void)modelFromIdctionary:(NSDictionary *)parmaters{
    [self setValuesForKeysWithDictionary:parmaters];
}

-(id)dictionaryFromModel:(id)model{
    
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    unsigned int count = 0;
    objc_property_t *properties = class_copyPropertyList([model class], &count);
    for (int i = 0; i < count; i ++) {
        const char *name = property_getName(properties[i]);
        NSString *propertyName = [NSString stringWithUTF8String:name];
        id propertyValue = [model valueForKey:propertyName];
        if (propertyValue) {
            [dict setObject:propertyValue forKey:propertyName];
        }
    }
    free(properties);
    
    return dict;
}


-(NSString *)getClassName{
    
    const char *name = object_getClassName(self);
    
    return [NSString stringWithUTF8String:name];
}


-(NSArray *)allClassMethods{
    NSMutableArray *array = [NSMutableArray array];
    uint count;
    Method *methods = class_copyMethodList([self class], &count);
    for (uint i = 0; i < count; i ++) {
        Method method = methods[i];
        SEL sel = method_getName(method);
        [array addObject:NSStringFromSelector(sel)];
    }
    
    return array;
}

-(NSArray *)identifiers{
    
    return nil;
}



-(NSString *)currentMethodName{
    
    return NSStringFromSelector(_cmd);
    
}


/**
 为操作添加唯一标识符
 @param identifier 标识符
 @return 标识符
 */
- (NSString *)registIdentifierForMethod:(NSString *)identifier{
    
    //防止多次注册
//    if (!self.identDict[[self currentMethodName]]) {
//        [self.identDict setObject:identifier forKey:[self currentMethodName]];
        return identifier;
//    }else{
//        return self.identDict[[self currentMethodName]];
//    }
}

/**
 取消当前方法标识符
 */
-(void)deregisterIdent{
   self.identDict[[self currentMethodName]] = nil;
}

/**
 获取当前方法的标识符
 
 @return 标识符
 */
-(NSString *)currentMethodIdentifier{
    
    return self.identDict[[self currentMethodName]];
}


@end
