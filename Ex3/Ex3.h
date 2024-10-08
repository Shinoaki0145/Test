#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
private:
	float x, y;
public:
	void nhap();
	void xuat();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	friend bool checkPoint(vector<Point>);
};

class Rectangle : public Point {
private:
	Point p1, p2, p3, p4;
public:
	void nhap();
	void xuat();
	void setForRec();
	friend bool cmpPoint(pair<float, float> a, pair<float, float> b);
	bool isRectangle();
	float chuVi();
	float dienTich();
};