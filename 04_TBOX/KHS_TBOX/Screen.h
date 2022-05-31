#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include "Ticket.h"
using namespace std;

class Screen {
protected:
	int nTicketPrice;
	int nRowMax, nColMax;
	int nCurrentReservedId;
	Ticket** pSeatArray;
	string strMovieName;
	Ticket* checkReservedID(int id);
public:
	Screen(string name, int price, int row, int col);
	~Screen();
	void showSeatMap();
	virtual void showMovieMenu();
	virtual void showMovieInfo() = 0;
	void reserveTicket();
	void cancelReservation();
	int getTicketPrice() { return nTicketPrice; }
	void Payment(); // 결제하기
	int getRowMax() { return nRowMax; }
	int getColMax() { return nColMax; }
	Ticket** getTicketArray() { return pSeatArray; }
};

class EuropeScreen : public Screen {
public:
	EuropeScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
	void showMovieInfo();
};

class AsiaScreen : public Screen {
public:
	AsiaScreen(string name, int price, int row, int col): Screen(name, price, row, col) {}
	void showMovieInfo();
};

class PremiumScreen : public Screen {
public:
	PremiumScreen(string name, int price, int row, int col): Screen(name, price, row, col) {}
	void showMovieInfo();
};
 
#endif 