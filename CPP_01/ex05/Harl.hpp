#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class	Harl
{
	void	debug();
	void	info();
	void	warning();
	void	error();

	struct Couple
	{
		const char*	level;
		void (Harl::*function)();

		Couple(char const* level, void (Harl::*function)());
	};

public:

	void	complain(std::string level);
};

#endif
