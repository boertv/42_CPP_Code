NAME = convert

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -std=c++98 ScalarConverter.cpp main.cpp -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
