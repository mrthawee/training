#include <iostream>
#include <typeinfo>

using namespace std;

template<class T, class U> 
auto add(T t, U u) -> decltype(t + u) {
   return t + u;
}

int main(void) {
   auto a = add(3, 5);
   cout << a << " : " << typeid(a).name() << endl;
   auto b = add(3.3, 5);
   cout << b << " : " << typeid(b).name() << endl;

   auto c = {1, 2};
   cout << " : " << typeid(c).name() << endl;

   return 0;
}
