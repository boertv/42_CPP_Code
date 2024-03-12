#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	static int const	bpoint;

	int	_raw_bits;

public:
	Fixed();
	Fixed(Fixed const& instance);
	~Fixed();

	Fixed&	operator=(Fixed const& instance);

	int		getRawBits() const;
	void	setRawBits(int const raw);
};

#endif
