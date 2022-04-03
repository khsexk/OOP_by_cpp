#include "Account.h"

inline bool Account::authenticate(int id, string passwd) {
	if (this->nID == id && this->strPassword == passwd)
		return 1;
	else
		return 0;
}

Account::Account() {
	this->nID = 0;
	this->nBalance = 0;
}

void Account::create(int id, int money, string name, string password) {
	this->nID = id;
	this->nBalance = 0;
	this->strAccountName = name;
	this->strPassword = password;
}

void Account::close() {}

int Account::check(int id, string password) {
	int flag = this->authenticate(id, password);

	if (!flag)
		return AUTHENTIFICATION_FAIL;
	else
		return this->nBalance;
}

int Account::deposit(int id, string password, int money) {
	int flag = this->authenticate(id, password);

	if (!flag)
		return AUTHENTIFICATION_FAIL;
	else {
		this->nBalance += money;
		return this->nBalance;
	}
}
int Account::widraw(int id, string password, int money) {
	int flag = this->authenticate(id, password);

	if (!flag)
		return AUTHENTIFICATION_FAIL;
	else {
		this->nBalance -= money;
		return this->nBalance;
	}
}