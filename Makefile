# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhebbat <yhebbat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 16:02:13 by yhebbat           #+#    #+#              #
#    Updated: 2021/07/16 18:51:54 by yhebbat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re

NAME = push_swap
NAME_BONUS = checker

SRC =	push_swap.c operations.c to_check.c pile.c get_next_line.c\
		utils.c big_sort.c move_to_b.c move_to_a.c get_next_line_utils.c\
		move_to_a_helper.c small_inst.c find_to_move.c \
		mini_sort.c free.c mini_sort_helper.c initialize.c last_moves_a.c
SRC_BONUS =	checker.c get_next_line.c get_next_line_utils.c pile.c \
			operations.c to_check.c utils.c free.c
OBJECT = $(SRC:.c=.o)
OBJECT_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror  $(SRC) -o $(NAME)
	@echo "✅✅✅"

bonus:
	@gcc -Wall -Wextra -Werror  -fsanitize=address -g $(SRC_BONUS) -o $(NAME_BONUS)
	@echo "🎁🎁🎁"

clean:
	@rm -f $(OBJECT) $(OBJECT_BONUS)
	@echo "🗑️ 🗑️ 🗑️"
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "🚮🚮🚮"
re: fclean all
