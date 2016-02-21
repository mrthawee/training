#include <iostream>

using namespace std;

class Singleton {
   private:
      static Singleton *instance;
   
      Singleton() {}   // in private, so it can't be created!
      Singleton(Singleton const &);
      void operator=(Singleton const &);

   public:
      static Singleton* getInstance();

      string getDescription() {
         return "I'm a classic Singleton!";
      }
};

// This line is the must!
Singleton* Singleton::instance = NULL;

Singleton* Singleton::getInstance() {
   if (instance == NULL) {
      instance = new Singleton();
   }

   return instance;
}

int main() {
   Singleton *in = Singleton::getInstance();
   cout << in->getDescription() << endl;

   cout << Singleton::getInstance()->getDescription() << endl;
}
