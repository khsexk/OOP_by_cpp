#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big){
    if(a==b)
        return true;
    else if(a>b)
        big = a;
    else if(a<b)
        big = b;
    return false;
}

int main() {
    int a, b, big;
    cin >> a >> b;

    if(bigger(a, b, big))
        cout << "same" << endl;
    else   
        cout << big << endl;
}
