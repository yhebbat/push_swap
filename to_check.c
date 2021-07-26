/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <yhebbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:04:11 by yhebbat           #+#    #+#             */
/*   Updated: 2021/07/17 19:04:39 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prj.h"

int	is_digit(char *str)
{
	if (*(str + 1) != '\0' && (*str == '+' || *str == '-'))
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	check_duplicate(t_list *head, char *str)
{
	t_stack	*a;

	if (head->header != NULL)
	{
		a = head->header;
		while (a != NULL)
		{
			if (a->value == ft_atoi(str))
				return (1);
			a = a->suivant;
		}
	}
	return (0);
}

long long	ft_overflowhelper(char *str)
{
	long long	a;
	long		sign;

	a = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		str++;
		sign = (-1);
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		a = a * 10 + *str - '0';
		str++;
	}
	if (a < 0 && sign < 0)
		return (0);
	if (a < 0 && sign > 0)
		return (-1);
	return (a * sign);
}

int	check_overflow(char *str)
{
	long long	r;

	r = ft_overflowhelper(str);
	if (ft_strlen(str) > 15)
		return (1);
	if (r > 2147483647 || r < -2147483648)
		return (1);
	return (0);
}

int	check_value(t_list *head, char *str)
{
	if (is_digit(str) || check_overflow(str) || check_duplicate(head, str))
		return (1);
	return (0);
}
