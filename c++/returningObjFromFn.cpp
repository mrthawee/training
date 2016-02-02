#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class samp {
   private:
      char* s;

   public:
      samp() { cout << "Default constructor\n";  s = NULL; }
      //samp(const samp &obj);
      samp(samp &obj);
      ~samp() { if (s) free(s); cout << "Freeing s\n"; }
      void show() { cout << s << endl; }
      void set(char *str);
};

//samp::samp(const samp &obj) {
samp::samp(samp &obj) {
   cout << "Copy constructor\n";
   s = (char*)malloc(strlen(obj.s));
   if (!s) {
      cout << "malloc failed!\n";
      exit (1);
   }

   strcpy(s, obj.s);
}

void samp::set(char *str){
   s = (char*)malloc(strlen(str));

   if (!s) {
      cout << "malloc failed!\n";
      exit (1);
   }

   strcpy(s, str);
}

/*
 This function DOESN'T work!

 It creates a local object and try to return that obj.
 IF USED, the caller will get INVALID object since it is deallocated already.
*/
samp input() {
   char s[30];
   samp str;    // local object -> constructor is called

   cout << "Enter a string: ";
   cin >> s;

   str.set(s);
   
   return (str); // returning -> destructor is called
}

// Thawee's work around
// Why does it fix?
//  -- passing the object by reference prevents calling constructor
//     so, it prevents creating another pointer to the same addr 
//     which will free when leaving funcion call
void input(samp &obj) {
   char s[30];
   //samp str;    // local object -> constructor is called

   cout << "Enter a string: ";
   cin >> s;

   obj.set(s);
   
   //return (str); // returning -> destructor is called
}
int main() {
   samp ob;     // constructor is called

   // assign returned object to ob
   // ob = input();  // This causes an error!! : use Thawee's work around on next line
   input(ob);
   ob.show();

   // Added for debugging!
   //char c;
   //cin >> c;

   return 0;
}
