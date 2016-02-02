#include <iostream>

using namespace std;

int main(void) {

   int in = 0;
   int c0 = 0;
   int c1 = 0;

   cout << "Enter a number: ";
   cin >> in;

   cout << "input = " << in << " -> 0b";
   cout << bitset<8>(in)  << endl;

   //while (in > 0) {
   for (int i=0; i<8; i++) {  // range of 8 bits
      if (in % 2 == 0) {
         c0++;
      } else {
         c1++;
      }

      in = in >> 1;
   }
      
   cout << "num bits of 0 = " << c0 << endl;
   cout << "num bits of 1 = " << c1 << endl; 

   return 0;
}
