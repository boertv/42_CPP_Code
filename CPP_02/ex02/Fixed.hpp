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
	bool	operator>(Fixed const& instance) const;
	bool	operator<(Fixed const& instance) const;
	bool	operator>=(Fixed const& instance) const;
	bool	operator<=(Fixed const& instance) const;
	bool	operator==(Fixed const& instance) const;
	bool	operator!=(Fixed const& instance) const;
	Fixed	operator+(Fixed const& instance) const;
	Fixed	operator-(Fixed const& instance) const;
	Fixed	operator*(Fixed const& instance) const;
	Fixed	operator/(Fixed const& instance) const;
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static Fixed&		min(Fixed& a, Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static Fixed const&	min(Fixed const&a, Fixed const&b);
	static Fixed const&	max(Fixed const&a, Fixed const&b);

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;
};

std::ostream&	operator<<(std::ostream& stream, Fixed const& instance);

#endif
