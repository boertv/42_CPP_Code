#include "ShrubberyCreationForm.hpp"
#include <fstream>

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
	this->AForm::operator=(rhs);
	return *this;
}

/* MEMBER FUNCTIONS */
void	ShrubberyCreationForm::concrete_execute() const
{
	std::ofstream	outfile;

	outfile.open(std::string(_target).append("_shrubbery"), std::ofstream::app);
	if (outfile.fail())
	{
		std::cerr << "opening of file " << std::string(_target).append("_shrubbery") << " failed\n";
		return ;
	}
	outfile << "\n               ,@@@@@@@,\n";
	outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	outfile << "       |o|        | |         | |\n";
	outfile << "       |.|        | |         | |\n";
	outfile << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	outfile.close();
}
