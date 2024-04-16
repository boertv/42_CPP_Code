#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* CONSTRUCTORS */
Intern::Intern() {}

Intern::Intern(Intern const& src) { this->operator=(src); }

Intern::~Intern() {}

Intern&	Intern::operator=(Intern const& src) { (void) src; return *this;}

/* MEMBER FUNCTIONS */
AForm	*Intern::makeForm(std::string form_name, std::string target) const
{
	std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int			i;
	AForm		*res;

	for(i = 0; i < 3; i++)
		if (!form_name.compare(names[i]))
			break ;
	switch (i)
	{
		case 0:
			res = new ShrubberyCreationForm(target);
			break ;
		case 1:
			res = new RobotomyRequestForm(target);
			break ;
		case 2:
			res = new PresidentialPardonForm(target);
			break ;

		default:
			std::cout << "intern couldn't find a form with the name '" << form_name << "'.\n";
			return nullptr;
	}
	std::cout << "Intern creates " << form_name << ".\n";
	return res;
}
