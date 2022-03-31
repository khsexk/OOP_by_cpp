#include <iostream>
using namespace std;

class Circle{
    private:
        int radius;
    public: 
        Circle() { radius = 1; }
        Circle(int r) { radius = r; }
        ~Circle() { cout << radius << "원 소멸" << endl; }
        double getArea() { return 3.14 * radius * radius; }
        int getRadius() { return radius; }
        void setRadius(int radius) { this->radius = radius; }
};

void increase(Circle c){
    int r = c.getRadius();
    c.setRadius(r+1);
}

int main() {
    Circle waffle(30);
    increase(waffle);
    cout << waffle.getRadius() << endl;
}