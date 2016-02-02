#include <iostream>
#include <string>

using namespace std;

class Shape {
   private:
      string name;

   public:
      Shape(string s) { name = s; }
      void setName(string s) { name = s; }
      string getName() const { return name; }

      // pure virtual function
      virtual double getArea() const = 0; // pure because " = 0"
};

class Circle : public Shape {
   private:
      double radius;

   public:
      Circle(string s, double r) : Shape(s) { radius = r; }
      void setRadius(double r) { radius = r; }
      double getRadius() const { return radius; }
   
      virtual double getArea() const { return 3.14159*radius*radius; }
};

class Rectangle : public Shape {
   private:
      double length, width;

   public:
      Rectangle(string s, double l, double w) : Shape(s) {
         length = l; width = w;
      }
      void setLength(double l) { length = l; }
      void setWidth(double w) { width = w; }
      double getLength() const { return length; }
      double getWidth() const { return width; }

      virtual double getArea() const { return length * width; }
};

class Triangle : public Shape {
   private:
      double base, width;

   public:
      Triangle(string s, double b, double w) : Shape(s) {
         base = b; width = w;
      }

      virtual double getArea() const { return 0.5 * base * width; }
};

int main() {
   //Shape s("Foo");
   //cout << s.getName() << endl;

   Circle c("CC", 2);
   
   cout << "Circle:\n";
   cout << "  name = " << c.getName() << endl;
   cout << "  radius = " << c.getRadius() << endl;
   cout << "  area = " << c.getArea() << endl;

   Rectangle r("RR", 4, 10);
   cout << "Rectangle:\n";
   cout << "  name = " << r.getName() << endl;
   cout << "  length = " << r.getLength() << endl;
   cout << "  width = " << r.getWidth() << endl;
   cout << "  area = " << r.getArea() << endl;

   Triangle t("TT", 2, 5);
   cout << "Triangle:\n";
   cout << "  name = " << t.getName() << endl;
   cout << "  area = " << t.getArea() << endl;

   Shape* sh[3] = { new Circle("c1", 3), new Rectangle("r1", 3, 5), new Triangle("t1", 6, 8) };

   // Polymorphism : calling getArea() of sub-classes using pointers to base class
   for (int i=0; i<3; i++) {
      cout << sh[i]->getArea() << endl;
   }

   return 0;
}
