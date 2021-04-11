#include "prj.h"

void	swap(t_list *head)
{
	int		tmp;
	t_stack	*lsd;
    if (head->header != NULL)
		lsd = head->header;

	if (lsd->suivant != NULL)
	{
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