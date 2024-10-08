#include "Ex3.h"

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

void Point::setX(float x) {
	this->x = x;
}

void Point::setY(float y) {
	this->y = y;
}

bool checkPoint(vector<Point> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i].getX() == v[j].getX() && v[i].getY() == v[j].getY()) {
				return false;
			}
		}
	}
	return true;
}

void Rectangle::nhap() {
	vector<Point> v;

	do {
		v.clear();
		cout << "Nhap diem p1: " << endl;
		p1.nhap();
		cout << "Nhap diem p2: " << endl;
		p2.nhap();
		cout << "Nhap diem p3: " << endl;
		p3.nhap();
		cout << "Nhap diem p4: " << endl;
		p4.nhap();

		v.push_back(p1);
		v.push_back(p2);
		v.push_back(p3);
		v.push_back(p4);

		if (!checkPoint(v)) {
			cout << "Co diem bi trung. Hay nhap lai" << endl;
		}
	} while (!checkPoint(v));
}

void Rectangle::xuat() {
	cout << endl;
	cout << "Diem p1: ";
	p1.xuat();
	cout << "Diem p2: ";
	p2.xuat();
	cout << "Diem p3: ";
	p3.xuat();
	cout << "Diem p4: ";
	p4.xuat();
}

bool cmpPoint(pair<float, float> a, pair<float, float> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

void Rectangle::setForRec() {
	vector<pair<float, float>> v;
	v.push_back(make_pair(p1.getX(), p1.getY()));
	v.push_back(make_pair(p2.getX(), p2.getY()));
	v.push_back(make_pair(p3.getX(), p3.getY()));
	v.push_back(make_pair(p4.getX(), p4.getY()));

	sort(v.begin(), v.end(), cmpPoint);
	swap(v[1], v[2]);
	swap(v[2], v[3]);

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			p1.setX(v[i].first);
			p1.setY(v[i].second);
		}
		else if (i == 1) {
			p2.setX(v[i].first);
			p2.setY(v[i].second);
		}
		else if (i == 2) {
			p3.setX(v[i].first);
			p3.setY(v[i].second);
		}
		else {
			p4.setX(v[i].first);
			p4.setY(v[i].second);
		}
	}
}

bool Rectangle::isRectangle() {
	float d12 = sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
	float d23 = sqrt(pow(p2.getX() - p3.getX(), 2) + pow(p2.getY() - p3.getY(), 2));
	float d34 = sqrt(pow(p3.getX() - p4.getX(), 2) + pow(p3.getY() - p4.getY(), 2));
	float d41 = sqrt(pow(p4.getX() - p1.getX(), 2) + pow(p4.getY() - p1.getY(), 2));
	float d13 = sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2));
	float d24 = sqrt(pow(p2.getX() - p4.getX(), 2) + pow(p2.getY() - p4.getY(), 2));
	return d12 == d34 && d23 == d41 && d13 == d24;
}

float Rectangle::chuVi() {
	float d12 = sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
	float d23 = sqrt(pow(p2.getX() - p3.getX(), 2) + pow(p2.getY() - p3.getY(), 2));
	return 2 * (d12 + d23);
}

float Rectangle::dienTich() {
	float d12 = sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
	float d23 = sqrt(pow(p2.getX() - p3.getX(), 2) + pow(p2.getY() - p3.getY(), 2));
	return d12 * d23;
}

int main() {
	Rectangle r;

	r.nhap();
	r.setForRec();

	cout << "\nHinh tu giac theo thu tu cac dinh lan luot tu goc trai tren la: ";
	r.xuat();

	if (r.isRectangle()) {
		cout << "\nDay la hinh chu nhat" << endl;
		cout << "Chu vi: " << r.chuVi() << endl;
		cout << "Dien tich: " << r.dienTich() << endl;
	}
	else {
		cout << "Day khong phai hinh chu nhat" << endl;
	}

	return 0;
}