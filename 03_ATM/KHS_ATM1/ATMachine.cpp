#include <iostream>
#include <string>
#include <stdlib.h>

#include "ATMachine.h"
#include "Account.h"

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
	delete [] this->pAcctArray;
	cout << "�ȳ��� ������" << endl;
}

void ATMachine::displayMenu() {
	cout << "-----------------------" << endl;
	cout << "-     TUKOREA BANK    -" << endl;
	cout << "-----------------------" << endl;
	cout << "  1. ���� ����" << endl;
	cout << "  2. ���� ��ȸ" << endl;
	cout << "  3. ���� �Ա�" << endl;
	cout << "  4. ���� ���" << endl;
	cout << "  6. ���� ����" << endl;
	cout << "  9. ���� ����" << endl;
}

void ATMachine::createAccount() {
	cout << endl << "------    ����   ------" << endl;

	string username, passwd;
	cout << "�̸� �Է�: ";
	cin >> username;

	cout << "��ȣ �Է�: ";
	cin >> passwd;

	// ���� �Է��� ���Ѱ��
	if (username == "" || passwd == "")
		cout << "�̸��̳� ��ȣ�� �Է����� �ʾҽ��ϴ�" << endl << endl;
	// ���� ����
	else {
		int id;
		bool flag = false;

		// ����ϰ� �ִ� ���¹�ȣ���� check
		while (!flag) {
			id = rand() % (1000 + 1 - 100) + 100;

			if (!this->usingID[id])
				flag = true;
		}

		this->pAcctArray[nCurrentAccountNum].create(id, 0, username, passwd);
		this->usingID[id] = true;
		this->nCurrentAccountNum++;
		cout << username << "�� " << id << "�� ���¹�ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�." << endl;
	}
}

void ATMachine::checkMoney() {
	cout << endl << "------    ��ȸ   ------" << endl;

	int id;
	string passwd;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;

	cout << "��й�ȣ �Է�: ";
	cin >> passwd;

	int money = -1;
	for (int i = 0; i < this->nCurrentAccountNum; i++) {
		int value = this->pAcctArray[i].check(id, passwd);
		money = (value > money) ? value : money;
	}

	if (money == -1)
		cout << "���¹�ȣ�� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
	else
		cout << "���� �ܾ�: " << money << endl;
}

void ATMachine::closeAccount() {
	cout << endl << "------    ��ȸ   ------" << endl;

	int id;
	string passwd;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;

	cout << "��й�ȣ �Է�: ";
	cin >> passwd;

	int money = -1;
	for (int i = 0; i < this->nCurrentAccountNum; i++) {
		int value = this->pAcctArray[i].check(id, passwd);
		money = (value > money) ? value : money;

		if (money > 0) {
			cout << id << "�� ���¸� ������ �� �����ϴ�. �ܾ�: " << money << endl << endl;
			break;
		}
		else if(money == 0) {
			Account del = this->pAcctArray[i];
			for (int j = i; j < this->nCurrentAccountNum; j++)
				this->pAcctArray[j] = this->pAcctArray[j + 1];
			del.close();
			this->nCurrentAccountNum--;
			cout << id << "�� ���°� �����Ǿ����ϴ�. �����մϴ�." << endl << endl;
			break;
		}
	}

	if (money == -1)
		cout << "���¹�ȣ�� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
}

void ATMachine::depositMoney() {
	cout << endl << "------    �Ա�   ------" << endl;

	int id;
	string passwd;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;

	cout << "��й�ȣ �Է�: ";
	cin >> passwd;

	int money = -1;
	for (int i = 0; i < this->nCurrentAccountNum; i++) {
		int value = this->pAcctArray[i].check(id, passwd);
		money = (value > money) ? value : money;

		if (money >= 0) {
			int dps;
			cout << "�Աݾ� �Է�: ";
			cin >> dps;
			money = this->pAcctArray[i].deposit(id, passwd, dps);

			if (money == -1) 
				cout << "�Ա� ����" << endl;

			cout << "���� �ܾ�: " << money << endl;
			cout << "�Ա� �Ϸ�" << endl << endl;
			this->nMachineBalance += dps;

			break;
		}
			
	}
	if (money == -1)
		cout << "���¹�ȣ�� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
}

void ATMachine::widrawMoney() {
	cout << endl << "------    ���   ------" << endl;

	int id;
	string passwd;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;

	cout << "��й�ȣ �Է�: ";
	cin >> passwd;

	int money = -1;
	for (int i = 0; i < this->nCurrentAccountNum; i++) {
		int value = this->pAcctArray[i].check(id, passwd);
		money = (value > money) ? value : money;

		if (money >= 0) {
			int wtd;
			cout << "��ݾ� �Է�: ";
			cin >> wtd;
			if (this->nMachineBalance >= wtd && money >= wtd) {
				money = this->pAcctArray[i].widraw(id, passwd, wtd);
				cout << "���� �ܾ�: " << money << endl;
				cout << "��� �Ϸ�" << endl << endl;
			}
			else if(this->nMachineBalance < wtd){
				cout << "ATM �⿡ �ܾ��� �����մϴ�" << endl;
			}
			else if (money < wtd) {
				cout << "���¿� �ܾ��� �����մϴ�" << endl;
			}
			break;
		}

	}
	if (money == -1)
		cout << "���¹�ȣ�� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
}