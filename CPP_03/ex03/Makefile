NAME = diamond

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -Wshadow -std=c++98 ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
