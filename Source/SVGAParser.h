//
//  SVGAParser.h
//  SVGAPlayer
//
//  Created by 崔明辉 on 16/6/17.
//  Copyright © 2016年 UED Center. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SVGAVideoEntity.h"

@class SVGAVideoEntity;

@interface SVGAParser : NSObject

@property (nonatomic, assign) BOOL enabledMemoryCache;

- (void)parseWithURL:(nonnull NSURL *)URL
     completionBlock:(void ( ^ _Nonnull )(SVGAVideoEntity * _Nullable videoItem,NSData * _Nullable data))completionBlock
        failureBlock:(void ( ^ _Nullable)(NSError * _Nullable error))failureBlock;


- (void)parseWithURLRequest:(NSURLRequest *_Nullable)URLRequest
            completionBlock:(void (^_Nonnull)(SVGAVideoEntity * _Nullable videoItem,NSData  * _Nullable  data))completionBlock failureBlock:(void (^_Nullable)(NSError * _Nullable))failureBlock;

- (void)parseWithCacheKey:(nonnull NSString *)cacheKey
          completionBlock:(void ( ^ _Nonnull)(SVGAVideoEntity * _Nonnull videoItem))completionBlock
             failureBlock:(void ( ^ _Nullable)(NSError * _Nonnull error))failureBlock;

- (void)parseWithNamed:(NSString *_Nullable)named
              inBundle:(NSBundle *_Nullable)inBundle
       completionBlock:(void (^_Nonnull)(SVGAVideoEntity * _Nonnull videoItem))completionBlock
          failureBlock:(void (^_Nullable)(NSError * _Nonnull error))failureBlock;


- (void)parseWithURL:(nonnull NSURL *)URL
              Kernel:(nullable CIColorKernel *)kenel
              metalColorInfo:(metalColorInfo)metalColorInfo
     completionBlock:(void ( ^ _Nonnull )(SVGAVideoEntity * _Nullable videoItem,NSData * _Nullable data))completionBlock
        failureBlock:(void ( ^ _Nullable)(NSError * _Nullable error))failureBlock;

- (void)parseWithURLRequest:(NSURLRequest *_Nullable)URLRequest
                     Kernel:(nullable CIColorKernel *)kenel
                     metalColorInfo:(metalColorInfo)metalColorInfo
            completionBlock:(void (^_Nonnull)(SVGAVideoEntity * _Nullable videoItem,NSData  * _Nullable  data))completionBlock failureBlock:(void (^_Nullable)(NSError * _Nullable))failureBlock;

- (void)parseWithCacheKey:(nonnull NSString *)cacheKey
                   Kernel:(nullable CIColorKernel *)kenel
                   metalColorInfo:(metalColorInfo)metalColorInfo
          completionBlock:(void ( ^ _Nonnull)(SVGAVideoEntity * _Nonnull videoItem))completionBlock
             failureBlock:(void ( ^ _Nullable)(NSError * _Nonnull error))failureBlock;

- (void)parseWithNamed:(NSString *_Nullable)named
              inBundle:(NSBundle *_Nullable)inBundle
                Kernel:(nullable CIColorKernel *)kenel
                metalColorInfo:(metalColorInfo)metalColorInfo
       completionBlock:(void (^_Nonnull)(SVGAVideoEntity * _Nonnull videoItem))completionBlock
          failureBlock:(void (^_Nullable)(NSError * _Nonnull error))failureBlock;
- (void)parseWithData:(nonnull NSData *)data
             cacheKey:(nonnull NSString *)cacheKey
               Kernel:(nullable CIColorKernel *)kenel
       metalColorInfo:(metalColorInfo)metalColorInfo
      completionBlock:(void ( ^ _Nonnull)(SVGAVideoEntity * _Nonnull videoItem))completionBlock
         failureBlock:(void ( ^ _Nullable)(NSError * _Nonnull error))failureBlock;

- (void)parseWithData:(nonnull NSData *)data
             cacheKey:(nonnull NSString *)cacheKey
      completionBlock:(void ( ^ _Nonnull)(SVGAVideoEntity * _Nonnull videoItem))completionBlock
         failureBlock:(void ( ^ _Nullable)(NSError * _Nonnull error))failureBlock;
@end
