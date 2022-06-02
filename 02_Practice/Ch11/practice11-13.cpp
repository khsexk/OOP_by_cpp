#include <iostream>
#include <string>
using namespace std;

istream &question(istream &ins)
{
    cout << "거울아 거울아 누가 제일 예쁘니?" << endl;
    return ins;
}

int main()
{
    string answer;
    cin >> question >> answer;
    cout << "세젤예는 " << answer << endl;
}