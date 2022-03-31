#ifndef ATMACHINE_H
#define ATMACHINE_H

using std::string;

#define NEGATIVE_ATM_BALANCE -10

class ATMachine {
    private:
        Account * pAcctArray;   // 동적 생성된 계좌 배열 포인터
        int nMachineBalance;    // ATM 잔고
        int nMaxAccountNum;     // 동적 생성된 계좌 배열 크기
        int nCurrentAccountNum; // 개설된 고객 계좌 수
        string strManagerPassword;  // 관리자 비밀번호
    public:
        ATMachine(int size, int balance, string password);
        ~ATMachine();

        void displayMenu();
        void createAccount();
        void closeAccount();
        void checkMoney();
        void depositMoney(); // 계좌 입금
        void widrawMoney(); // 계좌 출금
};

#endif