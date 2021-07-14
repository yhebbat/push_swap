#include "prj.h"


void	ft_sortt(t_list *head)
{
	t_stack *a;

	a = head->header;
	if (a->value > a->suivant->value)
	{
		swap(head);
		printf("sa\n");
	}
}

int	ft_check(t_list *head)
{
	t_stack	*to_check;

	to_check = head->header;
	while (to_check->suivant != NULL)
	{
		if (to_check->value > to_check->suivant->value)
			return (1);
		to_check = to_check->suivant;
	}
	return (0);
}

void	ft_helperthree(t_list *head, t_stack *a)
{
	if (a->value < a->suivant->suivant->value)
	{
		swap(head);
		printf("sa\n");
	}
	else
	{
		rotate(head);
		printf("ra\n");
	}
}

void	ft_helpertthree(t_list *head, t_stack *a)
{
	if (a->value < a->suivant->suivant->value)
	{
		swap(head);
		rotate(head);
		printf("sa\nra\n");
	}
	else
	{
		reverse_rotate(head);
		printf("rra\n");
	}
}

void	ft_sorttt(t_list *head)
{
	t_stack *a;
	
	a = head->header;
	if (a->value > a->suivant->value && a->suivant->value < a->suivant->suivant->value)
		ft_helperthree(head, a);
	else if (a->value > a->suivant->value && a->suivant->value > a->suivant->suivant->value)
	{
		swap(head);
		reverse_rotate(head);
		printf("sa\nrra\n");
	}
	else if (a->value < a->suivant->value && a->suivant->value > a->suivant->suivant->value)
		ft_helpertthree(head, a);
}

int		find_min(t_list *head)
{
	t_stack *a;
	int tmp;
	int i;

	i = 0;
	a = head->header;
	tmp = a->value;
	while (a->suivant != NULL)
	{
		if (tmp > a->suivant->value)
			tmp = a->suivant->value;
		a = a->suivant;
	}
	a = head->header;
	while (a->suivant != NULL)
	{
		if (a->value == tmp)
			break;
		i++;
		a = a->suivant;
	}
	return (i);
}

void	ft_sortttt(t_list *head, t_list *head_b)
{
	int i;

	i = find_min(head);
	if (i == 1)
	{
		swap(head);
		printf("sa\n");
	}
	else if (i == 2)
	{
		reverse_rotate(head);
		printf("rra\n");
		reverse_rotate(head);
		printf("rra\n");
	}
	else if (i == 3)
	{
		reverse_rotate(head);
		printf("rra\n");
	}
	push(head_b, head);
	printf("pb\n");
	ft_sorttt(head);
	push(head, head_b);
	printf("pa\n");
}

void	helperfive(t_list *head, int i)
{
	if (i == 1)
	{
		swap(head);
		printf("sa\n");
	}
	else if (i == 2)
	{
		rotate(head);
		printf("ra\n");
		swap(head);
		printf("sa\n");
	}
	else if (i == 3)
	{
		reverse_rotate(head);
		printf("rra\n");
		reverse_rotate(head);
		printf("rra\n");
	}
	else if (i == 4)
	{
		reverse_rotate(head);
		printf("rra\n");
	}
}
void	ft_sort5(t_list *head, t_list *head_b)
{
	int i;

	i = find_min(head);
	helperfive(head, i);
	push(head_b, head);
	printf("pb\n");
	ft_sortttt(head, head_b);
	push(head, head_b);
	printf("pa\n");
}

void	fromlinkedlist_to_table(t_stack *a, int *t, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		t[i] = a->value;
		a = a->suivant;
		i++;
	}
}

