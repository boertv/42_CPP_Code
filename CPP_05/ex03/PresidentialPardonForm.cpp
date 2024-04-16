#include "PresidentialPardonForm.hpp"

/* CONSTRUCTORS */
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("presidential pardon", 25, 5), _target("criminal") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: AForm("presidential pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src)
	: AForm("presidential pardon", 25, 5) {
	this->operator=(src); }

PresidentialPardonForm::~PresidentialPardonForm() {}

/* OPERATOR OVERLOADS */
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	_target = rhs._target;
	this->AForm::operator=(rhs);
	return *this;
}

/* MEMBER FUNCTIONS */
void	PresidentialPardonForm::concrete_execute() const
{
	std::cout << _target << " has graciously been pardoned by the most esteemed Zaphod Beeblebrox.\n";
}
