#include <iostream>
#include <string>

using namespace std;

class Car { // Abstract base class
   protected:
      string _str;

   public:
      Car() {
         _str = "Unknown Car";
      }

      virtual ~Car() {
         cout << "~Car()\n";
      }

      virtual string getDescription() {
         return _str;
      }

      virtual double getCost() = 0;
};      

// Decorator Base Class
class OptionsDecorator : public Car {
/*
   protected:
      Car   *_basePtrCar;
*/

   public:
      virtual ~OptionsDecorator() {
         cout << "~OptionsDecorator()\n";
      }

      virtual string getDescription() = 0;
};
      
class Honda : public Car {
   public:
      Honda() {
         _str = "Honda";
      }

      ~Honda() {
         cout << "~Honda()\n";
      }

      virtual double getCost() {
         return 25001.01;
      } 
};

class Toyota : public Car {
   public:
      Toyota() {
         _str = "Toyota";
      }

      ~Toyota() {
         cout << "~Toyota()\n";
      }

      virtual double getCost() {
         return 30000;
      }
};

class Navigation : public OptionsDecorator {
   private:
      Car   *_basePtrCar;

   public:
      Navigation(Car *b) {
         _basePtrCar = b;
      }

      virtual ~Navigation() {
         if (_basePtrCar != NULL) {
            delete _basePtrCar;
            _basePtrCar = NULL;
         }
         cout << "~Navigation()\n";
      }

      string getDescription() {
         return _basePtrCar->getDescription() + ", Navigation";
      }

      double getCost() {
         return _basePtrCar->getCost() + 550;
      }
};

class PremiumSoundSystem : public OptionsDecorator {
   private:
      Car   *_basePtrCar;

   public:
      PremiumSoundSystem(Car *b) {
         _basePtrCar = b;
      }

      virtual ~PremiumSoundSystem() {
         if (_basePtrCar != NULL) {
            delete _basePtrCar;
            _basePtrCar = NULL;
         }
         cout << "~PremiumSoundSystem()\n";
      }

      string getDescription() {
         return _basePtrCar->getDescription() + ", Premium Sound System";
      }

      double getCost() {
         return _basePtrCar->getCost() + 230;
      }
};

class CVT : public OptionsDecorator {
   private:
      Car *_basePtrCar;

   public:
      CVT(Car *b) {
         _basePtrCar = b;
      }

      virtual ~CVT() {
         if (_basePtrCar != NULL) {
            delete _basePtrCar;
            _basePtrCar = NULL;
         }
         cout << "~CVT()\n";
      }

      string getDescription() {
         return _basePtrCar->getDescription() + ", CVT";
      }

      double getCost() {
         return _basePtrCar->getCost() + 429;
      }
};

int main() {
   Car *c = new Honda();
   c = new Navigation(c);
   c = new PremiumSoundSystem(c);
   cout << c->getDescription() << " will cost you $" << c->getCost() << endl;

   Car *t = new CVT(new Toyota());
   t = new Navigation(t);
   t = new PremiumSoundSystem(t);
//   t = new CVT(t);
   cout << t->getDescription() << " will cost you $" << t->getCost() << endl;

   delete c;
   delete t;
}
