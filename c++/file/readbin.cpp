#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int get_int(int v);

int main(void) {
   char filename[FILENAME_MAX];
   int n =0;
   char name[20];
   int age = 0;
   int recsize = sizeof(name) + sizeof(int);

   cout << "Enter file name: ";
   cin.getline(filename, FILENAME_MAX);

   // Open file for binary read-write access
   fstream fbin(filename, ios::binary | ios::in);
   if (!fbin) {
      cout << "Error: can't open " << filename << endl;
      return -1;
   }

   // Get record number and go to record
   cout << "Enter file record number: ";
   //cin >> n;
   n = get_int(0);
   fbin.seekp(n * recsize);

   // Read data from file
   fbin.read(name, sizeof(name) - 1);
   fbin.read((char*)&age, sizeof(int));

   // Display the data and close file.
   cout << "Name = " << name << endl;
   cout << "Age = " << age << endl;
   fbin.close();

   return 0;
}

// Get integer function
int get_int(int v) {
   char s[81];

   cin.getline(s, 80);
   if (strlen(s) == 0) {
      return v;
   }

   return atoi(s);
}
