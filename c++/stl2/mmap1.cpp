#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
   multimap<int, string> mm;

   mm.insert(make_pair(5, "tagged"));
   mm.insert(make_pair(2, "a"));
   mm.insert(make_pair(1, "this"));
   mm.insert(make_pair(4, "of"));
   mm.insert(make_pair(6, "strings"));
   mm.insert(make_pair(1, "is"));
   mm.insert(make_pair(3, "multimap"));

   multimap<int, string>::iterator pos;
   for (pos = mm.begin(); pos != mm.end(); ++pos) {
      //cout << pos->first << ':' << pos->second << ' ';
      cout << pos->second << ' ';
   }
   cout << endl;
}
