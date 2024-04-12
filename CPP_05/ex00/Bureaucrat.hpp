#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>

class Bureaucrat
{
	std::string const	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const& src);
	~Bureaucrat();
	Bureaucrat&		operator=(Bureaucrat const& rhs);

	std::string	getName() const;
	int			getGrade() const;
	void		promote();
	void		demote();


	class	GradeTooHighException : public std::exception
	{
	public:
		const char	*what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		const char	*what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& stream, Bureaucrat const& rhs);


#endif
