#include <iostream>
#include <cstring>
using namespace std;

class Book{
    char *title;
    int price;
public:
    Book(const char* title, int price) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->price = price;
    };
    ~Book() {
        if(title)
            delete [] title;
    };
    void set(char* title, int price){
        if(this->title)
            delete [] this->title;
        this->title = new char[strlen(title)+1];
        strcpy(this->title, title);
        this->price = price;
    };
    void show() {cout << title << ' ' << price << "원" << endl; }

    Book(Book& b);
};

Book::Book(Book& b) { // (2) 정답. 디폴트 복사 생성자
	title = new char[strlen(b.title) + 1];
    strcpy(title, b.title);
    price = b.price;
}

int main() {
    Book cpp("명품c++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
}