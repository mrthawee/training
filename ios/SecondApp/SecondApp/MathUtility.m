//
//  MathUtility.m
//  SecondApp
//
//  Created by Thawee Techathamnukool on 1/29/16.
//  Copyright © 2016 Thawee Techathamnukool. All rights reserved.
//

#import "MathUtility.h"

@implementation MathUtility

-(int) timesTen:(int)number {
    NSLog(@"You passed in the value: %i", number);
    return number * 10;
}

-(int) addNumber:(int)a toNumber:(int)b {
    NSLog(@"a=%i b=%i", a, b);
    return a + b;
}

@end
