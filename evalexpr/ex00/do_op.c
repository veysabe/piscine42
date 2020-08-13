/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:17:23 by eellie            #+#    #+#             */
/*   Updated: 2020/08/08 15:51:52 by eellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <stdio.h>

int		do_op(int a, char *op, int b)
{
	if (ft_strcmp(op, "+") == 0)
		ft_plus(a, b);
	else if (ft_strcmp(op, "-") == 0)
		ft_minus(a, b);
	else if (ft_strcmp(op, "/") == 0)
		ft_div(a, b);
	else if (ft_strcmp(op, "%") == 0)
		ft_mod(a, b);
	else if (ft_strcmp(op, "*") == 0)
		ft_mul(a, b);
	else
	{
		ft_putchar('0');
		ft_putchar('\n');
	}
	return (1);
}
