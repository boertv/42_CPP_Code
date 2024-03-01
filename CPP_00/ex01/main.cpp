#include <iostream>
#include "PhoneBook.hpp"

// returns false if EXIT was typed
bool	handle_input(PhoneBook *book)
{
	std::string	buffer;

	std::getline(std::cin, buffer);
	while (!std::cin.good())
	{
		std::cerr << "something went wrong, try again!" << '\n';
		std::getline(std::cin, buffer);
	}
	if (!buffer.compare("EXIT"))
		return false;
	if (!buffer.compare("ADD"))
		book->add();
	else if (!buffer.compare("SEARCH"))
		book->search();
	else
		std::cout << "type one of: ADD, SEARCH, EXIT" << '\n';
	return true;
}

int	main()
{
	PhoneBook book;

	std::cout << "what would you like to do?" << '\n';
	std::cout << "type one of: ADD, SEARCH, EXIT" << '\n';
	while (handle_input(&book))
		std::cout << '\n' << "what would you like to do?" << '\n';
}

// test emtpy inputs (and NULL?)
