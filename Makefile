SRC =	checker.c get_next_line.c get_next_line_utils.c pile.c operations.c to_check.c

OBJECT = $(SRC:.c=.o)

NAME = checker.a

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@gcc checker.c $(NAME) -o checker

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all