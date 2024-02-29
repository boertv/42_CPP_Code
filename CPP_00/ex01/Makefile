NAME = phonebook

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -std=c++98 Contact.cpp PhoneBook.cpp main.cpp -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
