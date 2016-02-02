#include <iostream>

using namespace std;

class coord {
   private:
      int x, y;  // coordinate values

   public:
      coord(int i=0, int j=0) { x=i; y=j; }
      void get_xy(int &i, int &j) { i=x; j=y; }

      // overload binary operators
      coord operator+(const coord& obj); // o1 + o2
      coord operator+(const int i);      // ob + int : not for int + ob
      coord operator-(const coord& obj); // o1 - o2
      coord operator*(const coord& obj); // o1 - o2
      coord operator/(const coord& obj); // o1 - o2
   
      friend coord operator+(const int i, const coord& obj); // int + ob

      coord operator=(const coord& obj); // ob = obj

      bool  operator==(const coord& obj); // ob1 == ob2
      bool  operator&&(const coord& obj); // ob1 && ob2
      bool  operator>(const coord& obj);  // if (ob1 > ob2)
      bool  operator<(const coord& obj);  // if (ob1 < ob2)

      // overload unary operators
      coord operator++();  // ++ob
      coord operator--();  // --ob
      coord operator++(int notused); //ob++
      coord operator--(int notused); //ob--
      coord operator-();   // -ob : negation
      coord operator+();   // +ob : define as abs(ob)

      // Insertor : << for cout and stream
      friend ostream& operator<<(ostream& os, const coord& obj);
      // Extractor : >> for cin and stream
      //   obj can't be const because x, y will be updated
      friend istream& operator>>(istream& is,coord& obj);
};

ostream& operator<<(ostream& os, const coord &obj) {
   os << "x=" << obj.x << " y=" << obj.y;

   return os;
}

istream& operator>>(istream& is, coord &obj) {
   cout << "Enter value of x: ";
   is >> obj.x;
   cout << "Enter value of y: ";
   is >> obj.y;

   return is;
}

coord coord::operator+(const coord& obj) {
   coord tmp;

   tmp.x = x + obj.x;
   tmp.y = y + obj.y;

   return tmp;
}

coord coord::operator+(const int i) {
   coord tmp;

   tmp.x = x + i;
   tmp.y = y + i;

   return tmp;
}

coord coord::operator-(const coord& obj) {
   coord tmp;

   tmp.x = x - obj.x;
   tmp.y = y - obj.y;

   return tmp;
}

coord coord::operator=(const coord& obj) {
   x = obj.x;
   y = obj.y;

   return *this;
}

coord coord::operator*(const coord& obj) {
   coord tmp;

   tmp.x = x * obj.x;
   tmp.y = y * obj.y;

   return tmp;
}

coord coord::operator/(const coord& obj) {
   coord tmp;

   tmp.x = x / obj.x;
   tmp.y = y / obj.y;

   return tmp;
}

bool coord::operator==(const coord& obj) {
   /*
   if ( (x==obj.x) && (y==obj.y) ) 
      return true;
   else 
      return false;
   */
   return ( (x==obj.x) && (y==obj.y) );
}

bool coord::operator&&(const coord& obj) {
   return ( (x&&obj.x) && (y&&obj.y) );
}

bool coord::operator>(const coord& obj) {
   return ( (x>obj.x) && (y>obj.y) );
}

bool coord::operator<(const coord& obj) {
   return ( (x<obj.x) && (y<obj.y) );
}

coord coord::operator++() {
   x++; y++;
   return *this;
}

coord coord::operator--() {
   x--; y--;
   return *this;
}

coord coord::operator++(int notused) {
   x++; y++;
   return *this;
}

coord coord::operator--(int notused) {
   x--; y--;
   return *this;
}

coord coord::operator-() {  // -ob : negation
   x = -x;
   y = -y;

   return *this;
}

coord coord::operator+() {  // +ob : define as abs(ob)
   if (x < 0)
      x = -x;
   if (y < 0)
      y = -y;

   return *this;
}

coord operator+(const int i, const coord& obj) {
   coord tmp;

   tmp.x = obj.x + i;
   tmp.y = obj.y + i;

   return tmp;
}
int main() {
   coord o1(10, 10), o2(5, 3), o3, od;
   int x, y;

   cout << "o1 : " << o1 << endl;
   cout << "o2 : " << o2 << endl;
   cout << "o3 : " << o3 << endl;

   od = o1 + o2;
   od.get_xy(x, y);
   //cout << "(o1 + o2)  x=" << x << "  y=" << y << endl;
   cout << "(o1+o2) : " << od << endl;

   od = o1 + 20;
   od.get_xy(x, y);
   cout << "(o1+20) : " << od << endl;


   od = o1 - o2;
   od.get_xy(x, y);
   cout << "(o1-o2) : " << od << endl;

   od = o1 * o2;
   od.get_xy(x, y);
   cout << "(o1*o2) : " << od << endl;

   od = o1 / o2;
   od.get_xy(x, y);
   cout << "(o1/o2) : " << od << endl;

   od = o2;
   cout << "(od=o2)-> od : " << od << endl;

   if ( o1 == o2 ) 
      cout << " o1 == o2 returns true\n";
   else
      cout << " o1 == o2 returns false\n";

   if ( o1 && o2)
      cout << " o1 && o2 returns true\n";
   else
      cout << " o1 && o2 returns false\n";

   if ( o1 > o2)
      cout << " o1 > o2 returns true\n";
   else
      cout << " o1 > o2 returns false\n";

   if ( o1 < o2)
      cout << " o1 < o2 returns true\n";
   else
      cout << " o1 < o2 returns false\n";

   cout << "++o1 = " << ++o1 << endl;
   cout << "--o1 = " << --o1 << endl;

   cout << "o1++ = " << o1++ << endl;
   cout << "o1-- = " << o1-- << endl;

   cout << "-o2 = " << -o2 << endl;
   cout << "+o2 = " << +o2 << endl;

   // Use of "friend coord operator+(const int i, const coord& obj);"
   od = 40 + o1; // can't be done with  coord coord::operator+(coord ob);
   cout << "od = (40+o1) => " << od << endl;

   coord testObj;
   cout << "Init: " << testObj << endl;;
   cin >> testObj;
   cout << "Now: " << testObj << endl;

   return 0;
} 
