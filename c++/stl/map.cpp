/*
 * map : pair of (key, value)
 * map is sorted by key : no dup keys
 */

#include <iostream>
#include <map>

using namespace std;

int main(void) {

   map<char, int> mymap;

   mymap.insert(pair<char, int>('a', 100));
   mymap.insert(make_pair('z', 100));

   map<char, int>::iterator it = mymap.begin();
   mymap.insert(it, pair<char, int>('b',300));  // 'it' is a hint
   
   it = mymap.find('z');
   cout << (*it).first << " => " << (*it).second << endl;

   pair<map<char,int>::iterator, bool> ret;
   ret = mymap.insert(pair<char, int>('b',400));  // 'b' already exists
   if (ret.second == false) {
      cout << "Error: failed to insert 'b'\n";
      cout << "  'b' already exists with => " << ret.first->second << endl;
   } else
      cout << "Insert 'b' success.\n";

   mymap.insert(it, pair<char, int>('c',400));  // 'b' already exists

   for (it=mymap.begin(); it!=mymap.end(); it++) {
//      cout << (*it).first << " => " << (*it).second << endl;
      cout << it->first << " => " << it->second << endl;
   }

   return 0;
}
