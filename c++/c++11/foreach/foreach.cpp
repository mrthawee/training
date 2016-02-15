#include <iostream>

using namespace std;

int main(void) {
   int arr[10];

   for (auto & i : arr) {  // & is needed to modify data
      i = 5;
   }

   for (auto i : arr) {   // no & is needed if to read data
      cout << i << " ";
   }
   cout << endl;

   for (auto & i : arr) {   //  & is ok to read data
      cout << i << " ";
   }
   cout << endl;

   for (auto const & i : arr) {   // const & is good to read data
      cout << i << " ";
   }
   cout << endl;

   for (int n : {1,2,3,4,5} ) {
      cout << n << " ";
   }
   cout << endl;

   return 0;
}
