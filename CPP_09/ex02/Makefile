NAME = PmergeMe

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -std=c++98 PmergeMe.cpp main.cpp -o $(NAME)

clean:
	@rm -rf $(NAME).dSYM
	@rm -rf .vscode

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
