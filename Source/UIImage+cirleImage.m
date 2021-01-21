//
//  UIImage+cirleImage.m
//  SVGAPlayer
//
//  Created by 胡伟伟 on 2020/9/29.
//

#import "UIImage+cirleImage.h"

@implementation UIImage (cirleImage)
-(UIImage *)mq_cireImage {
    UIGraphicsBeginImageContextWithOptions(self.size, NO, 0.0);
    CGContextRef ref = UIGraphicsGetCurrentContext();
    CGRect rect = CGRectMake(0, 0, self.size.width, self.size.width);
    CGContextAddEllipseInRect(ref, rect);
    CGContextClip(ref);
    [self drawInRect:rect];
    UIImage * image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}
- (UIImage *)mq_cireImageWithRadius:(CGFloat)radius
{
    int w = self.size.width * self.scale;
    int h = self.size.height * self.scale;
    CGRect rect = CGRectMake(0, 0, w, h);
    //使用贝塞尔
    UIGraphicsBeginImageContextWithOptions(CGSizeMake(w, h), false, 1.0);
    [[UIBezierPath bezierPathWithRoundedRect:rect cornerRadius:radius] addClip];
    [self drawInRect:rect];
    UIImage *ret = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return ret;
}
@end
