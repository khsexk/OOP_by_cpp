#ifndef ATMACHINE_H
#define ATMACHINE_H

#include <string>
#include "ATMachine.h"
#include "Account.h"

using std::string;

#define NEGATIVE_ATM_BALANCE -10

class ATMachine {
private:
    Account* pAcctArray;   // ���� ������ ���� �迭 ������
    int nMachineBalance;    // ATM �ܰ�
    int nMaxAccountNum;     // ���� ������ ���� �迭 ũ��
    int nCurrentAccountNum; // ������ �� ���� ��
    string strManagerPassword;  // ������ ��й�ȣ
    bool usingID[];     // ��� ���¸� ����ִ� �迭 (�߰�)
    bool isManager(string password);
    void displayReport();
public:
    ATMachine(int size, int balance, string password);
    ~ATMachine();

    void displayMenu();
    void createAccount();
    void closeAccount();
    void checkMoney();
    void depositMoney(); // ���� �Ա�
    void widrawMoney(); // ���� ���
    void transfer();
    void managerMode();
};

#endif