#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point	a(0 ,5);
	Point	b(5, 0);
	Point	c(5, 10);
	Point	point(4.75f, 5);

	std::cout << "the point (" << point.getX() << ", " << point.getY() << ") IS ";
	if (!bsp(a, b, c, point))
		std::cout << "NOT ";
	std::cout << "in the triangle\n";
}
