/*
 * unordered multiset : unordered set that allows dup elements
 * unordered map: unordered set of pairs
 * unordered multimap: unordered map that allows dup keys
 *
 * hash collision => performance degrade
 *
 * Properties of unordered containers:
 * 1. Fastest search/insert at any place: O(1)
 *      Associate Containter takes O(log(n))
 *      vector, deque takes O(n)
 *      list, takes O(1) to insert and O(n) to search
 * 2. Unordered set/multiset: element value cannot be changed
 *    Unordered map/multimap: element key cannot be changed
 *
 */
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

int main(void) {
   unordered_set<string> myset = { "red", "green", "blue" };
   unordered_set<string>::const_iterator itr = myset.find("green");  // O(1)
   if (itr != myset.end()) // important check
      cout << *itr << endl;

   pair<unordered_set<string>::iterator, bool> ret;

   ret = myset.insert("yellow"); // O(1)
   if (ret.second == false) {
      cout << "Error: insert 'yellow' failed!\n";
   } else {
      cout << "Insert 'yellow' success.\n";
   }

   vector<string> vec = { "purple", "pink" };
   myset.insert(vec.begin(), vec.end());
   /*
   ret = myset.insert(vec.begin(), vec.end());
   if (ret.second == false) {
      cout << "Error: insert 'vec' failed!\n";
   } else {
      cout << "Insert 'vec' success.\n";
   }
   */

   cout << "myset contains: ";
   //for (auto it=myset.begin(); it!=myset.end(); ++it)
   for (unordered_set<string>::iterator it=myset.begin(); it!=myset.end(); ++it)
      cout << *it << " ";
   cout << endl;

   for (int i=0; i<myset.bucket_count(); ++i) {
      cout << "bucket #" << i << " contains: ";
      for (auto l_it = myset.begin(i); l_it!=myset.end(i); l_it++) {
         cout << *l_it << " ";
       }
       cout << endl;
   }

   // hash table specific APIs:
   cout << "load_factor = " << myset.load_factor() << endl;
   string x = "red";
   cout << x << " is in bucket #" << myset.bucket(x) << endl;
   cout << "Total bucket #" << myset.bucket_count() << endl;

   return 0;
}
