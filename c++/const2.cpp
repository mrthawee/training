#include <iostream>

using namespace std;

class Dog {
   private:
      int age;
      string name;
   public:
      Dog() { age = 3; name = "dummy"; }
      void print() {
         cout << " age = " << age << "   name = " << name << endl;
      }
      void setAge(int &a) {
         age = a;
         a++; // just for an example if we modify it : cout as 10
      }

      void setAge(const int &a) {
         age = a;
         // a++;  both 'const int a' and 'const int &a' don't allow a++
      }

      // void setAge(const int a) : can't be overloaded 
      // compiler got confused with 'void setAge(int &a)

      // const to what is returned
      const string& getName() { return name; }

      // not point of using const here
//      const string getName() { return name; }

      // const funciton :
      // 1. can't update member variables 
      // 2. can call only const functions
      void printName() const { cout << "Const : " << name << endl; }

      // to be called by a non-const object of Dog
      void printName() { cout << "Non-Const : "<< name << endl; }
};

int main() {
   Dog d;

   int i = 9;
   d.setAge(i); // calling 'void setAge(int &a)'
   d.print();
   cout << i << endl;

   const int x = 20;
   d.setAge(x); // calling 'void setAge(const int &a)'
   d.print();
   cout << x << endl;

   d.printName(); // calling the non-const printName()

   const Dog dc;
   dc.printName(); // calling the const printName()
} 
