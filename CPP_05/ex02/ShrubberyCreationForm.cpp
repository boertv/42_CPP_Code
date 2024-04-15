#include "ShrubberyCreationForm.hpp"

/* CONSTRUCTORS */
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("shrubbery creation", 145, 137), _target("forest") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	: AForm("shrubbery creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
	: AForm("shrubbery creation", 145, 137) {
	this->operator=(src); }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* OPERATOR OVERLOADS */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	_target = rhs._target;
	this->AForm::operator=(rhs);	// DOES THIS WORK ??   EVEN THE 'rhs' == AForm ??
	return *this;
}

/* MEMBER FUNCTIONS */
void	ShrubberyCreationForm::concrete_execute(Bureaucrat const& executor) const
{
	// create some nice shrubbery :)
}
