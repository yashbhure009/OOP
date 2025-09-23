/* * 1095.cpp * * Created on: 10 Sept 2025 * Author: mmcoe */
#include<iostream>
using namespace std;
class shape {
protected:
   float x, y;
public:
   shape() {
       float x;
       float y;
   }
   virtual void input() {
       cout << "Enter The Height Of The X(Height): ";
       cin >> x;
       cout << "Enter The Base Of The Y(Width): ";
       cin >> y;
   }
   virtual void display() {
       cout << "Area is done by Base Class" << endl;
   }
};
class triangle : public shape {
public:
   void display() {
       float area = 0.5 * x * y;
       cout << "Area of Triangle is: " << area << endl;
       // ASCII art for triangle
       cout << "   /\\\n";
       cout << "  /  \\\n";
       cout << " /    \\\n";
       cout << "/______\\\n";
   }
};
class rectangle : public shape {
public:
   void display() {
       float area = x * y;
       cout << "Area Of Rectangle: " << area << endl;
       // ASCII art for rectangle
       cout << "  ____________ " << endl;
       cout << " |            |" << endl;
       cout << " |            |" << endl;
       cout << " |            |" << endl;
       cout << " |____________|" << endl;
   }
};
int main() {
   shape* shapeptr;
   triangle t;
   shapeptr = &t;
   shapeptr->input();
   shapeptr->display();
   rectangle r;
   shapeptr = &r;
   shapeptr->input();
   shapeptr->display();
   return 0;
}
