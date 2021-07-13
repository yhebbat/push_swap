SRC1 =	checker.c get_next_line.c get_next_line_utils.c pile.c operations.c to_check.c utils.c
SRC2 =	push_swap.c get_next_line.c get_next_line_utils.c pile.c operations.c to_check.c utils.c
OBJECT = $(SRC1:.c=.o)

NAME = checker.a

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC1) 
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@gcc -Wall -Wextra -Werror $(SRC2) libft.a -o push_swap
	@gcc checker.c $(NAME) -fsanitize=address -g3 -o checker

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all
