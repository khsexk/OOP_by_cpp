#include <iostream>
#include <string>
using namespace std;

class Person{
    string name;
    string tel;
public:
    Person() { }
    string getName() { return name; }
    string getTel() { return tel; }
    void set(string name, string tel);
};

void Person::set(string name, string tel){
    this->name = name;
    this->tel = tel;
}

int main() {
    Person p[3];
    cout << "이름과 전화번호를 입력해 주세요" << endl;

    for(int i=0 ; i<3 ; i++){
        string name, hp;
        cout << "사람 " << i+1 << ">> ";
        cin >> name >> hp;
        p[i].set(name, hp);
    }
    cout << "모든 사람의 이름은 " << p[0].getName() << " " << p[1].getName() << " "<< p[2].getName() << endl;

    string fName;
    cout << "전화번호 검색합니다. 이름을 입력하세요>> ";
    cin >> fName;

    for(int j=0 ; j<3 ; j++){
        if(p[j].getName() == fName){
            cout << "전화번호는 " << p[j].getTel();
            break;
        }
    }
}