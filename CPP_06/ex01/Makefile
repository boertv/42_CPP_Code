NAME = serialize

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -std=c++98 Data.cpp Serializer.cpp main.cpp -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
