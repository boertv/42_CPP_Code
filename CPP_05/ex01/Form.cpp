#include "Form.hpp"
#include "Bureaucrat.hpp"

/* CONSTRUCTORS */
Form::Form()
	: _name("Standard Form"), _signed(false), _grade_sign(150), _grade_exec(150) {}

Form::Form(std::string const& name, int const grade_sign, int const grade_exec)
	: _name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_sign > 150 || grade_exec > 150)
		throw (GradeTooLowException());
	if (grade_sign < 1 || grade_exec < 1)
		throw (GradeTooHighException());
}

Form::Form(Form const& src)
	: _name(src._name), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec) {
	*this = src; }

Form::~Form() {}

/* OPERATOR OVERLOADS */
Form& Form::operator=(Form const& rhs)
{
	_signed = rhs._signed;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, Form const& rhs)
{
	stream << rhs.getName() << " (signed: " << rhs.getSigned() << ", grade to sign: " << rhs.getGradeSign();
	stream << ", grade to execute: " << rhs.getGradeExec() << ")";
	return stream;
}

/* GETTERS */
std::string	Form::getName() const {
	return _name; }

bool	Form::getSigned() const {
	return _signed; }

int		Form::getGradeSign() const {
	return _grade_sign; }

int		Form::getGradeExec() const {
	return _grade_exec; }

/* MEMBER FUNCTIONS */
void	Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (_signed)
		return ;
	if (bureaucrat.getGrade() > _grade_sign)
		throw (GradeTooLowException());
	_signed = true;
}


/* EXCEPTION CLASSES */
const char *Form::GradeTooHighException::what() const throw() {
	return "grade too high"; }

const char *Form::GradeTooLowException::what() const throw() {
	return "grade too low"; }
