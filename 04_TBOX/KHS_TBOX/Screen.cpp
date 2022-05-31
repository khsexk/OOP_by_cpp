#include <iostream>
#include <string>
#include "Screen.h"
#include "Pay.h"
using namespace std;

Screen::Screen(string name, int price, int row, int col) {
	strMovieName = name;
	nRowMax = row;
	nColMax = col;
	nTicketPrice = price;
	nCurrentReservedId = 100;
	pSeatArray = new Ticket * [nRowMax];
	for (int r = 0; r < nRowMax; r++) {
		pSeatArray[r] = new Ticket[nColMax];
	}
	for (int i = 0; i < nRowMax; i++) {
		for (int j = 0; j < nColMax; j++) {
			pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
			pSeatArray[i][j].setPayAmount(nTicketPrice);
		}
	}
}
Screen::~Screen() { 
	for (int r = 0; r < nRowMax; r++) {
		delete pSeatArray[r];
	}
}

void Screen::showSeatMap() {
	cout << "\t[ �¼� ���� ��Ȳ]" << endl << "\t";
	for (int i = 0; i < this->nColMax; i++) {
		cout << "[" << i + 1 << "] ";
	}
	cout << endl;

	for (int i = 0; i < this->nRowMax; i++) {
		cout << "[" << i + 1 << "]\t";
		for (int j = 0; j < this->nColMax; j++) {
			cout << "[" << pSeatArray[i][j].getCheck() << "] ";
		}
		cout << endl;
	}
}

// �߰���� 1: �����ϱ�
void Screen::reserveTicket() {
	cout << "\t[�¼� ����]" << endl;
	int row, col;
	cout << "�¼� �� ��ȣ �Է� (1-" << this->nRowMax << ") : ";
	cin >> row;
	cout << "�¼� �� ��ȣ �Է� (1-" << this->nColMax << ") : ";
	cin >> col;

	if (this->pSeatArray[row - 1][col - 1].getCheck() == SEAT_RESERVED_MARK || this->pSeatArray[row - 1][col - 1].getCheck() == SEAT_COMPLETION_MARK) {
		cout << "�̹� ����� �¼��Դϴ�" << endl;
		return;
	}

	this->pSeatArray[row-1][col-1].setReservedID(this->nCurrentReservedId);
	this->pSeatArray[row-1][col-1].setCheck(SEAT_RESERVED_MARK);

	cout << "��[" << row << "] ��[" << col << "] " << this->nCurrentReservedId << "�� ����Ǿ����ϴ�" << endl;
	this->nCurrentReservedId++;
}

// �߰���� 2: ���� ����ϱ�
Ticket* Screen::checkReservedID(int id) {
	for (int i = 0; i < nRowMax; i++) {
		for (int j = 0; j < nColMax; j++) {
			if (pSeatArray[i][j].getCheck() == SEAT_RESERVED_MARK && pSeatArray[i][j].getReservedID() == id)
				return &pSeatArray[i][j];
		}
	}
	return NULL;
}
void Screen::cancelReservation() {
	cout << "\t[�¼� ����]" << endl;
	int id;
	cout << "���� ��ȣ �Է� : ";
	cin >> id;

	Ticket * ticket = this->checkReservedID(id);
	if (ticket == NULL)
		cout << "���� ��ȣ�� �߸��ưų� ����� �¼��� �����ϴ�" << endl;
	else {
		ticket->setReservedID(0);
		ticket->setCheck(SEAT_EMPTY_MARK);
		cout << id << "���� ��ȣ�� ��� ó���Ǿ����ϴ�" << endl;
	}
}

