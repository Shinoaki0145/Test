#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
	float x, y;
public:
	void nhap();
	void xuat();
	float getX();
	float getY();
};

class Line : public Point {
private:
	Point p1, p2;
public:
	void nhap();
	void xuat();
	float khoangCach();
};