/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_moves_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <yhebbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:03:29 by yhebbat           #+#    #+#             */
/*   Updated: 2021/07/16 17:21:26 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prj.h"

void	ft_rotate_a(t_list *head, int i, int fromdown)
{
	if (fromdown == 1)
	{
		while (i > 0)
		{
			reverse_rotate(head);
			ft_putstr("rra\n");
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			rotate(head);
			ft_putstr("ra\n");
			i--;
		}
	}
}

void	last_actions(t_list	*head, int size_a)
{
	t_stack	*a;
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
