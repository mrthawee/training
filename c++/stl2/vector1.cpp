#include <iostream>
#include <vector>

using namespace std;

int main(void) {
   vector<int> v;

   for (int i=1; i<=6; ++i) {
      v.push_back(i);  // always add to the back of the vector 
   }

   for (int i=0; i<v.size(); ++i) {
      cout << v[i] << ' ';
   }
   cout << endl;

   return 0;
}
