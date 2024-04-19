NAME = real_type

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -std=c++98 Base.cpp A.cpp B.cpp C.cpp main.cpp -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
