#include "prj.h"

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
