#include "prj.h"

void ft_depiler(t_list *head)
{
	t_stack	*to_delete;
	t_stack *a;

	if (head != NULL && head->header != NULL)
	{
		to_delete = head->header;
		if (!to_delete->suivant)
		{
			free(to_delete);
			head->header = NULL;
			to_delete = NULL;
		}
		else
		{
			a = to_delete->suivant;
			head->header = a;
			a->preced = NULL;
			free(to_delete);
			to_delete = NULL;
		}
	}
}


void ft_remplir(t_list *head, int val, int index)
{
	t_stack	*a;
	t_stack *to_add;

	to_add = malloc(sizeof(t_stack));
	if (!to_add)
		ft_exit();
	if (head->header == NULL)
	{
		to_add->index = index;
		to_add->value = val;
		to_add->suivant = NULL;
		to_add->preced = NULL;
		head->footer = to_add;
		head->header = to_add;
	}
	else
	{
		a = head->header;
		to_add->index = index;
		to_add->value = val;
		to_add->suivant = a;
		to_add->preced = NULL;
		a->preced = to_add;
		head->header = to_add;
	}
}
