#include "AForm.hpp"
#include "Bureaucrat.hpp"
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
	AForm		*form;

	form = new RobotomyRequestForm("human");
	try
	{
		form->execute(tom);
	}
	catch (std::exception const& e)
	{
		std::cout << "caught an exception ! it says " << e.what() << "\n";
	}
	tom.signForm(*form);
	try
	{
		form->execute(Bureaucrat("new hire", 150));
	}
	catch (std::exception const& e)
	{
		std::cout << "caught an exception ! it says " << e.what() << "\n";
	}
	delete form;
	std::cout << "\n";


	form = new RobotomyRequestForm("human");
	run_form(form, tom);

	form = new PresidentialPardonForm("Ted");
	run_form(form, tom);

	form = new ShrubberyCreationForm("BeCentral");
	run_form(form, tom);
}
