//
//  ViewController.m
//  CustomAnyShapeButton
//
//  Created by LiuLinhong on 16/5/12.
//  Copyright © 2016年 LiuLinhong. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
{
    ShapeButton *shapeButton;
}
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    shapeButton = [[ShapeButton alloc] initWithAnyShapeButton];
    [shapeButton addTarget:self action:@selector(shapeButtonPressed) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:shapeButton];
}

- (void)shapeButtonPressed
{
    NSLog(@"LLH...... Shape Button Pressed");
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

@end
