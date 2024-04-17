#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	run_form(AForm *form, Bureaucrat const& bur)
{
	if (!form)
		return ;
	bur.signForm(*form);
	bur.executeForm(*form);
	delete form;
	std::cout << '\n';
}

int	main()
{
	Bureaucrat	tom("Tom", 5);
	Intern		tommy;
	AForm		*form;

	form = tommy.makeForm("nope", "lmao");
	run_form(form, tom);
	std::cout << "\n";

	form = tommy.makeForm("robotomy request", "human");
	run_form(form, tom);

	form = tommy.makeForm("presidential pardon", "Ted");
	run_form(form, tom);

	form = tommy.makeForm("shrubbery creation", "bocal");
	run_form(form, tom);
}
