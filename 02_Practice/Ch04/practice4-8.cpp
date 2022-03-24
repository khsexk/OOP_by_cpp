#include <iostream>

using namespace std;

class Circle{
    int radius;
    public:
        Circle() { radius = 1; }
        Circle(int r) { radius = r; }
        ~Circle() { cout << radius << " 소멸자 실행" << endl;}
        void setRadius(int r) { radius = r; }
        double getArea();
};
double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() {
    int radius;

    while(true){
        cout << "반지름 입력: ";
        cin >> radius;

        if(radius < 0)
            break;
        Circle *p = new Circle(radius);
        cout << radius << " 면적: " << p->getArea() << endl;
        delete p;
    }
}