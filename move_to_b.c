/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <yhebbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:03:44 by yhebbat           #+#    #+#             */
/*   Updated: 2021/07/16 16:44:50 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prj.h"

void	push_to_b(t_list *head_a, t_list *head_b)
{
	t_stack	*a;
	int		k;

	k = 0;
	while (ft_checker(head_a) != 1)
	{
		a = head_a->header;
		if (a->index < k + 12 && a->index >= k)
		{
			k = a->index;
			rotate(head_a);
			ft_putstr("ra\n");
		}
		else
		{
			push(head_b, head_a);
			ft_putstr("pb\n");
		}
	}
}