void	ft_sorted(int max, t_list *head, int *t)
{
	int i;
	int k;
	int tmp;
	t_stack *a;

	i = 0;
	a = head->header;
	fromlinkedlist_to_table(a,t,max);
	while (i < max)
	{
		k = 0;
		while (k < max - i - 1)
		{
			if (t[k] > t[k + 1])
			{
				tmp = t[k];
				t[k] = t[k + 1];
				t[k + 1] = tmp;
			}
			k++;
		}
		i++;
	}
}
/*
int		find_the_first_num(t_list *head_a, int min, int max)
{
	t_stack *a_top;
	t_stack *a_bot;
	int i;
	int k;

	i = 0;
	k = 0;
	a_top = head_a->header;
	a_bot = head_a->footer;
	while (a_top != NULL)
	{
		i++;
		if (a_top->value >= min && a_top->value <= max)
			break;
		a_top = a_top->suivant;
	}
	while (a_bot != NULL)
	{
		k++;
		if (a_bot->value >= min && a_bot->value <= max)
			break;
		a_bot = a_bot->preced;
	}
	if (k < i)
		return (1);
	else
		return (0);
}
*/
void		size(t_list *head_a, t_list *head_b, int *t)
{
	t_stack *a;
	t_stack *b;

	a = head_a->header;
	b = head_b->header;
	t[MINA] = a->index;
	t[MAXA] = a->index;
	t[LENA] = 0;
	t[LENB] = 0;
	while (a)
	{
		if (a->index < t[MINA])
			t[MINA] = a->index;
		else if (a->index > t[MAXA])
			t[MAXA] = a->index;
		t[LENA]++;
		a = a->suivant;
	}
	while (b)
	{
		t[LENB]++;
		b = b->suivant;
	}
}

void	min_instructions(int *t, int nb)
{
	t[UPA] = t[FROMUPA];
	t[UPB] = t[FROMUPB];
	t[NBA] = t[NBRINSA];
	t[NBB] = nb;
	t[NBAB] = t[NBRINSAB];
}

void	number_of_instructions(int *t, int v, int nb)
{
	if (t[NBRINSA] > (t[LENA] / 2))
	{
		t[FROMUPA] = 0;
		t[NBRINSA] = t[LENA] - t[NBRINSA];
	}
	if (nb > (t[LENB] / 2))
	{	
		t[FROMUPB] = 0;
		nb = t[LENB] - nb;
	}
	t[NBRINSA] += v;
	if (t[FROMUPB] == t[FROMUPA])
	{
	 	if(t[NBRINSA] > nb)
	 		t[NBRINSAB] = t[NBRINSA];
	 	else
	 		t[NBRINSAB] = nb;
	 }
	else
		t[NBRINSAB] = t[NBRINSA] + nb;
	if (t[NBAB] > t[NBRINSAB])
		min_instructions(t, nb);
}

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


