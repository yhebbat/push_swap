/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <yhebbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:02:17 by yhebbat           #+#    #+#             */
/*   Updated: 2021/07/16 18:21:50 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prj.h"

void	init(t_list *header, t_list *header_b)
{
	header->header = NULL;
	header_b->header = NULL;
	header->footer = NULL;
	header_b->footer = NULL;
}

int	main(int ac, char **av)
{
	t_list	*header;
	t_list	*header_b;

	if (ac > 1)
	{
		header = malloc(sizeof(t_list));
		header_b = malloc(sizeof(t_list));
		init(header, header_b);
		while (ac - 1 > 0)
		{
			if (check_value(header, av[ac - 1]))
				ft_exit();
			else
				ft_remplir(header, ft_atoi(av[ac - 1]), -1);
			ac--;
		}
		ft_get(header, header_b);
		if (ft_checker(header))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		ft_free(header);
		ft_free(header_b);
	}
}
