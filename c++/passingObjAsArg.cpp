#include <iostream>
#include <stdlib.h>

using namespace std;

class dyna {
   private:
      int* p;

   public:
      dyna(int i);
      dyna(const dyna &obj); // copy constructor
      //dyna(dyna &obj); // copy constructor
      ~dyna() { free(p); cout << " freeing\n"; }
      int get() { return *p; }
};

dyna::dyna(int i) {
   cout << "constructor i=" << i << endl;
   p = (int*)malloc(sizeof(int));
   if (!p) {
      cout << "malloc() failed!\n";
      exit(1);
   }

   *p = i;
}

dyna::dyna(const dyna &obj) {
//dyna::dyna(dyna &obj) {
   cout << "copy constructor obj.p=" << obj.p << " *(obj.p)= " << *(obj.p) << endl;
   p = (int*)malloc(sizeof(int));
   if (!p) {
      cout << "malloc() failed!\n";
      exit(1);
   }

   *p = *(obj.p);
}

/* Thawee's note: 
      the object as argument calls copy constructor.

   ISSUE: if the obj has pointer, copy constructor MUST take care of 
          memory allocation here, so the destructor can deallocate 
          memory properly. OTHERWISE, the memory will be deallocated twice!

   TO TEST: comment out the declaration and implementation of copy constructor
            then try running this code.
*/
int neg(dyna ob) {
   return -ob.get();
}
   
int main() {
   dyna o(-10);

   cout << "1: " << o.get() << endl; // -10
   cout << "2: " << neg(o) << endl;  // 10 and destructor() is called once here

/*
   dyna o2(20);
   cout << "3: " << o2.get() << endl; // 20
   cout << "4: " << neg(o2) << endl;  // -20

   cout << "5: " << o.get() << endl;
   cout << "6: " << neg(o) << endl;
*/

   return 0;
}
