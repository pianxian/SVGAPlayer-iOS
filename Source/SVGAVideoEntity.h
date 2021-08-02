//
//  SVGAVideoEntity.h
//  SVGAPlayer
//
//  Created by 崔明辉 on 16/6/17.
//  Copyright © 2016年 UED Center. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
typedef struct metalColorInfo{
    CGFloat r;
    CGFloat g;
    CGFloat b;
    CGFloat a;
    
}metalColorInfo;

@class SVGAVideoEntity, SVGAVideoSpriteEntity, SVGAVideoSpriteFrameEntity, SVGABitmapLayer, SVGAVectorLayer, SVGAAudioEntity;
@class SVGAProtoMovieEntity;

@interface SVGAVideoEntity : NSObject

@property (nonatomic, readonly) CGSize videoSize;
@property (nonatomic, readonly) int FPS;
@property (nonatomic, readonly) int frames;
@property (nonatomic, readonly) NSDictionary<NSString *, UIImage *> *images;
@property (nonatomic, readonly) NSDictionary<NSString *, NSData *> *audiosData;
@property (nonatomic, readonly) NSArray<SVGAVideoSpriteEntity *> *sprites;
@property (nonatomic, readonly) NSArray<SVGAAudioEntity *> *audios;

- (instancetype)initWithJSONObject:(NSDictionary *)JSONObject cacheDir:(NSString *)cacheDir;
- (void)resetImagesWithJSONObject:(NSDictionary *)JSONObject;
- (void)resetSpritesWithJSONObject:(NSDictionary *)JSONObject;

- (instancetype)initWithProtoObject:(SVGAProtoMovieEntity *)protoObject cacheDir:(NSString *)cacheDir;

/// 解压图片
/// @param protoObject protoObject description
/// @param mirrorEnable 是否需要镜像翻转
- (void)resetImagesWithProtoObject:(SVGAProtoMovieEntity *)protoObject mirrorEnable:(BOOL)mirrorEnable;
- (void)resetSpritesWithProtoObject:(SVGAProtoMovieEntity *)protoObject;
- (void)resetAudiosWithProtoObject:(SVGAProtoMovieEntity *)protoObject;

/// 携带 Metal 滤镜方法
/// @param protoObject protoObject description
/// @param kernel metal kernel 对象
/// @param metalColorInfo 颜色
/// @param mirrorEnable 是否需要镜像
- (void)resetImagesWithProtoObject:(SVGAProtoMovieEntity *)protoObject
                            kernel:(CIColorKernel *)kernel
                    metalColorInfo:(metalColorInfo)metalColorInfo
                      mirrorEnable:(BOOL)mirrorEnable;

- (void)resetImagesWithJSONObject:(NSDictionary *)JSONObject kernel:(CIColorKernel *)kernel metalColorInfo:(metalColorInfo)metalColorInfo;
+ (SVGAVideoEntity *)readCache:(NSString *)cacheKey;
// NSCache缓存
- (void)saveCache:(NSString *)cacheKey;
// NSMapTable弱缓存
- (void)saveWeakCache:(NSString *)cacheKey;
@end


