#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    char name[100];
    char address[100];
    int age;

    cout << "이름은? ";
    cin.getline(name, 100);

    cout << "주소는? ";
    cin.getline(address, 100);

    cout << "나이는? ";
    cin >> age;

    cout << name << ", " << address << ", " << age << "세 \n";

    return 0;
}
