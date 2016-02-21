/*
 * Decorator Pattern:
 *
 * The Decorator Pattern attaches dadditional responsibilities to an object
 * dynamically.  Decorators provide a flexible alternative to subclassing
 * for extending functionality.
 */
#include <iostream>
#include <string>

using namespace std;

// Beverage : abstract class
// - no implementation of cost()
class Beverage {
   protected:
      string description;

   public:
      Beverage() : description("Unknown Beverage") { }
      virtual ~Beverage() { cout << "~Beverage()\n"; }
      virtual string getDescription() {
         return description;
      }
      virtual double cost() = 0;
};

// Implement Coffee type 1
class HouseBlend : public Beverage {
   public:
      //HouseBlend() : description("House Blend Coffee") { }
      HouseBlend() {
         description = "House Blend Coffee";
      }
      ~HouseBlend() { 
         cout << "~HouseBlend()\n"; 
      }

      double cost() { return 0.89; }
};

// Implement Coffee type 2
class Espresso : public Beverage {
   public:
      Espresso() {
         description = "Espresso";
      }
      ~Espresso() { 
         cout << "~Espresso()\n";
      }

      double cost() { return 1.99; }
};

class DarkRoast : public Beverage {
   public:
      DarkRoast() {
         description = "DarkRoast";
      }
      double cost() { return 0.99; }
};

class Decaf : public Beverage {
   public:
      Decaf() {
         description = "Decaf";
      }
      double cost() { return 1.05; }
};


// CondimentDecorator : abstract class
// - no implementation of getDescription()
class CondimentDecorator : public Beverage {
   public:
      virtual string getDescription() = 0;
};

class Milk : public CondimentDecorator {
   private:
      Beverage *beverage;

   public:
      Milk(Beverage *b) {
         beverage = b;
      }

      ~Milk() {
         if (beverage != NULL) {
            delete beverage;
            beverage = NULL;
         }
      }

      string getDescription() {
         return beverage->getDescription() + ", Milk";
      }

      double cost() {
         return 0.10 + beverage->cost();
      }
};

class Soy : public CondimentDecorator {
   private:
      Beverage *beverage;

   public:
      Soy(Beverage *b) {
         beverage = b;
      }

      ~Soy() {
         if (beverage != NULL) {
            delete beverage;
            beverage = NULL;
         }
      }

      string getDescription() {
         return beverage->getDescription() + ", Soy";
      }

      double cost() {
         return beverage->cost() + 0.15;
      }
};

class Mocha : public CondimentDecorator {
   private:
      Beverage *beverage;

   public:
      Mocha(Beverage *b) {
         beverage = b;
      }

      ~Mocha() {
         if (beverage != NULL) {
            delete beverage;
            beverage = NULL;
         }
      }

      string getDescription() {
         return beverage->getDescription() + ", Mocha";
      }

      double cost() {
         return beverage->cost() + 0.20;
      }
};

class Whip : public CondimentDecorator {
   private:
      Beverage *beverage;
   public:
      Whip(Beverage *b) {
         beverage = b;
      }
      ~Whip() {
         if (beverage != NULL) {
            delete beverage;
            beverage = NULL;
         }
      }
      string getDescription() {
         return beverage->getDescription() + ", Whip";
      }
      double cost() {
         return beverage->cost() + 0.10;
      }
};

int main() {
   // HouseBlend with Milk
   Beverage *b1 = new HouseBlend();
   b1 = new Milk(b1);
   cout << b1->getDescription() << " costs " << b1->cost() << endl;

   // Decaf Mocha double Whip
   Beverage *b2 = new Decaf();
   b2 = new Mocha(b2);
   b2 = new Whip(new Whip(b2));  // double Whip
   cout << b2->getDescription() << " costs " << b2->cost() << endl;

   delete b1;
   delete b2;
}

