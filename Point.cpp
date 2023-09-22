#include "Point.h"

Point::Point(const int x_, const int y_) :x(x_), y(y_) {}

Point& Point::operator+=(const Point& pr)
{
	x += pr.x;
	y += pr.y;

	return *this;
}

bool Point::operator==(const Point& pr) const
{
	if (x == pr.x && y == pr.y)
		return true;
	return false;
}

bool Point::isValid(const int& size) const
{
	if (x < 0 || y < 0 || x >= size || y >= size)
		return false;
	return true;
}