NAME = bsp

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -std=c++98 Fixed.cpp Point.cpp bsp.cpp main.cpp -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
