#include "prj.h"

void	swap(t_list *head)
{
	int		tmp;
	t_stack	*lsd;

	lsd = NULL;
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
	//t_stack *des;
	t_stack *dep;

	//des = dest->header;
	dep = depart->header;
	if (dep != NULL)
	{
		ft_remplir(dest, dep->value);
		ft_depiler(depart);
	}
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
