#include "ScalarConverter.hpp"
#include <iomanip>
#include <cmath>

/* CONSTRUCTORS */
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const& src){ (void) src; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs) { (void) rhs; return *this; }

/* convert */
static bool	lit_checker(std::string const& lit)
{
	std::string::const_iterator	it = lit.begin();
	bool						point = false;
	bool						neg = false;

	if (lit.size() == 3 && lit.at(0) == '\'' && lit.at(2) == '\'')
		return true;
	if (*it == '-')
	{
		neg = true;
		it++;
	}
	for ((void) it; it != lit.end(); it++)
	{
		if (isdigit(*it))
			continue ;
		if (*it != '.')
			break ;
		if (point)
			break ;
		point = true;
	}
	if (point && lit.size() - neg == 1)
		return false;
	if (it == lit.end())
		return true;
	if (*it != 'f' || lit.size() - neg == 1 || !point)
		return false;
	if (it + 1 != lit.end())
		return false;
	if (point && lit.size() - neg == 2)
		return false;
	return true;
}

static char	lit_type(std::string const& lit)
{
	if (!lit.size())
		return 0;
	if (!lit.compare("+inff") || !lit.compare("-inff") || !lit.compare("nanf"))
		return 'f';
	if (!lit.compare("+inf") || !lit.compare("-inf") || !lit.compare("nan"))
		return 'd';
	if (!lit_checker(lit))
		return 0;
	if (lit.at(0) == '\'')
		return 'c';
	if (*(lit.end() - 1) == 'f')
		return 'f';
	if (lit.find('.') != std::string::npos)
		return 'd';
	return 'i';
}

static void	assign_value(std::string const& lit, char& type, Value& value)
{
	if (!type)
		return ;
	try
	{
		switch (type)
		{
			case 'c':
				value.c = lit.at(1);
				return ;
			case 'i':
				value.i = std::stoi(lit);
				return ;
			case 'f':
				value.f = std::stof(lit);
				return ;
			case 'd':
				value.d = std::stod(lit);
				return ;
		}
	}
	catch (std::exception const& e)
	{
		type = 0;
	}
}

static void	output_char(Value& value)
{
	std::cout << "char: '" << value.c << "'\n";
	std::cout << "int: " << static_cast<int>(value.c) << "\n";
	std::cout << "float: " << static_cast<float>(value.c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(value.c) << ".0\n";
}

static void	output_int(Value& value)
{
	std::cout << "char: ";
	if (value.i < 0 || value.i > 127)
		std::cout << "impossible";
	else if (!std::isprint(value.i))
		std::cout << "non displayable";
	else
		std::cout << "'" << static_cast<char>(value.i) << "'";
	std::cout << "\n";
	std::cout << "int: " << value.i << "\n";
	std::cout << "float: " << static_cast<float>(value.i) << ".0f\n";
	std::cout << "double: " << static_cast<double>(value.i) << ".0\n";
}

static void	output_float(Value& value)
{
	std::cout << "char: ";
	if (std::isnan(value.f) || std::isinf(value.f) || value.f < 0 || value.f > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<int>(value.f)))
		std::cout << "non displayable";
	else
		std::cout << "'" << static_cast<char>(value.f) << "'";
	std::cout << "\n";
	std::cout << "int: ";
	if (std::isnan(value.f) || std::isinf(value.f) || value.f > INT32_MAX || value.f < INT32_MIN)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value.f);
	std::cout << "\n";
	if (std::abs(value.f) < 1000000)
	{
		float garbage;
		std::cout << std::fixed << std::showpoint << std::setprecision(3);
		if (std::abs(std::modf(value.f, &garbage)) < 0.0005)
			std::cout << std::setprecision(1);
	}
	std::cout << "float: " << value.f << "f\n";
	std::cout << "double: " << static_cast<double>(value.f) << "\n";
}

static void	output_double(Value& value)
{
	std::cout << "char: ";
	if (std::isnan(value.d) || std::isinf(value.d) || value.d < 0 || value.d > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<int>(value.d)))
		std::cout << "non displayable";
	else
		std::cout << "'" << static_cast<char>(value.d) << "'";
	std::cout << "\n";
	std::cout << "int: ";
	if (std::isnan(value.d) || std::isinf(value.d) || value.d > INT32_MAX || value.d < INT32_MIN)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value.d);
	std::cout << "\n";
	if (std::abs(value.d) < 1000000)
	{
		double garbage;
		std::cout << std::fixed << std::showpoint << std::setprecision(3);
		if (std::abs(std::modf(value.d, &garbage)) < 0.0005)
			std::cout << std::setprecision(1);
	}
	std::cout << "float: " << static_cast<float>(value.d) << "f\n";
	std::cout << "double: " << value.d << "\n";
}

static void	output_series(Value& value, char type)
{
	switch (type)
	{
		case 0:
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
			return ;
		case 'c':
			return output_char(value);
		case 'i':
			return output_int(value);
		case 'f':
			return output_float(value);
		case 'd':
			return output_double(value);
	}
}

void	ScalarConverter::convert(std::string const& lit)
{
	Value value;
	char type = lit_type(lit);
	assign_value(lit, type, value);
	output_series(value, type);
}
