/*
   B1    B2
   |     |
   v     v
   ------
      |
      v
      D
*/
#include <iostream>

using namespace std;

class B1 {
   private:
   public:
      B1() { cout << "Constructor B1\n"; }
      ~B1() { cout << "Destructor B1\n"; }
};

class B2 {
   private:
   public:
      B2() { cout << "Constructor B2\n"; }
      ~B2() { cout << "Destructor B2\n"; }
};

class D : public B1, public B2 {
   private:
   public:
      D() { cout << "Constructor D\n"; }
      ~D() { cout << "Destructor D\n"; }
};

int main() {
   D ob;
   return 0;
}
