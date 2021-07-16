/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <yhebbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:04:06 by yhebbat           #+#    #+#             */
/*   Updated: 2021/07/16 17:55:05 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prj.h"

int	ft_lena(t_list *head_a)
{
	t_stack	*a;
	int		i;

	i = 1;
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
	int	i;

	i = ft_lena(head_a);
	index_numbers(head_a, head_b, i);
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
	int	i;

	i = ac;
	while (i - 1 > 0)
	{
		if (check_value(header, av[i - 1]))
			ft_exit();
			
		else
			ft_remplir(header, ft_atoi(av[i - 1]), -1);
		i--;
	}
}

int	main(int ac, char **av)
{
	t_list	*header;
	t_list	*header_b;
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
		// system ("leaks push_swap");
		exit(0);
	}
	else
		ft_exit();
}
