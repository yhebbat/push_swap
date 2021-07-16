/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <yhebbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:01:00 by yhebbat           #+#    #+#             */
/*   Updated: 2021/07/16 17:17:30 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prj.h"

void	ft_sorted(int max, t_list *head, int *t)
{
	int		i;
	int		k;
	int		tmp;
	t_stack	*a;

	i = 0;
	a = head->header;
	fromlinkedlist_to_table(a, t, max);
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

void	index_numbers(t_list *head_a, t_list *head_b, int size_a)
{
	int		*t;
	int		k;
	t_stack	*a;

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
