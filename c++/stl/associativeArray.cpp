/*
 * Associative Array
 * - can be implemented using map and unordered map
 *
 * Notes about Associative Array:
 * 1. Search time: unordered_map -> O(1), map -> O(log(n))
 * 2. Unordered_map may degrade to O(n)
 * 3. Can't use multimap and unordered_multimap, they don't have [] operator, 
 *    and both don't have unique key
 *
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main(void) {
   unordered_map<char, string> day = { {'S', "Sunday"}, {'M', "Monday"} };

   cout << day['S'] << endl;   // no range check
   cout << day.at('S') << endl;  // has range check

   vector<int> vec = { 1, 2, 3 };
   vec[1] = 5;   // ok
   //vec[5] = 5;   // compiler error
   for (auto it: vec)
      cout << it << " ";
   cout << endl;

   day['W'] = "Wednesday";  // insert {'W', "Wednesday"}
   day.insert(make_pair('F', "Friday"));  // insert {'F', "Friday"}

   //day.insert(make_pair('M', "MONDAY"));  // failed, can't modify unordered_map
   day['M'] = "MONDAY";  // OK, change 'Monday' to 'MONDAY'

   for (int i=0; i<day.bucket_count(); i++) {
      cout << "bucket #" << i << " contains: ";
      for (auto l_it=day.begin(i); l_it!=day.end(i); ++l_it) {
         cout << l_it->first << " => " << l_it->second << ", ";
      }
      cout << endl;
   }

   return 0;
}
