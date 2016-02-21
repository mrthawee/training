/*
   Virtual function : needed for polymorphism

   Why? without 'virtual' keyword, ptr to base class will invoke the base class 
   implementation; not the derived ones

   Pure Virtual Function : function with no implementation => Abstract Class
   - Sub-Class must implement this function in order to create an object.

   Good Practice:
   1. Destructor must be virtual. Why?
      With Polymorphisim, ptrOb generally is pointing to base class. When
   it is deallocated, the destructor of its sub-class should be invoked as well.
   Hence, defining desstructor as virtual is needed.

   2. Never invoke virtual functions in Constructor/Destructor
   See Effective C++ item 9
   Brief: virtual function doesn't work in constructor because its sub-class
          has yet created! Same reason to explain destructor issue.

   Solution: let the constructor of sub-class invokes specific function of its
             super-class to ensure that all actions will take place properly.
*/
#include <iostream>

using namespace std;

class B {
   private:
      int b;
   public:
      B(int i) { b = i; }
      virtual ~B() { cout << "invoke ~B()\n"; }
//      virtual void Print() = 0; // Pure Virtual Function
//      virtual void Print() { cout << "B: " << b << endl; }
      void Print() { cout << "B: " << b << endl; }
};

class D : public B {
   private:
      int d;
   public:
      D(int x, int y) : B(y) { d = x; }
      virtual ~D() { cout << "invoke ~D()\n"; }
      void Print() {
         cout << "D: " << d << "    " ;
      // sub-class can invoke base class with scope when sharing the same name
      // B::Print();
         cout << endl;
      }
};

int main() {
   D ob(1, 2);
   B* ptrOb = &ob;

   ob.Print();

   // If 'B' doesn't define Print() as Virtual Function, B::Print() is invoked
   // If 'B' defines Print() as Virtual Function, D::Print() is invoked 
   ptrOb->Print();

   return 0;
}
