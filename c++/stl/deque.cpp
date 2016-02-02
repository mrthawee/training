/*
 * Diff from Deque: grow both begin and end, but vect only at the end
 * Properties of Deque:
 * 1. fast insert/remove at the begining and the end
 * 2. slow insert/remove in the middle: O(n)
 * 3. slow search: O(n)
 */
#include <iostream>
#include <deque>

using namespace std;

void dump(deque<int> d) {
   cout << "deq: ";
   for (auto it: d)
      cout << it << " ";
   cout << endl;
}

int main(void) {
   deque<int> deq;  // = { 4,6,7 };
   deq.push_front(4);
   dump(deq);
   deq.push_back(6);
   dump(deq);
   deq.push_back(7);
   dump(deq);
   deq.push_front(2);  // deq: { 2,4,6,7 }
   dump(deq);
   deq.push_back(3);   // deq: { 2,4,6,7,3 }
   dump(deq);

   // Deque has similar interface to vector
   cout << deq[1] << endl;;     // 4

/*
   for (auto it: deq)  // c++ 11
      cout << it << " ";
   cout << endl;
*/
   for (deque<int>::iterator itr=deq.begin(); itr!=deq.end(); ++itr)
      cout << *itr << " ";
   cout << endl;

}
