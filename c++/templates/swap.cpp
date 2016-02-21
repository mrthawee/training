#include <iostream>

using namespace std;

template<typename T>
void mySwap(T &a, T &b) {
   T tmp;
   tmp = a;
   a = b;
   b = tmp;
}

void mySwap(char &a, char &b) {
   cout << "Override the template generated one with my own version\n";
   char tmp;
   tmp = a;
   a = b;
   b = tmp;
}


int main() {
   int i = 10, j = 20;
   float x = 10.1, y = 23.3;
   char a = 'a', b = 'b';

   cout << "i=" << i << "   j=" << j << endl;
   cout << "x=" << x << "   y=" << y << endl;
   cout << "a=" << a << "   b=" << b << endl;

   cout << "now calling mySwap()\n";
   mySwap(i, j);
   mySwap(x, y);
   mySwap(a, b);

   cout << "i=" << i << "   j=" << j << endl;
   cout << "x=" << x << "   y=" << y << endl;
   cout << "a=" << a << "   b=" << b << endl;
}
