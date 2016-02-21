#include <iostream>

using namespace std;

template<typename T>
T min(T &a, T &b) {
   return (a < b) ? a : b;
}

int main() {
   int i = 5, j = 10;
   char a='a', z='z';

   cout << min(i,j) << endl;
   cout << min(z,a) << endl;
}
