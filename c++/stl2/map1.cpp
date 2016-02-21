#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
   map<string, float> sfMap;

   sfMap["VAT"] = 0.15;
   sfMap["Pi"] = 3.1415;
   sfMap["an arbitrary number"] = 4983.223;
   sfMap["Null"] = 0;

   map<string, float>::iterator pos;
   for (pos = sfMap.begin(); pos != sfMap.end(); ++pos) {
      cout << "key: \"" << pos->first << "\" "
           << "value: " << pos->second << endl;
   }
}
