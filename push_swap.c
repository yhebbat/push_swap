#include "prj.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void		ft_exit()
{
	printf("Error\n");
	exit(0);
}

void ft_depiler(t_list *head)
{
	t_stack	*a;
	int		val;

	if (head->header != NULL && head != NULL)
	{
		a = head->header;
		val = a->value;
		head->header = a->suivant;
		free(a);
	}
	else
		ft_exit();
}

void ft_remplir(t_list *head, int val)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		ft_exit();
	if (head->header == NULL)
	{
		a->value = val;
		a->suivant = NULL;
		head->header = a;
	}
	else
	{
		a->value = val;
		a->suivant = head->header;
		head->header = a;
	}
}


int			is_digit(char *str)
{
	if (*(str + 1) != '\0' && (*str == '+' || *str == '-'))
		str++;
	while (*str)
	{
		if(*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int			check_duplicate(t_list *head, char *str)
{
	t_stack *a;

	if (head->header != NULL)
	{
		a = head->header;
		while (a != NULL)
		{
			if (a->value == atoi(str))
				return (1);
			a = a->suivant;
		}
	}
	return (0);
}

int			check_overflow(char *str)
{
	long long r;
	
	r = atoi(str);
	if (r > 2147483647 || r < -2147483648)
		return (1);
	return (0);
}

int	check_value(t_list *head, char *str)
{
	if (is_digit(str) || check_overflow(str) || check_duplicate(head, str))
		return (1);
	return (0);
}

void	swap(t_list *head)
{
	int		tmp;
	t_stack	*lsd;

	if (head->header != NULL && lsd->suivant != NULL)
	{
		lsd = head->header;
		tmp = lsd->value;
		lsd->value = lsd->suivant->value;
		lsd->suivant->value = tmp;
	}
}

void	push(t_list *dest, t_list *depart)
{
	t_stack *des;
	t_stack *dep;

	des = dest->header;
	dep = depart->header;
	if (dep != NULL)
	{
		ft_remplir(dest, dep->value);
		ft_depiler(depart);
	}
}

void rotate(t_list *tesla)
{
	t_stack *me;
	t_stack *new;
	int		tmp;

	me = tesla->header;
	if (me != NULL && me->suivant != NULL)
	{
		tmp = me->value;
		tesla->header = me->suivant;
		new = malloc(sizeof(t_stack));
		new->value = tmp;
		new->suivant = NULL;
		free(me);
		me = tesla->header;
		while (me->suivant != NULL)
			me = me->suivant;
		me->suivant = new;
	}
}

void	reverse_rotate(t_list *tesla)
{
	t_stack *me;
	t_stack *new;
	int		tmp;

	me = tesla->header;
	if (me != NULL && me->suivant != NULL)
	{
		while (me->suivant->suivant != NULL)
			me = me->suivant;
		if (me->suivant->suivant == NULL)
		{
			tmp = me->suivant->value;
			free(me->suivant);
			me->suivant = NULL;
			new = malloc(sizeof(t_stack));
			new->value = tmp;
			new->suivant = tesla->header;
			tesla->header = new;
		}
	}
}

void	ft_command(t_list *head_a, t_list *head_b, char *line)
{
	if (strcmp(line, "sa") == 0)
		swap(head_a);
	else if (strcmp(line, "sb") == 0)
		swap(head_b);
	else if (strcmp(line, "ss") == 0)
	{
		swap(head_a);
		swap(head_b);
	}
	else if (strcmp(line, "pa") == 0)
		push(head_a, head_b);
	else if (strcmp(line, "pb") == 0)
		push(head_b, head_a);
	else if (strcmp(line, "ra") == 0)
		rotate(head_a);
	else if (strcmp(line, "rb") == 0)
		rotate(head_b);
	else if (strcmp(line, "rr") == 0)
	{
		rotate(head_a);
		rotate(head_b);
	}
	else if (strcmp(line, "rra") == 0)
		reverse_rotate(head_a);
	else if (strcmp(line, "rrb") == 0)
		reverse_rotate(head_b);
	else if (strcmp(line, "rrr") == 0)
	{
		reverse_rotate(head_a);
		reverse_rotate(head_b);
	}
	else
		ft_exit();
}

void	ft_get(t_list *header_a, t_list *header_b)
{
	char *line;
	t_stack *a;

	while (get_next_line(0, &line))
	{
		if (strcmp(line, "") == 0)
			break ;
		ft_command(header_a, header_b, line);
		free(line);
	}
}

int main(int ac, char **av)
{
	t_list *header;
	t_list *header_b;
	t_stack *a;
	// t_stack *b;
	int i;

	//a = NULL;
	i = 1;
	if (ac > 1)
	{
		header = malloc(sizeof(t_list));
		header_b = malloc(sizeof(t_list));
		header->header = NULL;
		header_b->header = NULL;
		while (i < ac)
		{
			if (check_value(header, av[i]))
				ft_exit();
			else
				ft_remplir(header, atoi(av[i]));
			i++;
		}
		ft_get(header, header_b);
		a = header->header;
		//b = header_b->header;
		while (a != NULL)
		{
			printf("|a|%d\n",a->value);
			a = a->suivant;
		}
		// while (b != NULL)
		// {
		// 	printf("|b|%d\n",b->value);
		// 	b = b->suivant;
		// }
	}
	else
		ft_exit();
}