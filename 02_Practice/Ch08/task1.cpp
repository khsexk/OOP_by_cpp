#include <iostream>
using namespace std;

class Point{

};
class ColorPoint : public Point {

};

int main() {
    Point p, *pPointer;
    pPointer = &p;

    ColorPoint *cpPointer = (ColorPoint*)pPointer; // 다운 캐스팅
}