#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct s_stack
{
    int value;
    struct s_stack *suivant;
}t_stack;

typedef struct s_list
{
    struct s_stack *header;
}t_list;

void	swap(t_list *head);
void	push(t_list *dest, t_list *depart);
void	rotate(t_list *tesla);
void	reverse_rotate(t_list *tesla);
void 	ft_depiler(t_list *head);
void 	ft_remplir(t_list *head, int val);
int		is_digit(char *str);
int		check_duplicate(t_list *head, char *str);
int		check_overflow(char *str);
int		check_value(t_list *head, char *str);
void	ft_command(t_list *head_a, t_list *head_b, char *line);
void	ft_get(t_list *header_a, t_list *header_b);
void	ft_exit();