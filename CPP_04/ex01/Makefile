NAME = huge_zoo

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -Wshadow -std=c++98 Animal.cpp Dog.cpp Cat.cpp Brain.cpp main.cpp -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
