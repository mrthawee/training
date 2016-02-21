#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "print.hpp"

using namespace std;

int square(int value) {
   return value * value;
}

int main() {
   set<int>  s;
   vector<int> v;

   for (int i=1; i<=9; ++i) {
      s.insert(i);
   }

   PRINT_ELEMENTS(s, "Init: ");

   transform(s.begin(), s.end(),
             back_inserter(v),
             square);

   PRINT_ELEMENTS(v, "squared: ");
}   
