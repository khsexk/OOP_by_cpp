#ifndef STATISTCIS_H
#define STATISTCIS_H

#include "Account.h"
#include "ATMachine.h"

class Statistics {

public:
	static int sum(Account* pArray, int size);
	static int average(Account* pArray, int size);
	static int max(Account* pArray, int size);
	static void sort(Account* pArray, int size);
};

#endif 