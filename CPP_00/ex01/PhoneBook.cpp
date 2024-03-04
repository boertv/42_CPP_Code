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

/* ADD CONTACT INFO */
void	PhoneBook::newfirstname()
{
	std::string buffer;

	std::cout << "\tfirst name: ";
	std::getline(std::cin, buffer);
	while (buffer.empty())
	{
		std::cerr << "something went wrong, try again!" << '\n';
		std::cout << "\tfirst name: ";
		std::getline(std::cin, buffer);
	}
	this->_contacts[this->next_index()].setfirst_name(buffer);
}

void	PhoneBook::newlastname()
{
	std::string buffer;

	std::cout << "\tlast name: ";
	std::getline(std::cin, buffer);
	while (buffer.empty())
	{
		std::cerr << "something went wrong, try again!" << '\n';
		std::cout << "\tlast name: ";
		std::getline(std::cin, buffer);
	}
	this->_contacts[this->next_index()].setlast_name(buffer);
}

void	PhoneBook::newnickname()
{
	std::string buffer;

	std::cout << "\tnickname: ";
	std::getline(std::cin, buffer);
	while (buffer.empty())
	{
		std::cerr << "something went wrong, try again!" << '\n';
		std::cout << "\tnickname: ";
		std::getline(std::cin, buffer);
	}
	this->_contacts[this->next_index()].setnickname(buffer);
}

static bool	is_bad_nbr(std::string str)
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

	std::cout << "\tphonenumber: ";
	std::getline(std::cin, buffer);
	while(buffer.empty() || is_bad_nbr(buffer))
	{
		std::cerr << "something went wrong, try again!" << '\n';
		std::cout << "\tphonenumber: ";
		std::getline(std::cin, buffer);
	}
	this->_contacts[this->next_index()].setnbr(buffer);
}

void	PhoneBook::newsecret()
{
	std::string buffer;

	std::cout << "\tdarkest secret: ";
	std::getline(std::cin, buffer);
	while (buffer.empty())
	{
		std::cerr << "something went wrong (everyone has a secret)" << '\n';
		std::cout << "\tdarkest secret (you can tell me): ";
		std::getline(std::cin, buffer);
	}
	this->_contacts[this->next_index()].setsecret(buffer);
}

/* FRONT FUNCTIONS */
void	PhoneBook::add()
{
	std::string buffer;

	if (this->_size == 8)
	{
		std::cout << "are you sure? this will overwrite the contact at index " << (int) this->_oldest + 1 << '\n';
		std::getline(std::cin, buffer);
		if (!(!buffer.compare("y") || !buffer.compare("yes")))
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
		std::cout << "give an index between 1 and " << (int) this->_size << ": ";
		std::cin >> i;
	}
	std::cin.ignore(10000, '\n');
	this->_contacts[i - 1].print_full();
}
