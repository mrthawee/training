#include <iostream>

using namespace std;

/*
int square(int x) {
   return x * x;
}

double square(double x) {
   return x * x;
}
*/

template <typename T>
T square(T x) {
   return x * x;
}

int main(void) {
   cout << square<int>(5) << endl;
   cout << square<double>(5.5) << endl;
   cout << square(5) << endl;   // don't have to tell type in function template
   cout << square(5.5) << endl; // don't have to tell type in function template
}
