#include "Pay.h"

int CardPay::charge(int amount) {
	return amount * (this->interest + 1);
}


int BankTransfer::charge(int amount) {
	return amount * (this->interest + 1);
}


int MobilePay::charge(int amount){
	return amount * (this->interest + 1);
}