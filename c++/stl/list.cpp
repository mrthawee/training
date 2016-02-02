// List : doubly linked list
/* Properties of List:
 * 1. fast insert/remove at any place in the list: O(1)
 * 2. slow search: O(n)
 * 3. no direct access, no [] operator
 */

#include <iostream>
#include <list>

using namespace std;

void dump(list<int> l) {
   cout << "list: ";
   for (auto it: l)
      cout << it << " ";
   cout << endl;
}

int main(void) {
   list<int> mylist; //  = { 5,2,9 };
   mylist.push_back(5);
   dump(mylist);
   mylist.push_back(2);
   dump(mylist);
   mylist.push_back(9);
   dump(mylist);
   mylist.push_back(6); // mylist: { 5,2,9,6 }
   dump(mylist);
   mylist.push_front(4); // mylist: { 4,5,2,9,6 }
   dump(mylist);

   list<int>::iterator itr = find(mylist.begin(), mylist.end(), 2); // itr -> 2
   mylist.insert(itr,8); // mylist : {4,5,8,2,9,6 }
                         // O(1), faster than vector/deque
   dump(mylist);
   itr++; // itr -> 9
   mylist.erase(itr);    // mylist : {4,8,5,2,6} : O(1)
   dump(mylist);

   for (list<int>::iterator itr=mylist.begin(); itr!=mylist.end(); ++itr)
      cout << *itr << " ";
   cout << endl;

   return 0;
}

