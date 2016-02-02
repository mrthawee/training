//
//  main.m
//  SecondApp
//
//  Created by Thawee Techathamnukool on 1/28/16.
//  Copyright © 2016 Thawee Techathamnukool. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Employee.h"
#import "MathUtility.h"

void myFunction() {
    NSLog(@"In myFunction()");
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        int x = 45;
        NSLog(@"x=%d",x);
        
        int mins = 60;
        int hours = 24;
        int n = 2;
        NSLog(@"There are %i minutes in a day", mins*hours);
        NSLog(@"%i mins in %i days", n*mins*hours, n);
        
        int arithematic = 5 + 5 * 10;
        NSLog(@"arithematic operations are like C 5 + 5 * 10 = %i", arithematic);
        int a = 5;
        NSLog(@"a=5; ++a = %i", ++a);
        
        NSLog(@"if-else including ternary ( condition? true : false ) and switch are like C");
        
        for (int a=0; a<5; a++) {
            (a%2 == 0) ? NSLog(@"a is even") : NSLog(@"a is odd");
            NSLog(@"a=%d",a);
        }
        
        while (a<8) {
            a++;
        }
        NSLog(@"a=%i",a);
        
        myFunction(); // calling a function - like C
        
        NSDate *x2;
        x2 = [NSDate alloc];
        x2 = [x2 init];
        //NSDate *x2 = [[NSDate alloc]init];
        
        NSLog(@"date = %@",x2);
        
        NSDate *nextDate = [[NSDate alloc] initWithTimeIntervalSince1970:23234544];
        NSDate *anotherDate = [NSDate date];  // same as [[NSDate allo]init], obj-c style
        NSDate *yetAnotherDate = [NSDate dateWithTimeIntervalSince1970:23234544];
        
        NSLog(@"nextDate = %@",nextDate);
        NSLog(@"anotherDate = %@", anotherDate);
        NSLog(@"yetAnotherDate = %@", yetAnotherDate);
        
        NSString *msg = @"Hello";
        NSString *nextMsg = [[NSString alloc]initWithFormat:@"The word is: %@", msg]; // old style from next step
        NSString *anotherMsg = [NSString stringWithFormat:@"The word is: %@", msg];  // obj-c style
        
        // create an object of class Employee
        Employee *fred = [[Employee alloc] init];
        
        // call a method of our new object
        [fred someMethod];
        
        // change a property of our new object
        [fred setName:@"Fred Smith"];
        
        MathUtility *util = [[MathUtility alloc] init];
        
        int result = [util timesTen:55];
        NSLog(@"The result of timesTen: %i", result);
        
        result = [util addNumber:99 toNumber:4];
        NSLog(@"The result of addNumber: %i", result);
    }
    return 0;
}
