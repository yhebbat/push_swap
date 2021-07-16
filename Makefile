NAME = push_swap
NAME_BONUS = checker

SRC =	push_swap.c get_next_line.c get_next_line_utils.c pile.c \
		operations.c to_check.c utils.c big_sort.c move_to_b.c move_to_a.c \
		move_to_a_helper.c small_inst.c initialize.c last_moves_a.c find_to_move.c \
		mini_sort.c free.c mini_sort_helper.c
SRC_BONUS =	checker.c get_next_line.c get_next_line_utils.c pile.c \
			operations.c to_check.c utils.c free.c
OBJECT = $(SRC:.c=.o)
OBJECT_BONUS = $(SRC_BONUS:.c=.o)


all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror libft.a  $(SRC) -o $(NAME)
	@echo "✅✅✅"

bonus:
	@gcc -Wall -Wextra -Werror libft.a  $(SRC_BONUS) -o $(NAME_BONUS)
	@echo "🎁🎁🎁"

clean:
	@rm -f $(OBJECT) $(OBJECT_BONUS)
	@echo "🗑️ 🗑️ 🗑️"
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "🚮🚮🚮"
re: fclean all
