#include <iostream>
#include <string>
#include "Screen.h"
#include "TicketBox.h"
using namespace std;


int main() {
	TUKoreaTBox tBox;
	Screen* screen = NULL;
	bool bScreenMenu = true;
	int select = 0;
	
	tBox.Initialize();
	while (1) {
		if (bScreenMenu) {
			screen = tBox.selectMenu();
			bScreenMenu = false;
			if(!screen) return 0;
		}
		screen->showMovieMenu();
		cout << "메뉴를 선택하세요: ";
		cin >> select;
		cout << endl;

		switch (select) {
			case 1:
				screen->showMovieInfo();
				break;
			case 2:
				screen->showSeatMap();
				break;
			case 3:
				screen->reserveTicket();
				break;
			case 4:
				screen->cancelReservation();
				break;
			case 5:
				screen->Payment();
				break;
			case 7:
				bScreenMenu = true;
				break;
		}
	} // while-true
	return 0;
}