#include <iostream>

using namespace std;

class Circle{
    public:
        int radius;
        double getArea();
        Circle(int r);
};

Circle::Circle(int r): radius(r) { }

int main(){
    Circle c1(30);
    // Circle c2; 컴파일 오류
}

