/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <yhebbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:03:19 by yhebbat           #+#    #+#             */
/*   Updated: 2021/07/16 16:45:17 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prj.h"

void	ft_free(t_list *head)
{
	if (head)
	{
		while (head->header != NULL)
		{
			ft_depiler(head);
		}
		free(head);
	}
}

void	ft_exit(void)
{
	ft_putstr("Error\n");
	exit(0);
}

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		write(1, &c[i++], 1);
}

int	ft_atoi(const char *str)
{
	long long	i;
	long long	sum;
	int			sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		sum = (sum * 10) + str[i] - '0';
		i++;
	}
	if (sum * sign > INT_MAX || sum * sign < INT_MIN || i > 12)
		return (0);
	return (sign * sum);
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
