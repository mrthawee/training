/* 
 * Properties of Vector:
 * 1. fast insert/remove at the end: O(1)
 * 2. slow insert/remove at the begining or in the middle: O(n)
 * 3. slow search: O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
   vector<int> vec;  // vec.size() == 0
   vec.push_back(4);
   vec.push_back(1);
   vec.push_back(8); // vec: {4, 1, 8};  vec.size() == 3

   cout << vec[2] << endl;    // no range check
   cout << vec.at(2) << endl; // throw range_error exception of out of range

   for (int i; i<vec.size(); i++)  // can be done, but not the right way
      cout << vec[i] << " ";
   cout << endl;

   // the right way to access
   // 1. faster than random  access
   // 2. same syntax for other containers such as deque, list
   for (vector<int>::iterator itr=vec.begin(); itr!=vec.end(); ++itr)
      cout << *itr << " ";
   cout << endl;

   //for (it: vec)  // c++ 11
   /*
   for (auto it: vec)  // c++ 11
      cout << it << " ";
   cout << endl;
   */

   // vector is a dynamically allocated contiguous array in memory
   int* p = &vec[0]; 
   p[1] = 6;
   for (vector<int>::iterator itr=vec.begin(); itr!=vec.end(); ++itr)
      cout << *itr << " ";
   cout << endl;

   // common member functions of all containers
   // vec: {4, 1, 8}
   if (vec.empty()) 
      cout << "Not possible.\n";
   else 
      cout << "yes, I am empty\n";

   cout << vec.size();  // 3
   vector<int> vec2(vec);  // copy constructor, vec2: {4, 1, 8}
   vec.clear();  // remove all items in vec;  vec.size() == 0
   vec2.swap(vec);  // vec2 becomes empty and vec has 3 items

//   vector<int>::iterator itr1 = vec.begin();  // half-open: [begin, end)
//   vector<int>::iterator itr2 = vec.end();  // cout << *vec.end(); -> invalid!

//   sort(itr1, itr2);
//   for (vector<int>::iterator itr = itr1; itr != vec.end(); ++itr)
//      cout << *itr << " "; // Print out: 4 1 8
}
