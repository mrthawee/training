#include <iostream>
#include <set>

using namespace std;

int main() {
   set<int> s;

   s.insert(3);
   s.insert(1);
   s.insert(5);
   s.insert(4);
   s.insert(1);  // won't be inserted because it is a dup one
   s.insert(6);
   s.insert(2);

   set<int>::const_iterator pos;
   for (pos = s.begin(); pos != s.end(); ++pos) {
      cout << *pos << ' ';
   }
   cout << endl;
}
