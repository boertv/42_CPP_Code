NAME = intern

CPP = c++ -Wall -Wextra -Werror -std=c++98
CPP += Bureaucrat.cpp Intern.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

all:	$(NAME)

$(NAME):
	$(CPP) main.cpp -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
