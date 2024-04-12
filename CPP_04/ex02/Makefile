NAME = abstract_zoo

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -Wshadow -std=c++98 AAnimal.cpp Dog.cpp Cat.cpp main.cpp -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
