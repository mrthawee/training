#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
   vector<int> v;
   vector<int>::iterator itr;

   v.push_back(2);
   v.push_back(5);
   v.push_back(4);
   v.push_back(1);
   v.push_back(6);
   v.push_back(3);


   itr = min_element(v.begin(), v.end());
   cout << "min: " << *itr << endl;
   itr = max_element(v.begin(), v.end());
   cout << "max: " << *itr << endl;

   sort(v.begin(), v.end());
   cout << "sort: ";
   for (auto x: v)  // need -std=c++11
      cout << x << ' ';
   cout << endl;

   cout << "find pos of 3, then reverse from there to the end: ";
   itr = find(v.begin(), v.end(), 3);
   reverse(itr, v.end());  // reverse part of the vector

   for (itr=v.begin(); itr!=v.end(); ++itr) {
      cout << *itr << ' ';
   }
   cout << endl;
}
