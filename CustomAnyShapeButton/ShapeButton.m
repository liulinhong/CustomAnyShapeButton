//
//  ShapeButton.m
//
//  Created by LiuLinhong on 15/12/17.
//  Copyright (c) 2015年 刘琳鸿. All rights reserved.
//

#import "ShapeButton.h"

@interface ShapeButton ()
{
    UIBezierPath *path;
}
@end

@implementation ShapeButton

- (id)initWithAnyShapeButton
{
//    self.layer.delegate  = self;
    self = [self initWithFrame:CGRectMake(120, 120, 120, 120)];
    
    path = [UIBezierPath bezierPath];
    [path moveToPoint:CGPointMake(10, 50)];
    [path addArcWithCenter:CGPointMake(50, 50) radius:40 startAngle:-M_PI endAngle:0 clockwise:YES];
    [path addArcWithCenter:CGPointMake(70, 50) radius:20 startAngle:0 endAngle:M_PI clockwise:YES];
    [path addArcWithCenter:CGPointMake(30, 50) radius:20 startAngle:0 endAngle:-M_PI clockwise:NO];
//    [path addLineToPoint:CGPointMake(60, 20)];
    
    [path closePath];
    [self setShape:path.CGPath];
    
    return self;
}

// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSaveGState(ctx);
    
    CGContextMoveToPoint(ctx, 10, 50);
    CGContextAddArc(ctx, 50, 50, 40, -M_PI, 0, 0);
    CGContextAddArc(ctx, 70, 50, 20, 0, M_PI, 0);
    CGContextAddArc(ctx, 30, 50, 20, 0, -M_PI, 1);
    //    CGContextAddLineToPoint(ctx, 114, 4);
    
    CGContextSetFillColorWithColor(ctx, [UIColor greenColor].CGColor);
    //    UIColor *shadowColor = [UIColor colorWithRed:0.0/255.0 green:0.0/255.0 blue:0.0/255.0 alpha:0.2];
    //    CGContextSetShadowWithColor(ctx,CGSizeMake(1.0f, -1.0f), 4.0f, shadowColor.CGColor);
    
    CGContextFillPath(ctx);
    CGContextRestoreGState(ctx);
    
    //添加一根细线区分上下边界
    /*
     CGContextRef context = UIGraphicsGetCurrentContext();
     CGContextMoveToPoint(context, 0, 58);
     CGContextAddLineToPoint(context, [[UIScreen mainScreen] bounds].size.width, 58);
     CGContextSetRGBStrokeColor (context, 215.0/255.0, 215.0/255.0, 215.0/255.0, 1.0);
     CGContextSetLineWidth(context, 1);
     CGContextClosePath(context);
     CGContextStrokePath(context);
     */
}

- (void)setShape:(CGPathRef)shape
{
    [super setShape:shape];
}

- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event
{
    if (CGPathIsEmpty(path.CGPath))
        return YES;
    
    //判断触发点是否在规定的 Shape 内
    if (CGPathContainsPoint(path.CGPath, nil, point, nil))
        return YES;
    else
        return NO;
}

@end
