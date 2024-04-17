#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	{
		try
		{
			Bureaucrat("wrong", 0);
		}
		catch(const std::exception& e)
		{
			std::cout << "Tried to create a bureaucrat but " << e.what() << '\n';
		}
		try
		{
			Bureaucrat("wrong", 1000);
		}
		catch(const std::exception& e)
		{
			std::cout << "Tried to create a bureaucrat but " << e.what() << '\n';
		}
	}
std::cout << "\n";

	{
		Bureaucrat eric("Eric", 100);

		try
		{
			std::cout << eric << "\n";
			eric.promote();
			std::cout << eric << "\n";
			eric.demote();
			eric.demote();
			std::cout << eric << "\n";
		}
		catch (std::exception& e)
		{
			std::cout << "Caught an error! It says: " << e.what() << "\n";
		}
	}
std::cout << "\n";

	{
		Bureaucrat jeff("Jeff", 150);
		try
		{
			jeff.demote();
			std::cout << jeff << "\n";
		}
		catch (std::exception& e)
		{
			std::cout << "Tried to demote a bureaucrat but " << e.what() << "\n";
		}
	}
std::cout << "\n";

	{
		Bureaucrat jeff("Jeff", 1);
		try
		{
			jeff.promote();
			std::cout << jeff << "\n";
		}
		catch (std::exception& e)
		{
			std::cout << "Tried to promote a bureaucrat but " << e.what() << "\n";
		}
	}
}
