//
//  Employee.h
//  SecondApp
//
//  Created by Thawee Techathamnukool on 1/29/16.
//  Copyright © 2016 Thawee Techathamnukool. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Employee : NSObject

@property NSString *name;
@property NSDate *hireDate;
@property int employeeNumber;

- (void) someMethod;  // '-' for instance method '+' for class method
/*
- (int) timesTen:(int) num;  // arg is 'int num' and returne 'int'
- (NSString *) createMessage: (NSString *) input;
- (int) addNumber:(int) a toNumber:(int) b;
*/

@end
