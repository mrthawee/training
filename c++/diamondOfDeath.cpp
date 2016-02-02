/*

   Common base class for multiple inheritance

   --------
   | Base | => needs 'virtual' for each sub-classes to have same grand sub-class
   --------
   |      |
   v      v
   D1    D2
   --------
       |
       v
       D3
*/

#include <iostream>

using namespace std;

class Base {
   public:
      int i;
};

//class D1 : public Base {
class D1 : virtual public Base { // keyword 'virtual' is needed!
   public:
      int j;
};

//class D2 : public Base {
class D2 : virtual public Base { // keyword 'virtual' is needed!
   public:
      int k;
};

class D3 : public D1, public D2 {
   public:
      int product() { return i*j*k; }
};

int main() {
   D3 ob;

   ob.i = 2;
   ob.j = 3;
   ob.k = 4;

   cout << ob.product() << endl;

   return 0;
}
