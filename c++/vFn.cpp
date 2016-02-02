#include <iostream>

using namespace std;

class Human {
   public:
      void From() {
         cout << "Earth" << endl;
      }
};

class Asia : public Human {
   public:
      virtual void From() {
         cout << "Asia" << endl;
      }
};

class Europe : public Human {
   public:
      void From() { // Without 'virtual' keyword, it's still a virtual
         cout << "Europe" << endl;
      }
};

class Thai : public Asia {
   public:
      virtual void From() {
         cout << "Thailand" << endl;
      }
};

class UK : public Europe {
   public:
      virtual void From() {
         cout << "UK" << endl;
      }
};


int main(int argc, char* argv[]) {
   Asia *a = new Asia;
   Europe *e = new Europe;

   Thai *t = new Thai;
   UK *u = new UK;

   Human *h = a;
   h->From();

   h = e;
   h->From();

   delete a;
   delete e;
   a = t; a->From();
   e = u; e->From();

   delete t;
   delete u;

   return 0;
}
