#include <iostream>

using namespace std;
// FlyBehavior Interface
class FlyBehavior {
   public:
      virtual void fly() = 0;
};

// FlyNoWay implements FlyBehevior Intetface
class FlyNoWay : public FlyBehavior {
   public:
      void fly() {
         cout << "I can't fly\n";
      }
};

class FlyWithWings : public FlyBehavior {
   public:
      void fly() {
         cout << "I'm flying!!\n";
      }
};

// QuackBehavior Interface
class QuackBehavior {
   public:
      virtual void quack() = 0;
};

// MuteQuack implements QuackBehavior Interface
class MuteQuack : public QuackBehavior {
   public:
      void quack() {
         cout << "<< Silence >>\n";
      }
};

class Quack : public QuackBehavior {
   public:
      void quack() {
         cout << "Quack\n";
      }
};

class Squeak : public QuackBehavior {
   public:
      void quack() {
         cout << "Squeak\n";
      }
};

// KEY of the strategey pattern
// * FlyBehavior and QuackBehavior are the polymorphism 
class Duck {
   protected:
      // Base Class for Polymorphism on FlyBehavior class hierarchy
      FlyBehavior *flyBehavior;

      // Base Class for Polymorphism on QuackBehavior class hierarchy
      QuackBehavior *quackBehavior;
   
   public:
      Duck() { }

      // Needed!!!! to not having memory leak!
      virtual ~Duck() {
         delete flyBehavior;
         delete quackBehavior;
      }

      // This "set" method allows sub-class to change its behavior as needed
      void setFlyBehavior(FlyBehavior *fb) {
         // Don't forget to delete the old object first, otherwise memory leaks
         delete flyBehavior;
         flyBehavior = fb;
      }

      // This "set" method allows sub-class to change its behavior as needed
      void setQuackBehavior(QuackBehavior *qb) {
         // Don't forget to delete the old object first, otherwise memory leaks
         delete quackBehavior;
         quackBehavior = qb;
      }

      virtual void display() = 0;

      void performFly() {
         //flyBehavior.fly();
         flyBehavior->fly();
      }

      void performQuack() {
         quackBehavior->quack();
      }

      void swim() {
         cout << "All ducks float, even decoys!\n";
      }
};

class DecoyDuck : public Duck {
   public:
      DecoyDuck() {
//         setFlyBehavior(new FlyNoWay());
//         setQuackBehavior(new MuteQuack());
         flyBehavior = new FlyNoWay();
         quackBehavior = new MuteQuack();
      }
   
      void display() {
         cout << "I'm a duck Decoy\n";
      }
};

class ModelDuck : public Duck {
   public:
      ModelDuck() {
         flyBehavior = new FlyNoWay();
         quackBehavior = new Quack();
      }

      /*
      void setFlyBehavior(FlyBehavior *fb) {
         delete flyBehavior;
         flyBehavior = fb;
      }

      void setQuackBehavior(QuackBehavior *qb) {
         delete quackBehavior;
         quackBehavior = qb;
      }
      */

      void display() {
         cout << "I'm a model duck.\n";
      }
};
         
class RubberDuck : public Duck {
   public:
      RubberDuck() {
         flyBehavior = new FlyNoWay();
         quackBehavior = new Squeak();
      }

      void display() {
         cout << "I'm a rubber duckie\n";
      }
};

class RedHeadDuck : public Duck {
   public:
      RedHeadDuck() {
         flyBehavior = new FlyWithWings();
         quackBehavior = new Quack();
      }

      void display() {
         cout << "I'm a real Red Headed duck\n";
      }
};

class FlyRocketPowered : public FlyBehavior {
   public:
      void fly() {
         cout << "I'm ROCKET POWERED flying!!\n";
      }
};

int main() {
   DecoyDuck decoy;
   cout << "DecoyDuck:\n";
   decoy.performQuack();
   decoy.performFly();
   decoy.swim();
   cout << endl;

   ModelDuck model;
   cout << "ModelDuck:\n";
   model.performQuack();
   model.performFly();
   model.setFlyBehavior(new FlyRocketPowered());
   model.performFly();
   model.swim();
   cout << endl;

   RubberDuck rubber;
   cout << "RubberDuck:\n";
   rubber.performQuack();
   rubber.performFly();
   rubber.swim();
   cout << endl;

   RedHeadDuck redhead;
   cout << "ReadHeadDuck:\n";
   redhead.performQuack();
   redhead.performFly();
   redhead.swim();
   cout << endl;

   return 0;
}

