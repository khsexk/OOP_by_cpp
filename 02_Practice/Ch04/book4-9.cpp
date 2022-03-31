#include <iostream>
#include <string>

using namespace std;

class Person {
    string name;
    string tel;
    public:
        string getName() { return name; }
        string getTel() { return tel; }
        void set(string name, string tel);
};

void Person::set(string name, string tel){
    this->name = name;
    this->tel = tel;
}

int main() {
    cout << "이름과 전화번호를 입력하시오." << endl;

    Person *profile = new Person[3];

    for(int i=0 ; i<3 ; i++){
        cout << "사람 " << i+1 << ">> ";
        string info;
        getline(cin, info, '\n');
        
        int idx = info.find(' ', 0);

        profile[i].set(info.substr(0, idx), info.substr(idx+1));
    } // for_i
    cout << "모든 사람의 이름은 ";
    for(int i=0 ; i<3 ; i++){
        cout << profile[i].getName() << " ";
    }
    cout << endl << "전화번호 검색합니다. 이름을 입력하세요 >> ";
    string find;
    getline(cin, find, '\n');

    for(int i=0 ; i<3 ; i++){
        if(profile[i].getName() == find){
            find = profile[i].getTel();
            break;
        }
    }

    cout << "전화 번호는 " << find << endl;
    
}