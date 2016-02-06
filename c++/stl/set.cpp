#include <iostream>
#include <set>

using namespace std;

/*
 * Set - No duplicates binary tree
 */

void PrintSet(set<int> s) {
   for (set<int>::iterator itr=s.begin(); itr!=s.end(); itr++)
      cout << *itr << " ";
   cout << endl;
}

int main() {
   set<int> myset;
   myset.insert(3);   // myset: { 3 }
   myset.insert(1);   // myset: { 1, 3 }
   myset.insert(7);   // myset: { 1, 3, 7 }

   PrintSet(myset);

   /*
   for (set<int>::iterator itr=myset.begin(); itr!=myset.end(); itr++)
      cout << *itr << " ";
   cout << endl;
   */

   set<int>::iterator it;
   it = myset.find(7);  // search with O(n), it points to 7

   // *it = 5; compilation error! can't update the key value directly

   pair<set<int>::iterator, bool> ret;
   // .insert() returns a pair(first=value, second = true/false)
   ret = myset.insert(3);  // can't be inserted - 3 already exists
   if (ret.second == false)
      it = ret.first;      // it points to 3

   myset.insert(it, 9);  // myset: { 1, 3, 7, 9 } with it to helps finding where to be inserted -> possibly faster
   PrintSet(myset);
   
   myset.erase(it);      // myset: { 1, 7, 9 }
   PrintSet(myset);

   myset.erase(7);       // myset: { 1, 9 }
   PrintSet(myset);

   return 0;
}
