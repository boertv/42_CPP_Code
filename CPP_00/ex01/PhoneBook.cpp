#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
	: _size(0), _oldest(0)
{}

int	PhoneBook::next_index()
{
	if (this->_size < 8)
		return this->_size;
	return this->_oldest;
}

void	PhoneBook::newfirstname()
{
	std::string buffer;

	std::cout << "first name: ";
	std::getline(std::cin, buffer);
	while (buffer.empty())
	{
		std::cerr << "something went wrong, try again!" << '\n';
		std::cout << "first name: ";
		std::getline(std::cin, buffer);
	}
	this->_contacts[this->next_index()].setfirst_name(buffer);
}

void	PhoneBook::newlastname()
{
	std::string buffer;

	std::cout << "last name: ";
	std::getline(std::cin, buffer);
	while (buffer.empty())
	{
		std::cerr << "something went wrong, try again!" << '\n';
		std::cout << "last name: ";
		std::getline(std::cin, buffer);
	}
	this->_contacts[this->next_index()].setlast_name(buffer);
}

void	PhoneBook::newnickname()
{
	std::string buffer;

	std::cout << "nickname: ";
	std::getline(std::cin, buffer);
	while (buffer.empty())
	{
		std::cerr << "something went wrong, try again!" << '\n';
		std::cout << "nickname: ";
		std::getline(std::cin, buffer);
	}
	this->_contacts[this->next_index()].setnickname(buffer);
}

static bool	bad_nbr(std::string str)
{
	std::string::iterator it = str.begin();

	while (it != str.end())
	{
		if ((*it < '0' || *it > '9') && *it != '-')
			return true;
		it++;
	}
	return false;
}

void	PhoneBook::newnbr()
{
	std::string buffer;

	std::cout << "phonenumber: ";
	std::getline(std::cin, buffer);
	while(buffer.empty() || bad_nbr(buffer))
	{
		std::cerr << "something went wrong, try again!" << '\n';
		std::cout << "phonenumber: ";
		std::getline(std::cin, buffer);
	}
	this->_contacts[this->next_index()].setnbr(buffer);
}

void	PhoneBook::newsecret()
{
	std::string buffer;

	std::cout << "darkest secret (you can tell me): ";
	std::getline(std::cin, buffer);
	while (buffer.empty())
	{
		std::cerr << "something went wrong (everyone has a secret)" << '\n';
		std::cout << "darkest secret: ";
		std::getline(std::cin, buffer);
	}
	this->_contacts[this->next_index()].setsecret(buffer);
}

void	PhoneBook::add()
{
	std::string buffer;

	if (this->_size == 8)
	{
		std::cout << "are you sure? this will overwrite the oldest contact (y/n)" << '\n';
		std::getline(std::cin, buffer);
		if (!(!buffer.compare("y") || !buffer.compare("yes") || !buffer.compare("1")))
			return;
	}
	std::cout << "making a new contact..." << '\n';
	this->newfirstname();
	this->newlastname();
	this->newnickname();
	this->newnbr();
	this->newsecret();
	this->_contacts[this->next_index()].setindex(this->next_index() + 1);
	if (this->_size == 8)
	{
		this->_oldest++;
		if (this->_oldest >= 8)
			this->_oldest = 0;
	}
	else
		this->_size++;
}

void	PhoneBook::print()
{
	char	i = 0;

	std::cout << " ~~~~~~~~~~~~ PHONEBOOK ~~~~~~~~~~~~~" << '\n';
	std::cout << "+---+----------+----------+----------+" << '\n';
	while (i < this->_size)
	{
		this->_contacts[(int) i].print_line();
		i++;
	}
	std::cout << "+---+----------+----------+----------+" << '\n';
}

void	PhoneBook::search()
{
	if (!this->_size)
	{
		std::cout << "no contacts yet" << '\n';
		return;
	}

	int	i;

	this->print();
	std::cout << "type the index of who you want to look at: ";
	std::cin >> i;
	while(!std::cin.good() || i < 1 || i > this->_size)
	{
		std::cin.clear(std::cin.goodbit);
		std::cin.ignore(10000, '\n');
		std::cerr << "something went wrong, try again!" << '\n';
		std::cout << "make sure the index exists: ";
		std::cin >> i;
	}
	std::cin.ignore(10000, '\n');
	this->_contacts[i - 1].print_full();
}
