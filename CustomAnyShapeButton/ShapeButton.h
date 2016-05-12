//
//  ShapeButton.h
//
//  Created by LiuLinhong on 15/12/17.
//  Copyright (c) 2015年 刘琳鸿. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIView+Shape.h"

@interface ShapeButton : UIButton

//left: YES   Right: NO
//@property (nonatomic, assign) BOOL leftOrRight;
//@property (nonatomic, assign) BOOL leftSelected;
//@property (nonatomic, assign) BOOL rightSelected;
//@property (nonatomic, assign) NSInteger deviceType;
@property (nonatomic, strong) UILabel *customizeTitleLabel;
@property (nonatomic, strong) CALayer *dotTipLayer;

- (id)initWithAnyShapeButton;


@end
