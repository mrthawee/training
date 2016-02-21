#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
   list<int> l;
   vector<int> v;

   for (int i=1; i<=9; ++i) {
      l.push_back(i);
   }

//   list<int>::iterator x;
   cout << "list: ";
   for (auto x: l)
      cout << x << ' ';
   cout << endl;

   // resize v so it is large enough to be copied over
   v.resize(l.size());
   copy (l.begin(), l.end(),
         v.begin() );
   
   cout << "vector: ";
   for (auto x: v)
      cout << x << ' ';
   cout << endl;

   deque<int> d(v.size());
   copy(v.begin(), v.end(),
        d.begin() );
   
   cout << "deque: ";
   for (auto x: d)
      cout << x << ' ';
   cout << endl;
}
