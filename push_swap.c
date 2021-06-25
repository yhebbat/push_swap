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

// void	to_divise(int *t, int number, int max)
// {
// 	int step;

// 	step = max / number;
// }

// void	move_to_b(t_data *m, int delim)
// {
// 	int step;
// 	int	i;

// 	m->pos = 0;
// 	i = 0;
// 	if (delim == 4)
// 		step = m->a_size / 5;
// 	else
// 		step = m->a_size / 11;
// 	while (i <= delim)
// 	{
// 		if (i == delim)
// 		{
// 			move_b(m, m->dup[i * step + 1], m->dup[m->dup_size - 1]);
// 			break;
// 		}
// 		if (i == 0)
// 		{
// 			move_b(m, m->dup[0], m->dup[step * (i + 1)]);
// 			i++;
// 			continue;
// 		}
// 		move_b(m, m->dup[i * step + 1], m->dup[step * (i + 1)]);
// 		i++;
// 	}
// }

void	move_to_b(t_list *head_a, t_list *head_b, int min, int max)
{
	
}

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
	move_to_b(head_a, head_b, t[0], t[step]);
	move_to_b(head_a, head_b, t[step + 1], t[2 * step]);
	move_to_b(head_a, head_b, t[(2 * step) + 1], t[3 * step]);
	move_to_b(head_a, head_b, t[3 * step + 1], t[max]);
}

void	sort_more_than_five_numbers(t_list *head_a, t_list *head_b, int size_a)
{
	int *t;
	// t_stack *a;
	// t_stack *b;
	
	t = malloc(sizeof(int) * size_a);
	ft_sorted(size_a, head_a, t);
	// a = head_a->header;
	// b = head_b->header;
	if (size_a <= 100)
		divise5(t, head_a, head_b);
	// to_divise(t, 5, i);
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
	sort_more_than_five_numbers(head_a, head_b, i);
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
	else if (ac <= 101)
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
				ft_remplir(header, atoi(av[i - 1]));
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
