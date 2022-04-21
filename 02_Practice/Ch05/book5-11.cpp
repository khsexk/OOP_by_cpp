#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    int price;
    public:
        Book(const string title, int price);
        Book(Book& book);
        ~Book();
        void set(string title, int price);
        void show() { cout << title << ' ' << price << "원" << endl; }
};

void Book::set(string title, int price){
    this->title = title;
    this->price = price;
}
Book::Book(const string title, int price) { 
    this->title=title; 
    this->price=price; 
}

Book::Book(Book& book){
    this->title = book.title;
    this->price = book.price;
    cout << "복사 완료" << endl ;
}

Book::~Book(){
    cout << this->title << " 소멸" << endl;
}


int main() {
    Book cpp("명품C++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
}