#include <iostream>

using namespace std;

int main(void) {
   int a = 0b01010101;
   int b = 0b10101010;

   int c = a | b;

   cout << c << endl;
//   cout << a | 0x1010 << endl; // c++14, but g++ can't compile

   return 0;
}
