/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 18:33:10 by eellie            #+#    #+#             */
/*   Updated: 2020/03/16 18:37:42 by eellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int cn;
	int *res;

	cn = 0;
	res = (int *)malloc(sizeof(int) * length);
	while (cn < length)
	{
		res[cn] = (*f)(tab[cn]);
		++cn;
	}
	return (res);
}
