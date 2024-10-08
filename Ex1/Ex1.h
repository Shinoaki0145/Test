#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class Phanso {
private:
	int tu;
	int mau;
public:
	void nhap();
	void xuatPhanSo();
	void xuatThapPhan();
	int UCLN(int a, int b);
	void dinhdaiphanso();
	void rutgon();
	Phanso cong(Phanso ps);
	Phanso tru(Phanso ps);
	Phanso nhan(Phanso ps);
	Phanso chia(Phanso ps);
};