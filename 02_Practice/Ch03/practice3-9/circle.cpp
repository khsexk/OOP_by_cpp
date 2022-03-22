#include <iostream>

using namespace std;

#include "circle.h"

Circle::Circle() {
    radius = 1;
    coud << "반지름이 " << radius << "인 원 생성" << endl;
}

Circle::Circle(int r) {
    radius = r;
    coud << "반지름이 " << radius << "인 원 생성" << endl;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}