void	from_upa(int *t, t_list *head_a, t_list *head_b)
{
	while (t[NBA] > 0)
	{
		rotate(head_a);
		printf("ra\n");
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{	
		reverse_rotate(head_b);
		printf("rrb\n");
		t[NBB]--;
	}
	push(head_a, head_b);
	printf("pa\n");
}

void	from_upb(int *t, t_list *head_a, t_list *head_b)
{
	while (t[NBA] > 0)
	{
		reverse_rotate(head_a);
		printf("rra\n");
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{
		rotate(head_b);
		printf("rb\n");
		t[NBB]--;
	}
	push(head_a, head_b);
	printf("pa\n");
}

void	from_upab(int *t, t_list *head_a, t_list *head_b)
{
	while (t[NBA] > 0 && t[NBB] > 0)
	{
		rotate(head_a);
		rotate(head_b);
		printf("rr\n");
		t[NBA]--;
		t[NBB]--;
	}
	while (t[NBA] > 0)
	{
		rotate(head_a);
		printf("ra\n");
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{
		rotate(head_b);
		printf("rb\n");	
		t[NBB]--;
	}
	push(head_a, head_b);
	printf("pa\n");
}

void	from_downab(int *t, t_list *head_a, t_list *head_b)
{
	while (t[NBA] > 0 && t[NBB] > 0)
	{
		reverse_rotate(head_a);
		reverse_rotate(head_b);
		printf("rrr\n");
		t[NBA]--;
		t[NBB]--;
	}
	while (t[NBA] > 0)
	{
		reverse_rotate(head_a);
		printf("rra\n");
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{
		reverse_rotate(head_b);
		printf("rrb\n");
		t[NBB]--;
	}
	push(head_a, head_b);
	printf("pa\n");
}

void	actions(int *t, t_list *head_a, t_list *head_b)
{
	if (t[UPA] == 1 && t[UPB] == 0)
		from_upa(t, head_a, head_b);
	else if (t[UPB] == 1 && t[UPA] == 0)
		from_upb(t, head_a, head_b);
	else if (t[UPA] == 1 && t[UPB] == 1)
		from_upab(t, head_a, head_b);
	else if (t[UPA] == 0 && t[UPB] == 0)
		from_downab(t, head_a, head_b);
}

void	initialiser(int *t)
{
	t[NBRINSA] = 0;
	t[NBRINSB] = 0;
	t[NBRINSAB] = 0;
	t[LENA] = 0;
	t[LENB] = 0;
	t[NBA] = 0;
	t[NBB] = 0;
	t[NBAB] = maxim;
	t[FROMUPA] = 1;
	t[FROMUPB] = 1;
	t[UPA] = 0;
	t[UPB] = 0;
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

void	push_to_b(t_list *head_a, t_list *head_b)
{
	t_stack *a;
	int k = 0;

	while (ft_checker(head_a) != 1)
	{
		a = head_a->header;
		if (a->index < k + 12 && a->index >= k)
		{
			k = a->index;
			rotate(head_a);
			printf("ra\n");
		}
		else
		{
			push(head_b, head_a);	
			printf("pb\n");
		}
	}
}

void	ft_rotate_a(t_list *head, int i, int fromdown)
{
	if (fromdown == 1)
	{
		while (i > 0)
		{
			reverse_rotate(head);
			printf("rra\n");
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			rotate(head);
			printf("ra\n");
			i--;
		}
	}
}

void	last_actions(t_list *head, int size_a)
{
	t_stack *a;
	int		i;
	int		fromdown;

	a = head->header;
	fromdown = 0;
	i = 0;
	while (a->index > 0)
	{
		i++;
		a = a->suivant;
	}
	if (i > (size_a / 2))
	{
		fromdown = 1;
		i = size_a - i;
	}
	ft_rotate_a(head, i, fromdown);
}

void	index_more_than_five_numbers(t_list *head_a, t_list *head_b, int size_a)
{
	int *t;
	int k;
	t_stack *a;
	
	t = malloc(sizeof(int) * size_a);
	ft_sorted(size_a, head_a, t);
	k = 0;
	while (k < size_a)
	{
		a = head_a->header;
		while (a != NULL)
		{
			if (t[k] == a->value)
			{
				a->index = k;
				break ;
			}
			a = a->suivant;
		}
		k++;
	}
	push_to_b(head_a, head_b);
	push_to_a(head_a, head_b);
	free(t);
}

int		ft_lena(t_list *head_a)
{
	t_stack *a;
	int		i = 1;

	a = head_a->header;
	while (a->suivant != NULL)
	{
		i++;
		a = a->suivant;
	}
	return (i);
}

void	ft_sort(t_list *head_a, t_list *head_b)
{
	int i;

	i = ft_lena(head_a);
	index_more_than_five_numbers(head_a, head_b, i);
	if (ft_check(head_a))
		last_actions(head_a, i);
}

void	ft_pushswap(t_list *head, t_list *head_b, int ac)
{
	if (ac == 3)
		ft_sortt(head);
	else if (ac == 4)
		ft_sorttt(head);
	else if (ac == 5)
		ft_sortttt(head, head_b);
	else if (ac == 6)
		ft_sort5(head, head_b);
	else
		ft_sort(head, head_b);
}

void	fill_a(t_list *header, int ac, char **av)
{
	int i;

	i = ac;
	while (i - 1 > 0)
	{
		if (check_value(header, av[i - 1]))
			ft_exit();
		else
			ft_remplir(header, atoi(av[i - 1]), -1, 0);
		i--;
	}
}

int main(int ac, char **av)
{
	t_list *header;
	t_list *header_b;
	int		i;

	i = ac;
	if (i > 1)
	{
		header = malloc(sizeof(t_list));
		header_b = malloc(sizeof(t_list));
		header->header = NULL;
		header_b->header = NULL;
		fill_a(header, ac, av);
		if (ft_check(header))
			ft_pushswap(header, header_b, ac);
		ft_free(header);
		ft_free(header_b);
		exit(0);
	}
	else
		ft_exit();
}
