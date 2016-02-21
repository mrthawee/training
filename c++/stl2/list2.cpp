#include <iostream>
#include <list>

using namespace std;

int main() {
   list<char> l;
   
   for (char c='a'; c<='z'; ++c) {
      l.push_back(c);
   }

   list<char>::const_iterator pos;
   for (pos = l.begin(); pos != l.end(); ++pos) {
      cout << *pos << ' ';
   }
   cout << endl;


   list<int*> ll;
   int a = 5, b = 10, c = 15;
   int *aPtr = &a;
   int *bPtr = &b;
   int *cPtr = &c;
   ll.push_back(aPtr);
   ll.push_back(bPtr);
   ll.push_back(cPtr);

   list<int*>::iterator itr;
   for (itr = ll.begin(); itr != ll.end(); ++itr) {
      cout << **itr << ' ';
   }
   cout << endl;
}
