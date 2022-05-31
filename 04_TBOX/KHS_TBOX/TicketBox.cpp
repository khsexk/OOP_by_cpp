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
	cout << "          �󿵰� ���� �޴�" << endl;
	cout << "-------------------------------------" << endl;
	cout << " 1. ���� ��ȭ 1��" << endl;
	cout << " 2. �ƽþ� ��ȭ 2��" << endl;
	cout << " 3. �����̾� ��ȭ 3��" << endl;
	cout << " 9. ��� ����" << endl << endl;
	cout << " ����(1~3, 9) �׿� ����: ";
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
			cout << "�ȳ��� �����մϴ�" << endl;
			return NULL;
	}
}

void TUKoreaTBox::Initialize() {
	// Screen(��ȭ����, Ƽ�ϰ���, �¼�(nRowMax), �¼�(nColMax))
	pEuropeScreen = new EuropeScreen("���ũ Ż��", 10000, 10, 10);
	pAsiaScreen = new AsiaScreen("����", 12000, 10, 10);
	pPremiumScreen = new PremiumScreen("���� ������ ��ȸ", 30000, 6, 6);
}

void TUKoreaTBox::Manage() {
	cout << "-------------------------------------" << endl;
	cout << "             ������ �޴�" << endl;
	cout << "-------------------------------------" << endl;
	string password;
	cout << " ������ ��й�ȣ �Է� : ";
	cin >> password;

	if (!password._Equal(TICKETBOX_MANAGER_PWD)) {
		cout << "�߸��� �����Դϴ�." << endl;
		return;
	}
	cout << endl;
	cout << " ���� ��ȭ �󿵰� ���� �ݾ� : " << Statistics::totalRevenue(this->pEuropeScreen) << endl;

	cout << " �ƽþ� ��ȭ �󿵰� ���� �ݾ� : " << Statistics::totalRevenue(this->pAsiaScreen) << endl;
	cout << " �����̾� ��ȭ �󿵰� ���� �ݾ� : " << Statistics::totalRevenue(this->pPremiumScreen) << endl;
	cout << " ��ü Ƽ�� �Ǹŷ� : " << Statistics::totalSalesCount(this->pEuropeScreen) + Statistics::totalSalesCount(this->pAsiaScreen)  + Statistics::totalSalesCount(this->pPremiumScreen) << endl;
}