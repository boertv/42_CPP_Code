#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
class Bureaucrat;

class AForm
{
private:
	std::string const	_name;
	bool				_signed;
	int const			_grade_sign;
	int const			_grade_exec;

public:
	AForm();
	AForm(std::string const& name, int const grade_sign, int const grade_exec);
	virtual ~AForm();
	AForm(AForm const& src);
	AForm& operator=(AForm const& rhs);

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeSign() const;
	int			getGradeExec() const;

	void			beSigned(Bureaucrat const& bureaucrat);
	void			execute(Bureaucrat const& executor) const;
	virtual void	concrete_execute() const = 0;


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

	class NotSignedException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& stream, AForm const& rhs);

#endif
