#include <iostream>

using namespace std;

enum class Color {
   RED,
   BLUE
};

enum class Fruit {
   BANANA,
   APPLE
};

int main() {
   Color a = Color::RED;
   Fruit b = Fruit::BANANA;

   //if (a == b) {
   if (Color::RED == Fruit::BANANA) {
      cout << "a and b are equal" << endl;
   } else {
      cout << "a and b are not equal" << endl;
   }

   return 0;
}
