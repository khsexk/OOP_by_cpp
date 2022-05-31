#include "TicketBox.h"
#include <iostream>
#include "Screen.h"
#include "Statistics.h"

using namespace std;


TUKoreaTBox::TUKoreaTBox() {
	this->Initialize();
}

TUKoreaTBox::~TUKoreaTBox() {
	delete this->pEuropeScreen;
	delete this->pAsiaScreen;
	delete this->pPremiumScreen;
}

Screen* TUKoreaTBox::selectMenu() {
	cout << "-------------------------------------" << endl;
	cout << "          상영관 메인 메뉴" << endl;
	cout << "-------------------------------------" << endl;
	cout << " 1. 유럽 영화 1관" << endl;
	cout << " 2. 아시아 영화 2관" << endl;
	cout << " 3. 프리미엄 영화 3관" << endl;
	cout << " 9. 통계 관리" << endl << endl;
	cout << " 선택(1~3, 9) 그외 종료: ";
	int select;
	cin >> select;

	switch (select) {
		case 1:
			return this->pEuropeScreen;
		case 2:
			return this->pAsiaScreen;
		case 3:
			return this->pPremiumScreen;
		case 9:
			this->Manage();
			break;
		default:
			cout << "안내를 종료합니다" << endl;
			return NULL;
	}
}

void TUKoreaTBox::Initialize() {
	// Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax))
	pEuropeScreen = new EuropeScreen("쇼생크 탈출", 10000, 10, 10);
	pAsiaScreen = new AsiaScreen("괴물", 12000, 10, 10);
	pPremiumScreen = new PremiumScreen("죽은 시인의 사회", 30000, 6, 6);
}

void TUKoreaTBox::Manage() {
	cout << "-------------------------------------" << endl;
	cout << "             관리자 메뉴" << endl;
	cout << "-------------------------------------" << endl;
	string password;
	cout << " 관리자 비밀번호 입력 : ";
	cin >> password;

	if (!password._Equal(TICKETBOX_MANAGER_PWD)) {
		cout << "잘못된 접근입니다." << endl;
		return;
	}
	cout << endl;
	cout << " 유럽 영화 상영관 결제 금액 : " << Statistics::totalRevenue(this->pEuropeScreen) << endl;

	cout << " 아시아 영화 상영관 결제 금액 : " << Statistics::totalRevenue(this->pAsiaScreen) << endl;
	cout << " 프리미엄 영화 상영관 결제 금액 : " << Statistics::totalRevenue(this->pPremiumScreen) << endl;
	cout << " 전체 티켓 판매량 : " << Statistics::totalSalesCount(this->pEuropeScreen) + Statistics::totalSalesCount(this->pAsiaScreen)  + Statistics::totalSalesCount(this->pPremiumScreen) << endl;
}