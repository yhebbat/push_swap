/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <yhebbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:03:26 by yhebbat           #+#    #+#             */
/*   Updated: 2021/07/16 17:34:59 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prj.h"

void	initialiser(int *t)
{
	t[NBRINSA] = 0;
	t[NBRINSB] = 0;
	t[NBRINSAB] = 0;
	t[LENA] = 0;
	t[LENB] = 0;
	t[NBA] = 0;
	t[NBB] = 0;
	t[NBAB] = MAXIM;
	t[FROMUPA] = 1;
	t[FROMUPB] = 1;
	t[UPA] = 0;
	t[UPB] = 0;
}
