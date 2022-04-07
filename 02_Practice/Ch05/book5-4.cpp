#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big);


int main() {
    int a = 0;
    cout << "a를 입력하시오: " ;
    cin >> a;

    int b = 0;
    cout << "b를 입력하시오: ";
    cin >> b;

    int big;

    if(bigger(a, b, big))
        cout << "두 수는 같다" << endl;
    else
        cout << big << endl;
}

bool bigger(int a, int b, int& big){
    if(a==b){
        big = a;
        return true;
    }
    else{
        if(a>b)
            big = a;
        else
            big = b;
        return false;
    }
};