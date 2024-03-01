#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	Contact	_contacts[8];
	char	_size;
	char	_oldest;

	int		next_index();
	void	newfirstname();
	void	newlastname();
	void	newnickname();
	void	newnbr();
	void	newsecret();

	void	print();

	public:
	PhoneBook();

	void	add();
	void	search();
};

#endif
