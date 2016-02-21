#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void print(int elem) {
   cout << elem << ' ';
}

int main() {
   vector<int> v;
   
   for (int i=1; i<=9; ++i) {
      v.push_back(i);
   }

   for_each(v.begin(), v.end(), print);
   cout << endl;
}
