#include <iostream>

using namespace std;

class Singleton {
   private:
      static bool       instanceFlag;
      static Singleton *instance;

      Singleton() {
         // private constructor
      }

   public:
      ~Singleton() {
         instanceFlag = false;
      }

      static Singleton* getInstance();
      
      void method();
};

bool Singleton::instanceFlag = false;
Singleton* Singleton::instance = NULL;

Singleton* Singleton::getInstance() {
   //if (instance == NULL) {
   if (instanceFlag == false) {
      cout << "Creating Singleton instance.." << endl;
      instance = new Singleton();
      instanceFlag = true;
   } else {
      cout << "Singleton instance has already been created." << endl;
   }

   return instance;
}

void Singleton::method() {
   cout << "Invoke method()" << endl;
}

int main(void) {

   Singleton *sc1, *sc2;
   sc1 = Singleton::getInstance();
   sc1->method();
   sc2 = Singleton::getInstance();
   sc2->method();

   return 0;
}
