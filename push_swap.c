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

void	ft_sorttt(t_list *head)
{
	t_stack *a;
	
	a = head->header;
	if (a->value > a->suivant->value && a->suivant->value < a->suivant->suivant->value)
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
	else if (a->value > a->suivant->value && a->suivant->value > a->suivant->suivant->value)
	{
		swap(head);
		reverse_rotate(head);
		printf("sa\nrra\n");
	}
	else if (a->value < a->suivant->value && a->suivant->value > a->suivant->suivant->value)
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
}

void	ft_sortttt(t_list *head, t_list *head_b)
{
	t_stack *a;
	t_stack *b;
	int tmp;
	int i;
	int k;

	i = 0;
	k = 0;
	a = head->header;
	b = head_b->header;
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
	//printf("--%d\n", i);
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

void	ft_sort5(t_list *head, t_list *head_b)
{
	t_stack *a;
	t_stack *b;
	int tmp;
	int i;

	i = 0;
	a = head->header;
	b = head_b->header;
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
	if (i == 1)
	{
		swap(head);
		printf("sa\n");
	}
	else if (i == 2)
	{
		reverse_rotate(head);
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
	push(head_b, head);
	printf("pb\n");
	ft_sortttt(head, head_b);
	push(head, head_b);
	printf("pa\n");
}

void	ft_sorted(int max, t_list *head, int *t)
{
	int i;
	int k;
	int tmp;
	t_stack *a;

	i = 0;
	a = head->header;
	
	while (i < max)
	{
		t[i] = a->value;
		a = a->suivant;
		i++;
	}
	i = 0;
	while ( i < max)
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

	// k = 0;
	// while(k < max)
	// 	printf("%d\n", t[k++]);	
}

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

// void	move_to_b(t_list *head_a, t_list *head_b, int min, int max)
// {
// 	int first;
// 	t_stack *up;
// 	t_stack *down;

// 	down = head_a->footer;
// 	up = head_a->header;
// 	first = find_the_first_num(head_a, min, max);
// 	// printf("%d\n", first);
// 	if (first == 1)
// 	{
// 		while (down != NULL/*down->value < min || down->value > max*/)
// 		{
// 			if (down->value < min || down->value > max)
// 			{
// 				reverse_rotate(head_a);
// 				printf("rra\n");
// 			}
// 			else if (down->value >= min && down->value <= max)
// 			{
// 				reverse_rotate(head_a);
// 				push(head_b, head_a);
// 				printf("rra\npb\n");
// 				break ;
// 			}
// 			down = down->preced;
// 		}
// 	}
// 	if (first == 0)
// 	{
// 		while (up != NULL)
// 		{
// 			if (up->value < min || up->value > max)
// 			{
// 				rotate(head_a);
// 				printf("ra\n");
// 			}
// 			else if (up->value >= min && up->value <= max)
// 			{
// 				push(head_b, head_a);
// 				printf("pb\n");
// 				break ;
// 			}
// 			up = up->suivant;
// 		}
// 	}
// }
/*
void	divise5(int *t, t_list *head_a, t_list *head_b)
{
	t_stack *a;
	t_stack *b;
	int		max;
	int		step;
	int		i;

	i = 0;
	max = 0;
	a = head_a->header;
	b = head_b->header;
	while (t[max])
		max++;
	step = max / 5;
	while (i <= step)
	{
		move_to_b(head_a, head_b, t[0], t[step]);
		a = head_a->header;
		b = head_b->header;
		printf("....\n");
		i++;
	}
	// move_to_b(head_a, head_b, t[step + 1], t[2 * step]);
	// move_to_b(head_a, head_b, t[(2 * step) + 1], t[3 * step]);
	// move_to_b(head_a, head_b, t[3 * step + 1], t[max]);
}*/

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
		if (a->index > t[MAXA])
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

void	best_pos_a(int *t, t_stack *a, t_stack *b)
{
	while (a)
	{
		if (t[MINA] > b->index)
		{
			while (a->index != t[MINA])
			{
				t[FROMUPA] = 1;
				t[NBRINSA]++;
				a = a->suivant;
			}
			break ;
		}
		if (t[MAXA] < b->index)
		{
			while (a->index != t[MAXA])
			{
				// printf("test\n");
				t[FROMUPA] = 1;
				t[NBRINSA]++;
				a = a->suivant;
			}
			break ;
		}
		if (b->index > t[MINA] && b->index < t[MAXA])
		{
			if (a->preced == NULL)
			{
				t[FROMUPA] = 1;
				a = a->suivant;
				t[NBRINSA]++;
			}
			while (!(b->index < a->index && b->index > a->preced->index))
			{
				t[FROMUPA] = 1;
				t[NBRINSA]++;
				a = a->suivant;
			}
			break ;
		}
	}
}

void	number_of_instructions(int *t)
{
	if (t[NBRINSA] > (t[LENA] / 2))
	{
		t[FROMUPA] = 0;
		t[NBRINSA] = t[LENA] - t[NBRINSA];
	}
	if (t[NBRINSB] > (t[LENB] / 2))
	{	
		t[FROMUPB] = 0;
		t[NBRINSB] = t[LENB] - t[NBRINSB];
	}
	t[NBRINSAB] = t[NBRINSA] + t[NBRINSB];
	if (t[NBAB] > t[NBRINSAB])
	{
		t[UPA] = t[FROMUPA];
		t[UPB] = t[FROMUPB];
		t[NBA] = t[NBRINSA];
		t[NBB] = t[NBRINSB];
		t[NBAB] = t[NBRINSAB];
	}
}

void	from_upa(int *t, t_list *head_a, t_list *head_b)
{
	while (t[NBA] != 0)
	{
		rotate(head_a);
		printf("ra\n");
		t[NBA]--;
	}
	while (t[NBB] != 0)
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
	while (t[NBA] != 0)
	{
		reverse_rotate(head_a);
		printf("rra\n");
		t[NBA]--;
	}
	while (t[NBB] != 0)
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
	while (t[NBA] != 0 && t[NBB] != 0)
	{
		rotate(head_a);
		rotate(head_b);
		printf("rr\n");
		t[NBA]--;
		t[NBB]--;
	}
	while (t[NBA] != 0)
	{
		rotate(head_a);
		printf("ra\n");
		t[NBA]--;
	}
	while (t[NBB] != 0)
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
	while (t[NBA] != 0 && t[NBB] != 0)
	{
		reverse_rotate(head_a);
		reverse_rotate(head_b);
		printf("rrr\n");
		t[NBA]--;
		t[NBB]--;
	}
	while (t[NBA] != 0)
	{
		reverse_rotate(head_a);
		printf("rra\n");
		t[NBA]--;
	}
	while (t[NBB] != 0)
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
	//printf("a-%d \t b-%d\n",t[UPA],t[UPB]);
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
	t[MINA] = maxim;
	t[MAXA] = maxim;
	t[NBRINSA] = 0;
	t[NBRINSB] = 0;
	t[NBRINSAB] = 0;
	t[LENA] = maxim;
	t[LENB] = maxim;
	t[NBA] = maxim;
	t[NBB] = maxim;
	t[NBAB] = maxim;
	t[FROMUPA] = 1;
	t[FROMUPB] = 1;
	t[UPA] = maxim;
	t[UPB] = maxim;
}

void	push_to_a(t_list *head_a, t_list *head_b)
{
	t_stack	*a;
	t_stack	*b;
	int		t[14];

	//t = malloc(14 * sizeof(int));
	while (head_b->header != NULL)
	{
		b = head_b->header;
		a = head_a->header;
		initialiser(t);
		while (b)
		{
			size(head_a,head_b, t);
			a = head_a->header;
			best_pos_a(t, a, b);
			number_of_instructions(t);
			t[FROMUPB] = 1;
			t[NBRINSB]++;
			b = b->suivant;
		}
		// printf("FROMUPB-%d \t FROMUPA-%d\t NBRINSA-%d\t NBRINSB-%d\t NBRINSAB-%d\n",t[FROMUPB],t[FROMUPA],t[NBRINSA],t[NBRINSB],t[NBRINSB]);
		// printf("UPB-%d \t UPA-%d\t NBA-%d\t NBB-%d\t NBAB-%d\n",t[UPB],t[UPA],t[NBA],t[NBB],t[NBAB]);
		// b = head_b->header;
		// a = head_a->header;
		// while (a)
		// {
		// 	printf("|a|--%d\n",a->index);
		// 	a = a->suivant;
		// }
		// while (b)
		// {
		// 	printf("|b|--%d\n",b->index);
		// 	b = b->suivant;
		// }
		// b = head_b->header;
		actions(t, head_a, head_b);
		a = head_a->header;
		printf("%d\n", a->index);
	}
	//free(t);
}

void	push_to_b(t_list *head_a, t_list *head_b)
{
	t_stack *a;
	t_stack *b;
	int k = 0;

	while (ft_checker(head_a) != 1)
	{
		a = head_a->header;
		b = head_b->header;
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
		//a = a->suivant;
	}
	// a = head_a->header;
	// b = head_b->header;
	// while (b)
	// {
	// 	printf("|b| ----- %d:\tindex %d\n", b->value, b->index);
	// 	b = b->suivant;
	// }
	//printf("%d\n\n new header %d\t%d\n",k , b->value, b->index);
	/*while (!a && a->index != k)
	{
		
	}*/
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
	// a = head_a->header;
	// while (a != NULL)
	// {
	// 	printf("%d :::\t", a->value);
	// 	printf("%d\n", a->index);
	// 	a = a->suivant;
	// }
	free(t);
}

void	ft_sort(t_list *head_a, t_list *head_b)
{
	t_stack *a;
	t_stack *b;
	int		i = 1;

	a = head_a->header;
	b = head_b->header;
	while (a->suivant != NULL)
	{
		i++;
		a = a->suivant;
	}
	index_more_than_five_numbers(head_a, head_b, i);
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

int main(int ac, char **av)
{
	t_list *header;
	t_list *header_b;
	t_stack *a;
	t_stack *b;
	int		i;

	i = ac;
	if (i > 1)
	{
		header = malloc(sizeof(t_list));
		header_b = malloc(sizeof(t_list));
		header->header = NULL;
		header_b->header = NULL;
		while (i - 1 > 0)
		{
			if (check_value(header, av[i - 1]))
				ft_exit();
			else
				ft_remplir(header, atoi(av[i - 1]), -1, 0);
			i--;
		}
		// ft_get(header, header_b);
		if (ft_check(header))
			ft_pushswap(header, header_b, ac);
		// a = header->header;
		// while (a != NULL)
		// {
		// 	printf("%d\n",a->value);
		// 	a = a->suivant;
		// }
		ft_free(header);
		ft_free(header_b);
		exit(0);
	}
	else
		ft_exit();
}
