#include <iostream>

using namespace std;

int g = 0;

/*
This function can't be included into this code. Compiler Error!
void f(int x, int y) {
   cout << "x=" << x << ", y=" << y << endl;
}
*/

// default arguments can be either
// 1. constants
// 2. global variables 
void f(int a=g, int b=0) {
   cout << "a=" << a << ", b=" << b << endl;
}

int main() {
   f();
   f(10);
   f(20, 99);
   g=25; // update global variable value
   f();  // default value of a is now 25

   return 0;
}
