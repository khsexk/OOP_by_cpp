#include <iostream>
using namespace std;

class Circle{
    int radius;
    public:
        Circle() { radius = 1; }
        ~Circle() { }
        void setRadius(int r) { radius = r; }
        double getArea();
};
double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() {
    cout << "생성하고자 하는 원의 개수: ";
    int n, radius;
    cin >> n;

    Circle *pArray = new Circle[n];

    for(int i=0 ; i<n ; i++){
        cout << "원 " << i+1 << ": ";
        cin >> radius;
        pArray[i].setRadius(radius);
    }

    int cnt = 0;
    Circle* p = pArray;

    for(int i=0 ; i<n ; i++){

    }

}