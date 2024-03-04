NAME = bank_test

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -std=c++98 Account.cpp tests.cpp -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
