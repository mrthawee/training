#include <iostream>
#include <deque>

using namespace std;

int main() {
   deque<float> d;

   for (int i=1; i<=6; ++i) {
      d.push_front(i*1.1);
   }

   for (int i=0; i<d.size(); ++i) {
      cout << d[i] << ' ';
   }
   cout << endl;
}
