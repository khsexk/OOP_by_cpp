#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    int price, pages;
public:
    Book(string title="", int price=0, int pages=0){
        this->title = title;
        this->price = price;
        this->pages = pages;
    }
    // Book& operator+=(int b2){
    //     this->price = this->price + b2;
    //     return *this;
    // }
    // Book& operator-=(int b2){
    //     this->price = this->price - b2;
    //     return *this;
    // }

    friend Book operator+=(Book b, int p);
    friend Book operator-=(Book b, int p);

    void show() {
        cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
    }
    string getTitle() {
        return title;
    }
    int getPrice() {
        return price;
    }
    int getPages() {
        return pages;
    }
};

Book operator+=(Book b, int p){
    Book tmp;
    tmp.title = b.getTitle();
    tmp.price = b.getPrice() + p;
    tmp.pages = b.getPages();
    return tmp;
}
Book operator-=(Book b, int p){
    Book tmp;
    tmp.title = b.getTitle();
    tmp.price = b.getPrice() - p;
    tmp.pages = b.getPages();
    return tmp;
}

int main() {
    Book a("청춘", 20000, 300), b("미래", 30000, 500);
    a+=500;
    b-=500;

    a.show();
    b.show();
}