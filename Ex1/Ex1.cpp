#include "Ex1.h"

void Phanso::nhap() {
	cout << "Nhap tu so: ";
	cin >> tu;

	do {
		cout << "Nhap mau so: ";
		cin >> mau;
		if (mau == 0)
			cout << "Mau so phai khac 0. Nhap lai." << endl;
	} while (mau == 0);

	dinhdaiphanso();
	rutgon();
}

void Phanso::xuatPhanSo() {
	if (tu == 0) {
		cout << "0" << endl;
		return;
	}
	else if (mau == 1) {
		cout << tu << endl;
		return;
	}
	cout << tu << mau << endl;
}

void Phanso::xuatThapPhan() {
	cout << fixed << setprecision(2) << (double)tu / mau << endl;
}

int Phanso::UCLN(int a, int b) {
	if (b == 0) return a;
	return UCLN(b, a % b);
}

void Phanso::dinhdaiphanso() {
	if (mau < 0) {
		tu = -tu;
		mau = -mau;
	}
}

void Phanso::rutgon() {
	int ucln = UCLN(tu, mau);
	tu = tu / ucln;
	mau = mau / ucln;
}

Phanso Phanso::cong(Phanso ps) {
	Phanso kq;

	kq.tu = tu * ps.mau + mau * ps.tu;
	kq.mau = mau * ps.mau;

	kq.rutgon();
	kq.dinhdaiphanso();

	return kq;
}

Phanso Phanso::tru(Phanso ps) {
	Phanso kq;

	kq.tu = tu * ps.mau - mau * ps.tu;
	kq.mau = mau * ps.mau;

	kq.rutgon();
	kq.dinhdaiphanso();

	return kq;
}

Phanso Phanso::nhan(Phanso ps) {
	Phanso kq;

	kq.tu = tu * ps.tu;
	kq.mau = mau * ps.mau;

	kq.rutgon();
	kq.dinhdaiphanso();

	return kq;
}

Phanso Phanso::chia(Phanso ps) {
	Phanso kq;

	kq.tu = tu * ps.mau;
	kq.mau = mau * ps.tu;

	kq.rutgon();
	kq.dinhdaiphanso();

	return kq;
}

int main() {
	Phanso ps1, ps2;

	ps1.nhap();
	ps2.nhap();

	cout << "Phan so 1: " << endl;
	ps1.xuatPhanSo();
	ps2.xuatThapPhan();

	cout << "Phan so 2: " << endl;
	ps1.xuatPhanSo();
	ps2.xuatThapPhan();

	Phanso kq = ps1.cong(ps2);
	cout << "Phan so 1 cong phan so 2: " << endl;
	kq.xuatPhanSo();
	kq.xuatThapPhan();

	cout << "Phan so 1 tru phan so 2: " << endl;
	kq = ps1.tru(ps2);
	kq.xuatPhanSo();
	kq.xuatThapPhan();

	cout << "Phan so 1 nhan phan so 2: " << endl;
	kq = ps1.nhan(ps2);
	kq.xuatPhanSo();
	kq.xuatThapPhan();

	cout << "Phan so 1 chia phan so 2: " << endl;
	kq = ps1.chia(ps2);
	kq.xuatPhanSo();
	kq.xuatThapPhan();

	return 0;
}