#include "prj.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void	ft_lstadd_first(t_stack **lst, int val)
{
	t_stack	*help;

	help = (t_stack *)malloc(sizeof(t_stack));
	if(help != NULL)
	{
		help->value = val;
		help->suivant = *lst;
		*lst = help;
	}
}

void	ft_lstdel_first(t_stack **lst)
{
	t_stack *tmp;

	if (*lst != NULL && lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->suivant;
		tmp->value = 0;
		tmp->suivant = NULL;
		free(tmp);
	}
}

void	add_last(t_stack **lst, int val)
{
	t_stack *new;
	t_stack *help;

	new = malloc(sizeof(t_stack));
	if (new != NULL)
	{
		new->suivant = NULL;
		new->value = val;
		if(*lst == NULL)
			*lst = new;
		else
		{
			help = *lst;
			while(help->suivant != NULL)
				help = help->suivant;
			help->suivant=new;
		}
	}
}

void		del_last(t_stack **p)
{
	t_stack *tmp;
	t_stack *help;

	if (p != NULL && *p != NULL)
	{
		if ((*p)->suivant == NULL)
		{
			free(*p);
		}
		tmp = *p;
		help = NULL;
		while (tmp->suivant != NULL)
		{
			help = tmp;
			tmp = tmp->suivant;
		}
		help->suivant = NULL;
		free(tmp);
	}
}

t_liste		*initialisation()
{
	t_stack	*p;
	t_liste *f;
	
	p = malloc(sizeof(t_stack));
	f = malloc(sizeof(t_liste));
	if (p == NULL || f == NULL)
		return (-1);
	p->value = 0;
	p->suivant = NULL;
	f->first = p;
	return (f);
}

t_stack		*ft_newstack(int ac, char **av)
{
	t_stack *p;
	p = NULL;
	while (ac > 1)
	{
		if (ft_checkvalue(p, av[ac - 1]))
			ft_lstadd_first(&p, atoi(av[ac - 1]));
		else
			ft_errorexit(&p);
		ac--;
	}
	return (p);
}

int			check_overflow(char *str)
{
	long long r;
	
	r = atoi(str);
	if (r > 2147483647 || r < -2147483648)
		return (0);
	return (1);
}

int			is_digit(char *str)
{
	if (*(str + 1) != '\0' && (*str == '+' || *str == '-'))
		str++;
	while (*str)
	{
		if(*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int			ft_checkvalue(t_stack *p, char *av)
{	
	if (is_digit(av) || check_overflow(av) /*|| check_duplicate(p, atoi(av))*/)
		return (0);
	return (1);
}

void		swap(t_stack **lst)
{
	int		tmp;

	if (lst != NULL && *lst != NULL)
	{
		tmp = (*lst)->value;
		(*lst)->value = (*lst)->suivant->value;
		(*lst)->suivant->value = tmp;
	}
}

void		command(t_stack **a, t_stack **b, char *line)
{
	if (strcmp(line, "sa") == 0)
		swap(&a);
	else if (strcmp(line, "sb") == 0)
		swap(&b);
	else if (strcmp(line, "ss") == 0)
		swap(&a);
	else if (strcmp(line, "pa") == 0)
		swap(&a);
	else if (strcmp(line, "pb") == 0)
		swap(&a);
	else if (strcmp(line, "ra") == 0)
		swap(&a);
	else if (strcmp(line, "rb") == 0)
		swap(&a);
	else if (strcmp(line, "rr") == 0)
		swap(&a);
	else if (strcmp(line, "rra") == 0)
		swap(&a);
	else if (strcmp(line, "rrb") == 0)
		swap(&a);
	else if (strcmp(line, "rrr") == 0)
		swap(&a);
}

void		parsing(t_stack **a, t_stack **b)
{
	char	*line;
	while (get_next_line(0, &line))
	{
		if (strcmp(line, "") == 0)
			break ;
		command(a, b, line);
		free(line);
	}
}

int			main(int ac, char **av)
{
    t_stack	*a;
	t_stack	*b;
	int i;

	a = NULL;
	b = NULL;
	i = 1;
    if (ac < 2)
    {
        printf("\n");
        return (-1);
    }
	else
	{
		a = ft_newstack(ac, av);
		parsing(&a, &b);
	}
	
    /*else
    {
        stack = (t_stack*)malloc(sizeof(t_stack));
        stack->a = (int *)malloc((ac - 1) * sizeof(int));
        stack->i = 0;
		stack->all = ac - 1;
        while (stack->i < ac - 1)
        {
            stack->a[stack->i] = atoi(av[stack->i + 1]);
            stack->i++;
        }
        stack->i = 0;
        while (stack->i < stack->all)
        {
            printf("|%d|\n",  stack->a[stack->i++]);
        }
        sa(stack);
        stack->i = 0;
        while (stack->i < stack->all)
        {
            printf("%d\n",  stack->a[stack->i++]);
        }
        // if (strcmp(av[1], "checker"))
        //     ft_checker(stack);
		// if (av[1] == "push_swap")
        //     ft_push_swap(ac, av);
    }
    return (0);*/
}
