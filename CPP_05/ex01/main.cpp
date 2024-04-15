#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Form	form("Important Form", 50, 50);
	Form	copy(form);
	std::cout << form << '\n';

	Bureaucrat("	jeff", 150).signForm(form);
	Bureaucrat("	bob", 51).signForm(form);
	Bureaucrat("	ed", 50).signForm(form);
	Bureaucrat("	winston", 49).signForm(form);
	std::cout << '\n';

	try
	{
		copy.beSigned(Bureaucrat("noob", 150));
	}
	catch (std::exception const& e)
	{
		std::cout << "caught an error! it says: " << e.what() << '\n';
	}
}
