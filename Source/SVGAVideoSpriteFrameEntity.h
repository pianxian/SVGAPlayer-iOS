//
//  SVGAVideoSpriteFrameEntity.h
//  SVGAPlayer
//
//  Created by 崔明辉 on 2017/2/20.
//  Copyright © 2017年 UED Center. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Svga.pbobjc.h"
@class SVGAVectorLayer;
//@class SVGAProtoFrameEntity;

@interface SVGAVideoSpriteFrameEntity : NSObject

@property (nonatomic, readonly) CGFloat alpha;
@property (nonatomic, assign) CGAffineTransform transform;
@property (nonatomic, readonly) CGRect layout;
@property (nonatomic, readonly) CGFloat nx;
@property (nonatomic, readonly) CGFloat ny;
@property (nonatomic, readonly) CALayer *maskLayer;
@property (nonatomic, readonly) NSArray *shapes;

@property (nonatomic,strong) SVGAProtoFrameEntity *protoObject;

- (instancetype)initWithJSONObject:(NSDictionary *)JSONObject;
- (instancetype)initWithProtoObject:(SVGAProtoFrameEntity *)protoObject;
-(void)resetLayout;
@end
