#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	static int const	bpoint;

	int	_raw_bits;

public:
	Fixed();
	Fixed(int const i);
	Fixed(float const f);
	Fixed(Fixed const& instance);
	~Fixed();

	Fixed&	operator=(Fixed const& instance);

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;
};

std::ostream&	operator<<(std::ostream& stream, Fixed const& instance);

#endif
