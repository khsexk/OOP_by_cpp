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
	cout << "\t[ 좌석 예약 현황]" << endl << "\t";
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

// 추가기능 1: 예약하기
void Screen::reserveTicket() {
	cout << "\t[좌석 예약]" << endl;
	int row, col;
	cout << "좌석 행 번호 입력 (1-" << this->nRowMax << ") : ";
	cin >> row;
	cout << "좌석 열 번호 입력 (1-" << this->nColMax << ") : ";
	cin >> col;

	if (this->pSeatArray[row - 1][col - 1].getCheck() == SEAT_RESERVED_MARK || this->pSeatArray[row - 1][col - 1].getCheck() == SEAT_COMPLETION_MARK) {
		cout << "이미 예약된 좌석입니다" << endl;
		return;
	}

	this->pSeatArray[row-1][col-1].setReservedID(this->nCurrentReservedId);
	this->pSeatArray[row-1][col-1].setCheck(SEAT_RESERVED_MARK);

	cout << "행[" << row << "] 열[" << col << "] " << this->nCurrentReservedId << "로 예약되었습니다" << endl;
	this->nCurrentReservedId++;
}

// 추가기능 2: 예약 취소하기
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
	cout << "\t[좌석 예약]" << endl;
	int id;
	cout << "예약 번호 입력 : ";
	cin >> id;

	Ticket * ticket = this->checkReservedID(id);
	if (ticket == NULL)
		cout << "예약 번호가 잘못됐거나 예약된 좌석이 없습니다" << endl;
	else {
		ticket->setReservedID(0);
		ticket->setCheck(SEAT_EMPTY_MARK);
		cout << id << "예약 번호가 취소 처리되었습니다" << endl;
	}
}

// 추가기능 3: 결제하기
void Screen::Payment() {
	cout << "\t[좌석 예약 결제]" << endl;
	int id;
	cout << "예약 번호 입력 : ";
	cin >> id;

	Ticket* ticket = this->checkReservedID(id);
	if (ticket == NULL) {
		cout << "예약 번호가 잘못됐거나 예약된 좌석이 없습니다" << endl;
		return;
	}

	cout << "-------------------------------------" << endl;
	cout << "          결제 방식 선택" << endl;
	cout << "-------------------------------------" << endl;
	cout << " 1. 모바일 결제" << endl;
	cout << " 2. 은행 이체 결제" << endl;
	cout << " 3. 카드 결제" << endl << endl;
	int pay;
	cout << " 결제 방식 선택(1-3) : ";
	cin >> pay;

	Pay* p = NULL;

	if (pay == MOBILE_PHONE_PAYMENT) {
		p = new MobilePay(MOBILE_PHONE_INTEREST_RATE);
		cout << endl << "\t[ 모바일 결제 ] " << endl;

		string hp;
		string name;
		cout << " 핸드폰 번호 입력(11자리) : ";
		cin >> hp;
		cout << " 이름 입력 : ";
		cin >> name;

		if (hp.length() != 11) {
			cout << " 핸드폰 번호가 잘못된 형식입니다." << endl;
			return;
		}

		ticket->setPayMethod(MOBILE_PHONE_PAYMENT);
		ticket->setPayAmount(p->charge(ticket->getPayAmount()));
		cout << "모바일 결제가 완료되었습니다. : " << ticket->getPayAmount() << endl;

		delete p;
	}
	else if (pay == BANK_TRANSFER_PAYMENT) {
		p = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);
		cout << endl << "\t[ TUK 은행 결제 ] " << endl;

		string account;
		string name;
		cout << " 은행 번호 입력(12자리) : ";
		cin >> account;
		cout << " 이름 입력 : ";
		cin >> name;

		if (account.length() != 12) {
			cout << " 은행 번호가 잘못된 형식입니다." << endl;
			return;
		}

		ticket->setPayMethod(BANK_TRANSFER_PAYMENT);
		ticket->setPayAmount(p->charge(ticket->getPayAmount()));
		cout << "TUK 은행 결제가 완료되었습니다. : " << ticket->getPayAmount() << endl;

		delete p;
	}
	else if (pay == CREDIT_CARD_PAYMENT) {
		p = new CardPay(CREDIT_CARD_INTEREST_RATE);
		cout << endl << "\t[ 신용카드 결제 ] " << endl;

		string card;
		string name;
		cout << " 카드 번호 입력(12자리) : ";
		cin >> card;
		cout << " 이름 입력 : ";
		cin >> name;

		if (card.length() != 12) {
			cout << " 카드 번호가 잘못된 형식입니다." << endl;
			return;
		}

		ticket->setPayMethod(CREDIT_CARD_PAYMENT);
		ticket->setPayAmount(p->charge(ticket->getPayAmount()));
		cout << "신용카드 결제가 완료되었습니다. : " << ticket->getPayAmount() << endl;

		delete p;
	}
	ticket->setCheck(SEAT_COMPLETION_MARK);
}

void Screen::showMovieMenu() {
	cout << "-------------------------------------" << endl;
	cout << "  영화 메뉴: " << this->strMovieName << endl;
	cout << "-------------------------------------" << endl;
	cout << " 1. 상영 영화 정보" << endl;
	cout << " 2. 좌석 예약 현황" << endl;
	cout << " 3. 좌석 예약 하기" << endl;
	cout << " 4. 좌석 예약 취소" << endl;
	cout << " 5. 예약 결제 하기" << endl;
	cout << " 7. 메인 메뉴로 이동" << endl;
}

void EuropeScreen::showMovieInfo() {
	cout << "-------------------------------------" << endl;
	cout << "           [ " << this->strMovieName <<" ]" << endl;
	cout << "-------------------------------------" << endl;
	cout << " 영화관: 유럽영화 1관" << endl;
	cout << " 주인공: Andrew Dufresne, Ellis Boyd Redding, Samuel Norton" << endl;
	cout << " 줄거리: 촉망 받던 은행 부지점장 앤디는 아내와 그 애인을 살해한 혐의로 종신형을 받고 쇼생크 교도소에 수감되는데..." << endl;
	cout << " 가격: " << this->nTicketPrice << endl << endl;
}

void AsiaScreen::showMovieInfo() {
	cout << "-------------------------------------" << endl;
	cout << "           [ " << this->strMovieName << " ]" << endl;
	cout << "-------------------------------------" << endl;
	cout << " 영화관: 아시아영화 2관" << endl;
	cout << " 주인공: " << endl;
	cout << " 줄거리: " << endl;
	cout << " 가격: " << this->nTicketPrice << endl << endl;
}

void PremiumScreen::showMovieInfo() {
	cout << "-------------------------------------" << endl;
	cout << "           [ " << this->strMovieName << " ]" << endl;
	cout << "-------------------------------------" << endl;
	cout << " 영화관: 프리미엄영화 3관" << endl;
	cout << " 주인공: " << endl;
	cout << " 줄거리: ..." << endl;
	cout << " 가격: " << this->nTicketPrice << endl << endl;
}