/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <yhebbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:03:32 by yhebbat           #+#    #+#             */
/*   Updated: 2021/07/16 16:46:20 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prj.h"

void	helperfive(t_list *head, int i)
{
	if (i == 1)
	{
		swap(head);
		ft_putstr("sa\n");
	}
	else if (i == 2)
	{
		rotate(head);
		ft_putstr("ra\n");
		swap(head);
		ft_putstr("sa\n");
	}
	else if (i == 3)
	{
		reverse_rotate(head);
		ft_putstr("rra\n");
		reverse_rotate(head);
		ft_putstr("rra\n");
	}
	else if (i == 4)
	{
		reverse_rotate(head);
		ft_putstr("rra\n");
	}
}

int	find_min(t_list *head)
{
	t_stack	*a;
	int		tmp;
	int		i;

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
			break ;
		i++;
		a = a->suivant;
	}
	return (i);
}

void	ft_helperthree(t_list *head, t_stack *a)
{
	if (a->value < a->suivant->suivant->value)
	{
		swap(head);
		ft_putstr("sa\n");
	}
	else
	{
		rotate(head);
		ft_putstr("ra\n");
	}
}

void	ft_helpertthree(t_list *head, t_stack *a)
{
	if (a->value < a->suivant->suivant->value)
	{
		swap(head);
		rotate(head);
		ft_putstr("sa\nra\n");
	}
	else
	{
		reverse_rotate(head);
		ft_putstr("rra\n");
	}
}
