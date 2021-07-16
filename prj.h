#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define MINA 0
#define MAXA 1
#define LENA 2
#define LENB 3
#define NBA 4
#define NBB 5
#define NBAB 6
#define FROMUPA 7
#define FROMUPB 8
#define NBRINSA 9
#define NBRINSB 10
#define NBRINSAB 11
#define UPA 12
#define UPB 13
#define maxim INT_MAX

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *suivant;
    struct s_stack *preced;
}t_stack;

typedef struct s_list
{
    struct s_stack *header;
    struct s_stack *footer;
}t_list;

void	swap(t_list *head);
void	push(t_list *dest, t_list *depart);
void	rotate(t_list *tesla);
void	reverse_rotate(t_list *tesla);
void 	ft_depiler(t_list *head);
void 	ft_remplir(t_list *head, int val, int index);
int		is_digit(char *str);
int		check_duplicate(t_list *head, char *str);
int		check_overflow(char *str);
int		check_value(t_list *head, char *str);
void	ft_command(t_list *head_a, t_list *head_b, char *line);
void	ft_get(t_list *header_a, t_list *header_b);
void	ft_exit(void);
int     ft_checker(t_list *head);
void	ft_free(t_list *head);
void	ft_compare1(t_list *head_a, t_list *head_b, char *line);
void	ft_compare2(t_list *head_a, t_list *head_b, char *line);
void	ft_compare3(t_list *head_a, t_list *head_b, char *line);
void	ft_free(t_list *head);

void ft_depiler2(t_stack **a);
//static void	ft_putstr(char *c);

long long	ft_overflowhelper(char *str);

void	ft_putstr(char *c);
void	ft_exit();
void	ft_compare1(t_list *head_a, t_list *head_b, char *line);
void	ft_compare2(t_list *head_a, t_list *head_b, char *line);
void	ft_compare3(t_list *head_a, t_list *head_b, char *line);
void	ft_command(t_list *head_a, t_list *head_b, char *line);
void	ft_get(t_list *header_a, t_list *header_b);
void	ft_free(t_list *head);

void	ft_sorted(int max, t_list *head, int *t);
void	index_more_than_five_numbers(t_list *head_a, t_list *head_b, int size_a);

void	ft_sortt(t_list *head);

void	ft_helperthree(t_list *head, t_stack *a);

void	ft_helpertthree(t_list *head, t_stack *a);

void	ft_sorttt(t_list *head);

void	ft_sortttt(t_list *head, t_list *head_b);

void	helperfive(t_list *head, int i);

void	ft_sort5(t_list *head, t_list *head_b);

void	fromlinkedlist_to_table(t_stack *a, int *t, int max);

void	ft_sorted(int max, t_list *head, int *t);

void		size(t_list *head_a, t_list *head_b, int *t);

void	min_instructions(int *t, int nb);

void	number_of_instructions(int *t, int v, int nb);

void	ft_min(int *t, t_stack *a);

void	ft_max(int *t, t_stack *a, int *v);

void	ft_mid(int *t, t_stack *a, t_stack *b);

void	find_element(int *t, t_list *head_a, t_stack *b);

void	from_upa(int *t, t_list *head_a, t_list *head_b);

void	from_upb(int *t, t_list *head_a, t_list *head_b);

void	from_upab(int *t, t_list *head_a, t_list *head_b);

void	from_downab(int *t, t_list *head_a, t_list *head_b);

void	actions(int *t, t_list *head_a, t_list *head_b);

void	initialiser(int *t);

void	push_to_a(t_list *head_a, t_list *head_b);

void	push_to_b(t_list *head_a, t_list *head_b);

void	ft_rotate_a(t_list *head, int i, int fromdown);

void	last_actions(t_list *head, int size_a);

void	index_more_than_five_numbers(t_list *head_a, t_list *head_b, int size_a);

void	ft_sort(t_list *head_a, t_list *head_b);

void	ft_pushswap(t_list *head, t_list *head_b, int ac);

void	fill_a(t_list *header, int ac, char **av);

int		find_min(t_list *head);