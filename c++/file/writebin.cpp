#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

//#define FILENAME_MAX 20

using namespace std;

int get_int(int v);

int main(void) {
   char filename[FILENAME_MAX];
   int n = 0;
   char name[20];
   int age = 0;
   int recsize = sizeof(name) + sizeof(int);

   cout << "Enter file name: ";
   cin.getline(filename, FILENAME_MAX);

   // Open file for binary write
   fstream fbin(filename, ios::binary | ios::out);
   if (!fbin) {
      cout << "Error: can't open file " << filename << endl;
      return -1;
   }

   // Get record filename to write to.
   cout << "Enter file record number: ";
   n = get_int(0);
   //cin >> n;
   cout << "got n = " << n << endl;

   // Get data from user
   cout << "Enter name: ";
   cin.getline(name, sizeof(name) - 1);
   //cin >> name;
   cout << "got name = " << name << endl;
   cout << "Enter age: ";
   age = get_int(0);
   //cin >> age;
   cout << "got age = " << age << endl;

   // Write data to file
   fbin.seekp(n * recsize);
   fbin.write(name, sizeof(name) - 1);
   fbin.write((char*)&age, sizeof(int));
   fbin.close();
   
   return 0;
}

#define COL_WIDTH 80

// Get integer function
int get_int(int v) {
   char s[81];

   cin.getline(s, 80);
   if (strlen(s) == 0) {
      return v;
   }

   return atoi(s);
}
