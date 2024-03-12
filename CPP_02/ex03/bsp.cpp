#include "Point.hpp"

#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	w1, w2;

	w1 = ((a.getX() * (c.getY() - a.getY())) + ((point.getY() - (a.getY())) * (c.getX() - a.getX())) - (point.getX() * (c.getY() - a.getY())))
			/ (((b.getY() - a.getY()) * (c.getX() - a.getX())) - ((b.getX() - a.getX()) * (c.getY() - a.getY())));
	w2 = ((point.getY() - a.getY()) - (w1 * (b.getY() - a.getY()))) / (c.getY() - a.getY());
	if (w1 <= 0 || w2 <= 0)
		return false;
	if (w1 + w2 >= Fixed(0.99f))
		return false;
	return true;
}

// w1 = Ax(Cy - Ay) + (py - Ay)(Cx - Ax) - px(Cy - Ay)
//		/
//		(By - Ay)(Cx - Ax) - (Bx - Ax)(Cy - Ay)

// w2 = (py - Ay) - w1(By - Ay) / Cy - Ay
