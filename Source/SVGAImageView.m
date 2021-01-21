//
//  SVGAImageView.m
//  SVGAPlayer
//
//  Created by 崔明辉 on 2017/10/17.
//  Copyright © 2017年 UED Center. All rights reserved.
//

#import "SVGAImageView.h"
#import "SVGAParser.h"
#import "SVGAVideoEntity.h"
static SVGAParser *sharedParser;

@implementation SVGAImageView

+ (void)load {
    sharedParser = [SVGAParser new];
}

- (instancetype)initWithCoder:(NSCoder *)coder
{
    self = [super initWithCoder:coder];
    if (self) {
        _autoPlay = YES;
    }
    return self;
}

- (void)setImageName:(NSString *)imageName {
    _imageName = imageName;
    if ([imageName hasPrefix:@"http://"] || [imageName hasPrefix:@"https://"]) {
//        metalColorInfo info = {1,1,1,1};
        [sharedParser parseWithURL:[NSURL URLWithString:imageName]  completionBlock:^(SVGAVideoEntity * _Nullable videoItem, NSData * _Nullable data) {
            [self setVideoItem:videoItem];
            if (self.autoPlay) {
                [self startAnimation];
            }
        } failureBlock:^(NSError * _Nullable error) {
            
        }];
//        [sharedParser parseWithURL:[NSURL URLWithString:imageName] completionBlock:^(SVGAVideoEntity * _Nullable videoItem,NSData *_Nullable data) {
//            [self setVideoItem:videoItem];
//            if (self.autoPlay) {
//                [self startAnimation];
//            }
//        } failureBlock:nil];
    }
    else {
        [sharedParser parseWithNamed:imageName inBundle:nil completionBlock:^(SVGAVideoEntity * _Nonnull videoItem) {
            [self setVideoItem:videoItem];
            if (self.autoPlay) {
                [self startAnimation];
            }
        } failureBlock:nil];
  
    }
}

@end
