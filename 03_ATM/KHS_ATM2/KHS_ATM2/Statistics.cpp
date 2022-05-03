#include "Account.h"
#include "Statistics.h"
#include "ATMachine.h"
#include <iostream>

using namespace std;

int Statistics::sum(Account* pArray, int size) {
	int result = 0;
	for (int i = 0; i < size; i++) 
		result += pArray[i].getBalance();
	return result;
}

int Statistics::average(Account* pArray, int size) {
	int total = Statistics::sum(pArray, size);
	return total/size;
}

int Statistics::max(Account* pArray, int size) {
	int result = 0;
	for (int i = 0; i < size; i++)
		result = pArray[i].getBalance() > result ? pArray[i].getBalance() : result;
	return result;
}

void Statistics::sort(Account* pArray, int size) {

	// Bubble Sort Algorithm »ç¿ë
	int idx=0;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 1; j < size - i; j++) {
			Account save = pArray[idx];

			if (save.getBalance() < pArray[j].getBalance()) {
				pArray[idx] = pArray[j];
				pArray[j] = save;
			}
			idx++;
		} // for_j
		idx = 0;
	} // for_i


	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << pArray[i].getAccountName() << "\t" << pArray[i].getAcctID() << "\t" << pArray[i].getBalance() << "¿ø" << endl;
	}
}