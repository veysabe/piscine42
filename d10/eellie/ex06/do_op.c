/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:17:23 by eellie            #+#    #+#             */
/*   Updated: 2020/03/17 17:09:17 by eellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		a;
	int		b;
	char	op;

	if (argc != 4)
		return (0);
	a = (ft_atoi(argv[1]));
	b = (ft_atoi(argv[3]));
	op = argv[2][0];
	if (op == '+')
		ft_plus(a, b);
	else if (op == '-')
		ft_minus(a, b);
	else if (op == '/')
		ft_div(a, b);
	else if (op == '%')
		ft_mod(a, b);
	else if (op == 42)
		ft_mul(a, b);
	else
	{
		ft_putchar('0');
		ft_putchar('\n');
	}
}
