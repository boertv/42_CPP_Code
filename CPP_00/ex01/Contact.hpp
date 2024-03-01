#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

// index of 0 means empty conact
class Contact
{
	int			_index;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_nbr;
	std::string	_secret;

	public:
	Contact();

	void	setindex(int i);
	void	setnbr(std::string str);
	bool	setfirst_name(std::string str);
	bool	setlast_name(std::string str);
	bool	setnickname(std::string str);
	bool	setsecret(std::string str);

	void	print_line();
	void	print_full();
};

#endif
