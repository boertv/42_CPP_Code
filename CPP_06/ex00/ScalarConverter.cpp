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

static void	output(char const& value)
{
	std::cout << "char: '" << value << "'\n";
	std::cout << "int: " << static_cast<int>(value) << "\n";
	std::cout << "float: " << static_cast<float>(value) << ".0f\n";
	std::cout << "double: " << static_cast<double>(value) << ".0\n";
}

static void	output(int const& value)
{
	std::cout << "char: ";
	if (value < 0 || value > 127)
		std::cout << "impossible";
	else if (!std::isprint(value))
		std::cout << "non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << "\n";
	std::cout << "int: " << value << "\n";
	std::cout << std::fixed << std::showpoint << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << "f\n";
	std::cout << "double: " << static_cast<double>(value) << "\n";
}

static void	output(float const& value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << "\n";
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) || value > INT32_MAX || value < INT32_MIN)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << "\n";
	if (std::abs(value) < 1000000)
	{
		float garbage;
		std::cout << std::fixed << std::showpoint << std::setprecision(3);
		if (std::abs(std::modf(value, &garbage)) < 0.0005)
			std::cout << std::setprecision(1);
	}
	std::cout << "float: " << value << "f\n";
	std::cout << "double: " << static_cast<double>(value) << "\n";
}

static void	output(double const& value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << "\n";
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) || value > INT32_MAX || value < INT32_MIN)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << "\n";
	if (std::abs(value) < 1000000)
	{
		double garbage;
		std::cout << std::fixed << std::showpoint << std::setprecision(3);
		if (std::abs(std::modf(value, &garbage)) < 0.0005)
			std::cout << std::setprecision(1);
	}
	std::cout << "float: " << static_cast<float>(value) << "f\n";
	std::cout << "double: " << value << "\n";
}

static void	output_series(Value& value, char type)
{
	switch (type)
	{
		case 0:
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
			return ;
		case 'c':
			return output(value.c);
		case 'i':
			return output(value.i);
		case 'f':
			return output(value.f);
		case 'd':
			return output(value.d);
	}
}

void	ScalarConverter::convert(std::string const& lit)
{
	Value value;
	char type = lit_type(lit);
	assign_value(lit, type, value);
	output_series(value, type);
}
