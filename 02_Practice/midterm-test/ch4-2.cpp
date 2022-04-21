#include <iostream>
using namespace std;

class Person{
    int id;
    double weight;
    string name;
public:
    // 중복생성자
    // Person();
    // Person(int id, string name);
    // Person(int id, string name, double weight);

    // 디폴트 매개변수
    Person(int id=1, string name="Grace", double weight=20.5){
        this->id = id;
        this->name = name;
        this->weight = weight;
    }
    void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

// Person::Person(){
//     id = 1;
//     name = "Grace";
//     weight = 20.5;
// }
// Person::Person(int id, string name){
//     this->id = id;
//     this->name = name;
//     weight = 20.5;
// }
// Person::Person(int id, string name, double weight){
//     this->id = id;
//     this->name = name;
//     this->weight = weight;
// }

int main(){
    Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);

    grace.show();
    ashley.show();
    helen.show();
}