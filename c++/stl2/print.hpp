#ifndef PRINT_H
#define PRINT_H

#include <iostream>

using namespace std;
/*
 * PRINT_ELEMENTS()
 * - prints optional C-string optcstr followed by
 * - all elements of the collection 
 * - separated by spaces
 */

template <class T>
inline void PRINT_ELEMENTS(const T& col1, const char* optcstr="") {
   typename T::const_iterator pos;

   cout << optcstr;
   for (pos=col1.begin(); pos!=col1.end(); ++pos) {
      cout << *pos << ' ';
   }
   cout << endl;
}

#endif
