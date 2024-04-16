#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	std::string	_target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm(PresidentialPardonForm const& src);
	~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);

	void	concrete_execute() const;
};

#endif
