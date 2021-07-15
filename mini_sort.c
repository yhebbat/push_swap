#include "prj.h"

void	ft_sortt(t_list *head)
{
	t_stack *a;

	a = head->header;
	if (a->value > a->suivant->value)
	{
		swap(head);
		ft_putstr("sa\n");
	}
}

void	ft_sorttt(t_list *head)
{
	t_stack *a;
	
	a = head->header;
	if (a->value > a->suivant->value && 
			a->suivant->value < a->suivant->suivant->value)
		ft_helperthree(head, a);
	else if (a->value > a->suivant->value &&
			a->suivant->value > a->suivant->suivant->value)
	{
		swap(head);
		reverse_rotate(head);
		ft_putstr("sa\nrra\n");
	}
	else if (a->value < a->suivant->value &&
			a->suivant->value > a->suivant->suivant->value)
		ft_helpertthree(head, a);
}

void	ft_sortttt(t_list *head, t_list *head_b)
{
	int i;

	i = find_min(head);
	if (i == 1)
	{
		swap(head);
		ft_putstr("sa\n");
	}
	else if (i == 2)
	{
		reverse_rotate(head);
		ft_putstr("rra\n");
		reverse_rotate(head);
		ft_putstr("rra\n");
	}
	else if (i == 3)
	{
		reverse_rotate(head);
		ft_putstr("rra\n");
	}
	push(head_b, head);
	ft_putstr("pb\n");
	ft_sorttt(head);
	push(head, head_b);
	ft_putstr("pa\n");
}

void	ft_sort5(t_list *head, t_list *head_b)
{
	int i;

	i = find_min(head);
	helperfive(head, i);
	push(head_b, head);
	ft_putstr("pb\n");
	ft_sortttt(head, head_b);
	push(head, head_b);
	ft_putstr("pa\n");
}