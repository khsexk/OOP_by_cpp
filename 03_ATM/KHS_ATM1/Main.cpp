#include <iostream>
#include "ATMachine.h"

using namespace std;

int main() {
    int select;

    ATMachine atm(100, 50000, "admin");

    while (1) {
        atm.displayMenu();
        cout << "�޴��� �����ϼ���: ";
        try {
            cin >> select;
            cout << endl;

            switch (select) {
                // ���� ����
                case 1:
                    atm.createAccount();
                    break;
                // ���� ����
                case 2:
                    atm.checkMoney();
                    break;
                // �Ա�
                case 3:
                    atm.depositMoney();
                    break;
                // ���
                case 4:
                    atm.widrawMoney();
                    break;
                // ���� ����
                case 6:
                    atm.closeAccount();
                    break;
                case 9:
                    atm.~ATMachine();
                    return 0;
                default:
                    cout << "��ȣ Ȯ�� �� �ٽ� �Է��ϼ���." << endl;
            }
        } catch (...) {
            cout << "��ȣ Ȯ�� �� �ٽ� �Է��ϼ���." << endl;
        }
    }
    return 0;
}