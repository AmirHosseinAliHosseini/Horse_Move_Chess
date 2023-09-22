#pragma once

class Point
{
public:
	Point(const int x, const int y);

	Point& operator+=(const Point& pr);
	bool operator==(const Point& pr) const;
	bool isValid(const int& size) const;

	int getX() { return x; }
	int getY() { return y; }
private:
	int x, y;
};
