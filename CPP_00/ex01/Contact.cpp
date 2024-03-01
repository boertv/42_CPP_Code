#include "Contact.hpp"

// remove this?
#include <iostream>
//
Contact::Contact()
	: _index(0)
{}

/*
	SETTING FUNCTIONS
*/
void	Contact::setindex(int i)
{
	this->_index = i;
}

void	Contact::setnbr(std::string str)
{
	this->_nbr = str;
}

// returns false if str is empty
bool	Contact::setfirst_name(std::string str)
{
	if (str.empty())
		return false;
	this->_first_name = str;
	return true;
}

// returns false if str is empty
bool	Contact::setlast_name(std::string str)
{
	if (str.empty())
		return false;
	this->_last_name = str;
	return true;
}

// returns false if str is empty
bool	Contact::setnickname(std::string str)
{
	if (str.empty())
		return false;
	this->_nickname = str;
	return true;
}

// returns false if str is empty
bool	Contact::setsecret(std::string str)
{
	if (str.empty())
		return false;
	this->_secret = str;
	return true;
}

static void	print_string_width(std::string str, size_t width)
{
	if (str.size() > width)
	{
		std::cout << str.substr(0, 9) << ".";
		return ;
	}
	while (width > str.size())
	{
		std::cout << " ";
		width--;
	}
	std::cout << str;
}

void	Contact::print_line()
{
	std::cout << "| " << this->_index << " |";
	print_string_width(this->_first_name, 10);
	std::cout << '|';
	print_string_width(this->_last_name, 10);
	std::cout << '|';
	print_string_width(this->_nickname, 10);
	std::cout << '|' << std::endl;
}

void	Contact::print_full()
{
	std::cout << std::endl;
	std::cout << this->_index << ".\t" << this->_first_name << std::endl;
	std::cout << "\t" << this->_last_name << std::endl;
	std::cout << "\t\"" << this->_nickname << '"' << std::endl;
	std::cout << "\t" << this->_nbr << std::endl;
	std::cout << "\t" << "(" << this->_secret << ")" << std::endl;
}
