#include <iostream>
#include <string>
#include <stdlib.h>

#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"

using namespace std;

ATMachine::ATMachine(int size, int balance, string password) {
	this->nCurrentAccountNum = 0;
	this->nMaxAccountNum = size;
	this->nMachineBalance = balance;
	this->strManagerPassword = password;
	this->pAcctArray = new Account[nMaxAccountNum];
	this->usingID[1000];
}

ATMachine::~ATMachine() {
	delete[] this->pAcctArray;
	cout << "안녕히 가세요" << endl;
}

void ATMachine::displayMenu() {
	cout << "-----------------------" << endl;
	cout << "-     TUKOREA BANK    -" << endl;
	cout << "-----------------------" << endl;
	cout << "  1. 계좌 개설" << endl;
	cout << "  2. 계좌 조회" << endl;
	cout << "  3. 계좌 입금" << endl;
	cout << "  4. 계좌 출금" << endl;
	cout << "  5. 계좌 이체" << endl;
	cout << "  6. 계좌 해지" << endl;
	cout << "  7. 고객 관리" << endl;
	cout << "  9. 업무 종료" << endl;
}

void ATMachine::createAccount() {
	cout << endl << "------    개설   ------" << endl;

	string username, passwd;
	cout << "이름 입력: ";
	cin >> username;

	cout << "암호 입력: ";
	cin >> passwd;

	// 정보 입력을 안한경우
	if (username == "" || passwd == "")
		cout << "이름이나 암호를 입력하지 않았습니다" << endl << endl;
	// 계좌 생성
	else {
		int id;
		bool flag = false;

		// 사용하고 있는 계좌번호인지 check
		while (!flag) {
			id = rand() % (1000 + 1 - 100) + 100;

			if (!this->usingID[id])
				flag = true;
		}

		this->pAcctArray[nCurrentAccountNum].create(id, 0, username, passwd);
		this->usingID[id] = true;
		this->nCurrentAccountNum++;
		cout << username << "님 " << id << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다." << endl;
	}
}

void ATMachine::checkMoney() {
	cout << endl << "------    조회   ------" << endl;

	int id;
	string passwd;
	cout << "계좌번호 입력: ";
	cin >> id;

	cout << "비밀번호 입력: ";
	cin >> passwd;

	int money = -1;
	for (int i = 0; i < this->nCurrentAccountNum; i++) {
		int value = this->pAcctArray[i].check(id, passwd);
		money = (value > money) ? value : money;
	}

	if (money == -1)
		cout << "계좌번호나 비밀번호가 일치하지 않습니다." << endl;
	else
		cout << "현재 잔액: " << money << endl;
}

void ATMachine::closeAccount() {
	cout << endl << "------    조회   ------" << endl;

	int id;
	string passwd;
	cout << "계좌번호 입력: ";
	cin >> id;

	cout << "비밀번호 입력: ";
	cin >> passwd;

	int money = -1;
	for (int i = 0; i < this->nCurrentAccountNum; i++) {
		int value = this->pAcctArray[i].check(id, passwd);
		money = (value > money) ? value : money;

		if (money > 0) {
			cout << id << "번 계좌를 해지할 수 없습니다. 잔액: " << money << endl << endl;
			break;
		}
		else if (money == 0) {
			Account del = this->pAcctArray[i];
			for (int j = i; j < this->nCurrentAccountNum; j++)
				this->pAcctArray[j] = this->pAcctArray[j + 1];
			del.close();
			this->nCurrentAccountNum--;
			this->usingID[id] = false;
			cout << id << "번 계좌가 해지되었습니다. 감사합니다." << endl << endl;
			break;
		}
	}

	if (money == -1)
		cout << "계좌번호나 비밀번호가 일치하지 않습니다." << endl;
}

void ATMachine::depositMoney() {
	cout << endl << "------    입금   ------" << endl;

	int id;
	string passwd;
	cout << "계좌번호 입력: ";
	cin >> id;

	cout << "비밀번호 입력: ";
	cin >> passwd;

	int money = -1;
	for (int i = 0; i < this->nCurrentAccountNum; i++) {
		int value = this->pAcctArray[i].check(id, passwd);
		money = (value > money) ? value : money;

		if (money >= 0) {
			int dps;
			cout << "입금액 입력: ";
			cin >> dps;
			money = this->pAcctArray[i].deposit(id, passwd, dps);

			if (money == -1)
				cout << "입금 실패" << endl;

			cout << "현재 잔액: " << money << endl;
			cout << "입금 완료" << endl << endl;
			this->nMachineBalance += dps;

			break;
		}

	}
	if (money == -1)
		cout << "계좌번호나 비밀번호가 일치하지 않습니다." << endl;
}

