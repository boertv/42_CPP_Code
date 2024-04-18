#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <iostream>

class ScalarConverter
{
	ScalarConverter();
	ScalarConverter(ScalarConverter const& src);
	~ScalarConverter();
	ScalarConverter& operator=(ScalarConverter const& rhs);

public:
	static void convert(std::string const& lit);
};

union Value
{
	char	c;
	int		i;
	float	f;
	double	d;
};

#endif
