//
//  UIView+Shape.m
//  Pangjiaoya_sences
//
//  Created by LiuLinhong on 14/11/7.
//  Copyright (c) 2014年 刘琳鸿. All rights reserved.
//

#import "UIView+Shape.h"

@implementation UIView (Shape)


- (void)setShape:(CGPathRef)shape
{
    if (shape == nil)
        self.layer.mask = nil;
    
    CAShapeLayer* maskLayer = [CAShapeLayer layer];
    maskLayer.path = shape;
    self.layer.mask = maskLayer;
}


@end
