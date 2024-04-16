#ifndef INTERN_H
# define INTERN_H

# include <iostream>
class AForm;

class Intern
{
public:
	Intern();
	Intern(Intern const& src);
	~Intern();
	Intern&	operator=(Intern const& rhs);

	AForm	*makeForm(std::string form_name, std::string target) const;
};

#endif
