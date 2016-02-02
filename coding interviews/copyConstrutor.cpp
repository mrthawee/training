#include <iostream>

using namespace std;

class A {
   private:
      int value;

   public:
      A(int n) {
         value = n;
      }

      //A(A other) {
      A(const A & other) {
         value = other.value;
      }
      void Print() {
         cout << value << endl;
      }
};

int main(int argc, char* argv[]) {

   A a = 10;
   A b = a;
   b.Print();

   return 0;
}
