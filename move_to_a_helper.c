/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <yhebbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:03:38 by yhebbat           #+#    #+#             */
/*   Updated: 2021/07/16 17:10:19 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prj.h"

void	fromlinkedlist_to_table(t_stack *a, int *t, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		t[i] = a->value;
		a = a->suivant;
		i++;
	}
}

void	size(t_list *head_a, t_list *head_b, int *t)
{
	t_stack	*a;
	t_stack	*b;

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
