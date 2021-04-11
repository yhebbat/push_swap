#include "prj.h"


void		ft_exit()
{
	printf("Error\n");
	exit(0);
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
		//i = ac - 1;
		header = malloc(sizeof(t_list));
		header_b = malloc(sizeof(t_list));
		header->header = NULL;
		header_b->header = NULL;
		while (ac - 1 > 0)
		{
			if (check_value(header, av[ac - 1]))
				ft_exit();
			else
				ft_remplir(header, atoi(av[ac - 1]));
			ac--;
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