#include <iostream>
#include "03_ATM/Account.h"
#include "03_ATM/ATMachine.h"

using namespace std;

int main() {
    int select;

    ATMachine atm(100, 50000, "admin");

    while(1){
        atm.displayMenu();
        cout << "메뉴를 선택하세요: ";
        cin >> select;
        cout << endl;

        switch(select) {
            // 계좌 개설
            case 1:
                atm.createAccount();
                break;
            // 계좌 조희
            case 2:
                atm.checkMoney();
                break;
            // 입급
            case 3:
                atm.depositMoney();
                break;
            // 출금
            case 4:
                atm.widrawMoney();
                break;
            // 계좌 해지
            case 6:
                atm.closeAccount();
                break;
            case 9:
                cout << "안녕히 가세요" << endl;
                return 0;
            default:
                cout << "번호 확인 후 다시 입력하세요." << endl;
        }
    }
    return 0;
}