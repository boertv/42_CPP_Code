#include "Point.hpp"


/*
CONSTRUCTORS, DESTRUCTOR
*/
Point::Point()
	: x(0), y(0) {}

Point::Point(Fixed const& x, Fixed const& y)
	: x(x), y(y) {}

Point::Point(Point const& instance)
	: x(instance.getX()), y(instance.getY()) {}

Point::~Point() {}


/*
GETTERS AND SETTERS
*/
Fixed const&	Point::getX() const {
	return this->x; }

Fixed const&	Point::getY() const {
	return this->y; }


/*
OPERATOR OVERLOADS
*/
Point&	Point::operator=(Point const& rhs)
{
	const_cast <Fixed&> (this->x) = rhs.getX();
	const_cast <Fixed&> (this->y) = rhs.getY();
	return *this;
}
