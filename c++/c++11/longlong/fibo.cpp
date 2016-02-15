#include <iostream>
#include <string>
#include <sstream>

using namespace std;

unsigned long long Fibo(int n);
string output_formatted_string(unsigned long long v);

int main() {
   int n = 0;
   cout << "Enter a number: ";
   cin >> n;
   string s = output_formatted_string(Fibo(n));
   cout << "Fibo(" << n << ") = " << s << endl;

   return 0;
}

unsigned long long Fibo(int n) {
   if (n < 2)
      return 1;

   unsigned long long temp1 = 1;
   unsigned long long temp2 = 1;
   unsigned long long sum = 0;

   while (n-- > 1) {
      sum   = temp1 + temp2;
      temp2 = temp1;
      temp1 = sum;

//      cout << n << " : " << sum << endl;
   }

   return sum;
}

#define GROUP_SEP  ','
#define GROUP_SIZE 3

string output_formatted_string(unsigned long long v) {
   // Read data into string s
   stringstream temp, out;
   temp << v;
   string s = temp.str();

   int n = s.size() % GROUP_SIZE;
   int i = 0;
   cout << "n=" << n << "  s.size()= " << s.size() << endl;
   if (n > 0 && s.size() > GROUP_SIZE) {
      cout << "i=" << i << "  n=" << n << endl;
      out << s.substr(i, n) << GROUP_SEP;
      cout << s.substr(i, n) << endl;;
      cout << out.str() << endl;
      i += n;
   }

   n = s.size() / GROUP_SIZE - 1;
   while (n-- > 0) {
      cout << "i=" << i << "  n=" << n << endl;
      out << s.substr(i, GROUP_SIZE) << GROUP_SEP;
      cout << s.substr(i, GROUP_SIZE) << endl;
      cout << out.str() << endl;
      i += GROUP_SIZE;
   }

   out << s.substr(i);
//   cout << s.substr(i) << endl;

   return out.str();
}
