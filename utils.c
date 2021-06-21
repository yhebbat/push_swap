#include "prj.h"

static void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		write(1, &c[i++], 1);
}

void	ft_exit(void)
{
	ft_putstr("Error\n");
	exit(0);
}

void	ft_compare1(t_list *head_a, t_list *head_b, char *line)
{
	if (!strcmp(line, "sa"))
		swap(head_a);
	else if (!strcmp(line, "sb"))
		swap(head_b);
	else if (!strcmp(line, "ss"))
	{
		swap(head_a);
		swap(head_b);
	}
	else
		ft_exit();
}

void	ft_compare2(t_list *head_a, t_list *head_b, char *line)
{
	if (!strcmp(line, "pa"))
		push(head_a, head_b);
	else if (!strcmp(line, "pb"))
		push(head_b, head_a);
	else
		ft_exit();
}

void	ft_compare3(t_list *head_a, t_list *head_b, char *line)
{
	if (!strcmp(line, "ra"))
		rotate(head_a);
	else if (!strcmp(line, "rb"))
		rotate(head_b);
	else if (!strcmp(line, "rr"))
	{
		rotate(head_a);
		rotate(head_b);
	}
	else if (!strcmp(line, "rra"))
		reverse_rotate(head_a);
	else if (!strcmp(line, "rrb"))
		reverse_rotate(head_b);
	else if (!strcmp(line, "rrr"))
	{
		reverse_rotate(head_a);
		reverse_rotate(head_b);
	}
	else
		ft_exit();
}

void	ft_command(t_list *head_a, t_list *head_b, char *line)
{
	if (line[0] == 's')
		ft_compare1(head_a, head_b, line);
	else if (line[0] == 'p')
		ft_compare2(head_a, head_b, line);
	else if (line[0] == 'r')
		ft_compare3(head_a, head_b, line);
	else
		ft_exit();
}

void	ft_get(t_list *header_a, t_list *header_b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (strcmp(line, "") == 0)
			break ;
		ft_command(header_a, header_b, line);
		free(line);
	}
	free(line);
}

void	ft_free(t_list *head)
{
	while (head->header != NULL)
	{
		ft_depiler(head);
	}
	free(head);
}