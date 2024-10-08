#include "Ex2.h"
// nhan dau buiii
void Point::nhap() {
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}

void Point::xuat() {
	cout << "(" << x << ", " << y << ")" << endl;
}

float Point::getX() {
	return x;
}

float Point::getY() {
	return y;
}

void Line::nhap() {
	cout << "Nhap diem dau: " << endl;
	p1.nhap();
	cout << "Nhap diem cuoi: " << endl;
	p2.nhap();
}

void Line::xuat() {
	cout << endl;
	p1.xuat();
	p2.xuat();
	cout << "Do dai duong thang: " << khoangCach() << endl;
}

float Line::khoangCach() {
	return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
}

int main() {
	Line l;
	l.nhap();
	l.xuat();
	
	return 0;
}