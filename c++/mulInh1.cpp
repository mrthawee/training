/*
   B1
   |
   v
   D1
   |
   v
   D2
*/
#include <iostream>

using namespace std;

class B1 {
   private:
      int a;
   public:
      B1(int x) { a = x; }
      int geta() { return a; }
      virtual void Print() = 0; // pure virtual function @ base : OK
};

class D1 : public B1 {
   private:
      int b;
   public:
      D1(int x, int y) : B1(y) { b = x; }
      int getb() { return b; }
      virtual void Print() = 0; // pure virtual function @ derived 1 : OK
};

class D2 : public D1 {
   private:
      int c;
   public:
      D2(int x, int y, int z) : D1(y, z) { c = x; }
      void Print() { show(); }; // implemented @ derived 2 : OK
      void show() {
         cout << geta() << ' ' << getb() << ' ' << c << endl;
      }
};

int main() {
   D2 obj(1, 2, 3);

//   obj.show();
   obj.Print();
   cout << obj.geta() << ' ' << obj.getb() << endl;
}
