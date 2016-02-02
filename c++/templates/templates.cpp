#include <iostream>

using namespace std;

int square(int x) {
   return x*x;
}

double square(double x) {
   return x*x;
}

template <typename T>
T squareTemplate(T x) {
   return x*x;
}

void testFunctionTemplate() {

   cout << square(5) << endl;    // make use of int square(int x);
   cout << square(5.5) << endl;    // make use of double square(double x);
   cout << squareTemplate<int>(5) << endl;
   cout << squareTemplate<double>(5.5) << endl;
   cout << squareTemplate(5) << endl;   // no need to specify Type
   cout << squareTemplate(5.5) << endl;   // no need to specify Type
}

template <typename T>
class BoVector {
   private:
     T arr[1000];
     int size;
   public:
      BoVector():size(0) {}
      void push(T x) { arr[size] = x; size++; }
      T get(int i) const { return arr[i]; }
      int getSize() const { return size; }
      void print() const { 
         for (int i=0; i<size; i++) {
            cout << arr[i] << endl;
         }
      }
};

template<typename T>
BoVector<T> operator*(const BoVector<T>& rhs1, BoVector<T>& rhs2) {
   BoVector<T> ret;
   for (int i=0; i<rhs1.getSize(); i++) {
      ret.push(rhs1.get(i) * rhs2.get(i));
   }

   return ret;
}

int main() {
   testFunctionTemplate();

   BoVector<int> bv;  // class template MUST have type defined clearly.
   bv.push(2);
   bv.push(5);
   bv.push(8);
   bv.push(9);
   bv.print();

   cout << "Print squared bv: " << endl;
   bv = squareTemplate(bv);
   bv.print();   
}
