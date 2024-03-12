#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
	Fixed const	x;
	Fixed const	y;

public:
	Point();
	Point(Fixed const& x, Fixed const& y);
	Point(Point const& instance);
	~Point();

	Fixed const&	getX() const;
	Fixed const&	getY() const;

	Point&	operator=(Point const& rhs);
};

#endif
