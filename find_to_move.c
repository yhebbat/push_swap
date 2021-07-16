#include "prj.h"

void	ft_min(int *t, t_stack *a)
{
	t[FROMUPA] = 1;
	while (a->index != t[MINA])
	{
		t[NBRINSA]++;
		a = a->suivant;
	}
}

void	ft_max(int *t, t_stack *a, int *v)
{
	t[FROMUPA] = 1;
	while (a->index != t[MAXA])
	{
		t[NBRINSA]++;
		a = a->suivant;
	}
	if (t[NBRINSA] > (t[LENA] / 2))
		*v = -1;
	else
		*v = 1;
}

void	ft_mid(int *t, t_stack *a, t_stack *b)
{
	t[NBRINSA] = 1;
	t[FROMUPA] = 1;
	while (a->suivant && !(b->index < a->suivant->index && b->index > a->index))
	{
		t[NBRINSA]++;
		a = a->suivant;
	}
	if (a->suivant == NULL)
	{
		t[NBRINSA] = 0;
	}
}

void	find_element(int *t, t_list *head_a, t_stack *b)
{
	int		v;
	int		nb;
	t_stack *a;

	nb = 0;
	while (b)
	{
		a = head_a->header;
		t[FROMUPB] = 1;
		v = 0;
		t[NBRINSA] = 0;
		if (b->index < t[MINA])
			ft_min(t, a);
		else if(b->index > t[MAXA])
			ft_max(t,a,&v);
		else
			ft_mid(t, a, b);
		number_of_instructions(t, v, nb);
		b = b->suivant;
		nb++;
	}
}

void	push_to_a(t_list *head_a, t_list *head_b)
{
	t_stack	*b;
	int		t[14];

	while (head_b->header != NULL)
	{
		b = head_b->header;
		initialiser(t);
		size(head_a, head_b, t);
		find_element(t, head_a, b);
		actions(t, head_a, head_b);
	}
}