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

	static int const	harl_size;
	static char const*	lvl_arr[];

	void			complain(std::string const& level);
	static int		gauge(std::string const& level);
};

#endif
