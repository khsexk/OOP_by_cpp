#include <iostream>

using namespace std;

#include "circle.h"

int main() {
    Circle donut;
    double area1 = donut.getArea();
    cout << "donut의 면적은 " << area1 << endl;

    Circle pizza(30);
    double area2 = pizza.getArea();
    cout << "pizza의 면적은 " << area2 << endl;
}

