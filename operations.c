#include "prj.h"

void	swap(t_list *head)
{
	int		tmp;
	int		tmp_ind;
	int		tmp_boo;
	t_stack	*lsd;

	lsd = NULL;
    if (head->header != NULL)
		lsd = head->header;

	if (lsd->suivant != NULL)
	{
		tmp = lsd->value;
		tmp_ind = lsd->index;
		tmp_boo = lsd->bool;
		lsd->value = lsd->suivant->value;
		lsd->index = lsd->suivant->index;
		lsd->bool = lsd->suivant->bool;
		lsd->suivant->value = tmp;
		lsd->suivant->index = tmp_ind;
		lsd->suivant->index = tmp_boo;
	}
}

void	push(t_list *dest, t_list *depart)
{
	t_stack *dep;

	dep = depart->header;
	if (dep != NULL)
	{
		ft_remplir(dest, dep->value, dep->index, dep->bool);
		ft_depiler(depart);
	}
}

int	ft_checker(t_list *head)
{
	t_stack	*to_check;

	to_check = head->header;
	while (to_check->suivant != NULL)
	{
		if (to_check->value > to_check->suivant->value)
			return(0);
		to_check = to_check->suivant;
	}
	return (1);
}

void rotate(t_list *tesla)
{
	t_stack	*me;
	t_stack	*new;

	me = tesla->footer;
	new = tesla->header;
	if (new != NULL && new->suivant != NULL)
	{
		new->preced = tesla->footer;
		me->suivant = new;
		tesla->header = new->suivant;
		tesla->header->preced = NULL;
		tesla->footer = new;
		tesla->footer->suivant = NULL;
	}
}

void	reverse_rotate(t_list *tesla)
{
	t_stack	*me;
	t_stack	*new;

	me = tesla->footer;
	new = tesla->header;
	if (me != NULL && me->preced != NULL)
	{
		me->suivant = tesla->header;
		new->preced = me;
		tesla->footer = me->preced;
		tesla->footer->suivant = NULL;
		tesla->header = me;
		tesla->header->preced = NULL;
	}
}
