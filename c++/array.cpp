#include <iostream>

using namespace std;

void printArray(int array[], int sizeOfArray) {
   for(int i=0; i<sizeOfArray; i++) {
      cout << array[i] << " ";
   }

   cout << endl;
}

int main() {
   int a[5] = { 2, 3, 5, 4, 1 };

   printArray(a, sizeof(a)/sizeof(a[0]));
}
