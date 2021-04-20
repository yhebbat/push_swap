#include "prj.h"

void	ft_sortt(t_list *head)
{
	t_stack *a;

	a = head->header;
	if (a->value > a->suivant->value)
	{
		printf("sa\n");
	}
}

void	ft_sorttt(t_list *head)
{
	t_stack *a;
	
	a = head->header;
	if (a->value > a->suivant->value && a->suivant->value < a->suivant->suivant->value)
	{
		if (a->value < a->suivant->suivant->value)
			printf("sa\n");
		else
			printf("ra\n");
	}
	if (a->value > a->suivant->value && a->suivant->value > a->suivant->suivant->value)
		printf("sa\nrra\n");
	if (a->value < a->suivant->value && a->suivant->value > a->suivant->suivant->value)
	{
		if (a->value < a->suivant->suivant->value)
			printf("sa\nra\n");
		else
			printf("rra\n");
	}
}

void	ft_sortttt(t_list *head, t_list *head_b)
{
	t_stack *a;
	t_stack *b;
	int		i;
	int		tmp;

	i = 0;
	a = head->header;
	b = head_b->header;
	push(head_b, head);
	printf("pb\n");
	ft_sorttt(head);
	printf("pa\n");
	push(head_b, head);
	tmp = a->value;
	//if (a->value < a->suivant->value && a->value > a->suivant->suivant->value)
	//	printf("sa\n")
	while (a->suivant != NULL)
	{
		if (tmp >= a->value)
			i++;
		else
			break ;
		a = a->suivant;
	}
	
	
}

void	ft_pushswap(t_list *head, t_list *head_b, int ac)
{
	if (ac == 3)
		ft_sortt(head);
	if (ac == 4)
		ft_sorttt(head);
	if (ac == 5)
		ft_sortttt(head, head_b);
	/*if (ac > 2)
	{
		if (ac == 3)
		{
			if ()
		}
	}*/

}

int main(int ac, char **av)
{
	t_list *header;
	t_list *header_b;
	t_stack *a;

	if (ac > 1)
	{
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
        printf("|a|\n");
		while (a != NULL)
		{
			printf("%d\n",a->value);
			a = a->suivant;
		}
		//ft_checker(header);
		ft_pushswap(header, header_b, ac);
		ft_free(header);
		ft_free(header_b);
		exit(0);
	}
	else
		ft_exit();
}