void ATMachine::widrawMoney() {
	cout << endl << "------    출금   ------" << endl;

	int id;
	string passwd;
	cout << "계좌번호 입력: ";
	cin >> id;

	cout << "비밀번호 입력: ";
	cin >> passwd;

	int money = -1;
	for (int i = 0; i < this->nCurrentAccountNum; i++) {
		int value = this->pAcctArray[i].check(id, passwd);
		money = (value > money) ? value : money;

		if (money >= 0) {
			int wtd;
			cout << "출금액 입력: ";
			cin >> wtd;
			if (this->nMachineBalance >= wtd && money >= wtd) {
				money = this->pAcctArray[i].widraw(id, passwd, wtd);
				cout << "현재 잔액: " << money << endl;
				cout << "출금 완료" << endl << endl;
				this->nMachineBalance -= wtd;
			}
			else if (this->nMachineBalance < wtd) {
				cout << "ATM 기에 잔액이 부족합니다" << endl;
			}
			else if (money < wtd) {
				cout << "계좌에 잔액이 부족합니다" << endl;
			}
			break;
		}

	}
	if (money == -1)
		cout << "계좌번호나 비밀번호가 일치하지 않습니다." << endl;
}

void ATMachine::transfer() {
	cout << endl << "------    이체   ------" << endl;

	int id, tId, money;
	string passwd;
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
	cin >> passwd;

	cout << "이체계좌 입력: ";
	cin >> tId;
	cout << "이체금액 입력: ";
	cin >> money;

	int flag = -1;
	int idx;
	for (int i = 0; i < this->nCurrentAccountNum; i++) {
		int value = this->pAcctArray[i].check(id, passwd);

		if (value > flag) {
			// 잔액 부족 처리
			if (money > value) {
				cout << "잔액이 부족합니다" << endl;
				return;
			}
			flag = value;
			idx = i;
			break;
		}
	}

	// 계좌 및 비밀번호 인증 처리
	if (flag == -1) {
		cout << "계좌번호나 비밀번호가 일치하지 않습니다." << endl;
		return;
	}

	int value;
	for (int i = 0; i < this->nCurrentAccountNum; i++) {
		value = this->pAcctArray[i].deposit(tId, money);

		if (value != -1) {
			int balance = this->pAcctArray[idx].widraw(id, passwd, money);
			cout << "현재 잔액: " << balance << endl;
			cout << "이체 완료" << endl;
			break;
		}
	}
	if (value == -1)
		cout << "상대 계좌가 없는 계좌입니다" << endl;
}

bool ATMachine::isManager(string password) {
	if (password == "admin")
		return true;
	return false;
}

void ATMachine::displayReport() {

}

void ATMachine::managerMode() {
	cout << endl << "------    관리   ------" << endl;

	string passwd;
	cout << "관리자 비밀번호 입력: ";
	cin >> passwd;

	if (!isManager(passwd)) {
		cout << "비밀번호가 맞지 않습니다" << endl;
		return;
	}
	cout << endl << "관리자입니다." << endl;
	cout << "-----------------------" << endl;
	cout << "ATM 현재 잔고: \t" << this->nMachineBalance << "원" << endl;
	cout << "ATM 잔고 총액: \t" << Statistics::sum(this->pAcctArray, this->nCurrentAccountNum) << "원 (총" << this->nCurrentAccountNum << "명)" << endl;
	cout << "ATM 잔고 평균: \t" << Statistics::average(this->pAcctArray, this->nCurrentAccountNum) << "원" << endl;
	cout << "ATM 잔고 최고: \t" << Statistics::max(this->pAcctArray, this->nCurrentAccountNum) << "원" << endl;

	cout << "-----------------------" << endl;
	cout << "-    고객 계좌 목록   -" << endl;
	cout << "-----------------------" << endl;
	Statistics::sort(this->pAcctArray, this->nCurrentAccountNum);
	cout << endl;
}