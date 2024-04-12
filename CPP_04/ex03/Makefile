NAME = materia

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -Wshadow -std=c++98 AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
