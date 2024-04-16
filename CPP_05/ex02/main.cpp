#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	run_form(AForm *form, Bureaucrat const& bur)
{
	bur.signForm(*form);
	bur.executeForm(*form);
	delete form;
	std::cout << '\n';
}

int	main()
{
	Bureaucrat	tom("Tom", 5);

	AForm	*form = new RobotomyRequestForm("human");
	run_form(form, tom);

	form = new RobotomyRequestForm("human");
	run_form(form, tom);

	form = new RobotomyRequestForm("human");
	run_form(form, tom);

	form = new RobotomyRequestForm("human");
	run_form(form, tom);

	form = new RobotomyRequestForm("human");
	run_form(form, tom);

	form = new PresidentialPardonForm("Ted");
	run_form(form, tom);

	form = new ShrubberyCreationForm("BeCentral");
	run_form(form, tom);
}
