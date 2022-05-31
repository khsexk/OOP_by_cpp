#include <iostream>
using namespace std;

int option;
// Bomb
class Bomb {
    string title;
public:
    Bomb(){}
    Bomb(string title) { this->title = title; }
    string getTitle() { return title; }
};

// Weapon
class Weapon {
public:
    virtual void load(Bomb bomb) = 0;
    virtual void use() = 0;

    // virtual 소멸자
    virtual ~Weapon(){}
};

class Tank : public Weapon {  
    Bomb bomb;
public:
    virtual void load(Bomb bomb){
        this->bomb = bomb;
        cout << "탱크 " << this->bomb.getTitle() << "을 적재함" << endl;
    }
    virtual void use(){
        cout << "탱크 " << this->bomb.getTitle() << "을 발사함" << endl;
    }
};

class Fighter : public Weapon {  
    Bomb bomb;
public:
    virtual void load(Bomb bomb){
        this->bomb = bomb;
        cout << "전투기 " << this->bomb.getTitle() << "을 적재함" << endl;
    }
    virtual void use(){
        cout << "전투기 " << this->bomb.getTitle() << "을 발사함" << endl;
    }
};

class Missile : public Weapon {  
    Bomb bomb;
public:
    virtual void load(Bomb bomb){
        this->bomb = bomb;
        cout << "미사일 " << this->bomb.getTitle() << "을 적재함" << endl;
    }
    virtual void use(){
        cout << "미사일 " << this->bomb.getTitle() << "을 발사함" << endl;
    }
};

// Shop
class Shop {
public:
    virtual Weapon* selectItem() = 0;
};

class BattleShop : public Shop {
public:
    virtual Weapon* selectItem() {
        cout << "------------------" << endl;
        cout << "-- 무기 아이템 선택 --" << endl;
        cout << "------------------" << endl;
        cout << "1. 탱크" << endl;
        cout << "2. 전투기" << endl;
        cout << "3. 산탄총" << endl << endl;

        cout << "아이템 선택(1~3) 그외 종료: ";
        cin >> option;

        if(option == 1){
            Tank* tank = new Tank();
            return tank;
        }
        else if(option == 2){
            Fighter* fither = new Fighter() ;
            return fither;
        }
        else if(option == 3){
            Missile* missile = new Missile();
            return missile;
        }
        else{
            Tank* tank = new Tank;
            return tank;
        }
    }
};

// main
int main() {
    BattleShop shop;
    Weapon* weapon;

    while(true){
        weapon = shop.selectItem();
        Bomb bomb("수소탄(hydrogen bomb)");

        if(!(option >= 1 && option <=3)){
            cout << "종료합니다" << endl;
            break;
        }

        weapon->load(bomb);
        weapon->use();

        delete weapon;
    }
    return 0;
}