// �߰���� 3: �����ϱ�
void Screen::Payment() {
	cout << "\t[�¼� ���� ����]" << endl;
	int id;
	cout << "���� ��ȣ �Է� : ";
	cin >> id;

	Ticket* ticket = this->checkReservedID(id);
	if (ticket == NULL) {
		cout << "���� ��ȣ�� �߸��ưų� ����� �¼��� �����ϴ�" << endl;
		return;
	}

	cout << "-------------------------------------" << endl;
	cout << "          ���� ��� ����" << endl;
	cout << "-------------------------------------" << endl;
	cout << " 1. ����� ����" << endl;
	cout << " 2. ���� ��ü ����" << endl;
	cout << " 3. ī�� ����" << endl << endl;
	int pay;
	cout << " ���� ��� ����(1-3) : ";
	cin >> pay;

	Pay* p = NULL;

	if (pay == MOBILE_PHONE_PAYMENT) {
		p = new MobilePay(MOBILE_PHONE_INTEREST_RATE);
		cout << endl << "\t[ ����� ���� ] " << endl;

		string hp;
		string name;
		cout << " �ڵ��� ��ȣ �Է�(11�ڸ�) : ";
		cin >> hp;
		cout << " �̸� �Է� : ";
		cin >> name;

		if (hp.length() != 11) {
			cout << " �ڵ��� ��ȣ�� �߸��� �����Դϴ�." << endl;
			return;
		}

		ticket->setPayMethod(MOBILE_PHONE_PAYMENT);
		ticket->setPayAmount(p->charge(ticket->getPayAmount()));
		cout << "����� ������ �Ϸ�Ǿ����ϴ�. : " << ticket->getPayAmount() << endl;

		delete p;
	}
	else if (pay == BANK_TRANSFER_PAYMENT) {
		p = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);
		cout << endl << "\t[ TUK ���� ���� ] " << endl;

		string account;
		string name;
		cout << " ���� ��ȣ �Է�(12�ڸ�) : ";
		cin >> account;
		cout << " �̸� �Է� : ";
		cin >> name;

		if (account.length() != 12) {
			cout << " ���� ��ȣ�� �߸��� �����Դϴ�." << endl;
			return;
		}

		ticket->setPayMethod(BANK_TRANSFER_PAYMENT);
		ticket->setPayAmount(p->charge(ticket->getPayAmount()));
		cout << "TUK ���� ������ �Ϸ�Ǿ����ϴ�. : " << ticket->getPayAmount() << endl;

		delete p;
	}
	else if (pay == CREDIT_CARD_PAYMENT) {
		p = new CardPay(CREDIT_CARD_INTEREST_RATE);
		cout << endl << "\t[ �ſ�ī�� ���� ] " << endl;

		string card;
		string name;
		cout << " ī�� ��ȣ �Է�(12�ڸ�) : ";
		cin >> card;
		cout << " �̸� �Է� : ";
		cin >> name;

		if (card.length() != 12) {
			cout << " ī�� ��ȣ�� �߸��� �����Դϴ�." << endl;
			return;
		}

		ticket->setPayMethod(CREDIT_CARD_PAYMENT);
		ticket->setPayAmount(p->charge(ticket->getPayAmount()));
		cout << "�ſ�ī�� ������ �Ϸ�Ǿ����ϴ�. : " << ticket->getPayAmount() << endl;

		delete p;
	}
	ticket->setCheck(SEAT_COMPLETION_MARK);
}

void Screen::showMovieMenu() {
	cout << "-------------------------------------" << endl;
	cout << "  ��ȭ �޴�: " << this->strMovieName << endl;
	cout << "-------------------------------------" << endl;
	cout << " 1. �� ��ȭ ����" << endl;
	cout << " 2. �¼� ���� ��Ȳ" << endl;
	cout << " 3. �¼� ���� �ϱ�" << endl;
	cout << " 4. �¼� ���� ���" << endl;
	cout << " 5. ���� ���� �ϱ�" << endl;
	cout << " 7. ���� �޴��� �̵�" << endl;
}

void EuropeScreen::showMovieInfo() {
	cout << "-------------------------------------" << endl;
	cout << "           [ " << this->strMovieName <<" ]" << endl;
	cout << "-------------------------------------" << endl;
	cout << " ��ȭ��: ������ȭ 1��" << endl;
	cout << " ���ΰ�: Andrew Dufresne, Ellis Boyd Redding, Samuel Norton" << endl;
	cout << " �ٰŸ�: �˸� �޴� ���� �������� �ص�� �Ƴ��� �� ������ ������ ���Ƿ� �������� �ް� ���ũ �����ҿ� �����Ǵµ�..." << endl;
	cout << " ����: " << this->nTicketPrice << endl << endl;
}

void AsiaScreen::showMovieInfo() {
	cout << "-------------------------------------" << endl;
	cout << "           [ " << this->strMovieName << " ]" << endl;
	cout << "-------------------------------------" << endl;
	cout << " ��ȭ��: �ƽþƿ�ȭ 2��" << endl;
	cout << " ���ΰ�: " << endl;
	cout << " �ٰŸ�: " << endl;
	cout << " ����: " << this->nTicketPrice << endl << endl;
}

void PremiumScreen::showMovieInfo() {
	cout << "-------------------------------------" << endl;
	cout << "           [ " << this->strMovieName << " ]" << endl;
	cout << "-------------------------------------" << endl;
	cout << " ��ȭ��: �����̾���ȭ 3��" << endl;
	cout << " ���ΰ�: " << endl;
	cout << " �ٰŸ�: ..." << endl;
	cout << " ����: " << this->nTicketPrice << endl << endl;
}