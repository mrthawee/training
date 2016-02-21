#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
   list<int> l;
   vector<int> v;

   for (int i=1; i<=9; ++i) {
      l.push_back(i);
   }

   // core dump! : v doesn't have enough space 
   // see copy2.cpp for the right way to do this
   copy (l.begin(), l.end(),
         v.begin() );
}
