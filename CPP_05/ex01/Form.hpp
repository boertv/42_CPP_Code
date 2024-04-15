#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
class Bureaucrat;

class Form
{
	std::string const	_name;
	bool				_signed;
	int const			_grade_sign;
	int const			_grade_exec;

public:
	Form();
	Form(std::string const& name, int const grade_sign, int const grade_exec);
	~Form();
	Form(Form const& src);
	Form& operator=(Form const& rhs);

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeSign() const;
	int			getGradeExec() const;

	void	beSigned(Bureaucrat const& bureaucrat);


	class GradeTooHighException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& stream, Form const& rhs);

#endif
