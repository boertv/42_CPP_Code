NAME = bct

all:	$(NAME)

$(NAME):
	c++ -g -o0 -Wall -Wextra -Werror -std=c++98 BitcoinExchange.cpp main.cpp -o $(NAME)

clean:
	@rm -rf $(NAME).dSYM

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
