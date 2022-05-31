#include <iostream>
#include "Screen.h"
#include "Statistics.h"

int Statistics::totalRevenue(Screen* pScreen) {
	int sum = 0;
	for (int i = 0; i < pScreen->getRowMax(); i++) {
		for (int j = 0; j < pScreen->getColMax(); j++) {
			if(pScreen->getTicketArray()[i][j].getCheck() == SEAT_COMPLETION_MARK)
			sum += pScreen->getTicketArray()[i][j].getPayAmount();
		}
	}
	return sum;
}

int Statistics::totalSalesCount(Screen* pScreen) {
	int cnt = 0;
	for (int i = 0; i < pScreen->getRowMax(); i++) {
		for (int j = 0; j < pScreen->getColMax(); j++) {
			if (pScreen->getTicketArray()[i][j].getCheck() == SEAT_COMPLETION_MARK)
				cnt += 1;
		}
	}
	return cnt;
}