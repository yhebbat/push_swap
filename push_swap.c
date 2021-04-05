#include "prj.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
void		ft_checker(t_stack *k)
{
	k->i = 0;
	while (k->i < k->all)
	{
		//IMPORTANT
		if (k->a[k->i++] > k->a[k->i])
		{
			printf("KO\n");
			return ;
		}
	}
	printf("OK\n");
}

void    sa(t_stack *l)
{
    int tmp;

    tmp = 0;
    if (l->all > 2)
    {
        tmp = l->a[l->all - 1];
        l->a[l->all - 1] = l->a[l->all - 2];
        l->a[l->all - 2] = tmp; 
    }
}*/

void	ft_lstadd_first(t_stack **lst, int val)
{
	t_stack	*help;

	help = (t_stack *)malloc(sizeof(t_stack));
	if(help != NULL)
	{
		help->value = val;
		help->preced = *lst;
		*lst = help;
	}
}

// void	ft_lstdel_first(t_stack **lst)
// {
// 	t_stack tmp;
// 	if (*lst && lst)
// 	{
		
// 	}
// }

t_stack		*ft_newstack(int ac, char **av)
{
	t_stack	*p;
	
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

int			ft_checkvalue(int ac, char **av)
{
	int		i;
	
	i = 1;
	while (i < (ac - 1))
	{
		if (!isdigit((int)av[i]))
			return (0);
		i++;
	}
	return (1);
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
		// if (ft_checkvalues(ac, **av))
		// {
		// }
		// else
		// 	printf("Error\n");
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