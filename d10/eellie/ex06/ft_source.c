/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 22:55:32 by eellie            #+#    #+#             */
/*   Updated: 2020/03/17 16:34:21 by eellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int cn;

	cn = 0;
	while (str[cn] != '\0')
	{
		ft_putchar(str[cn]);
		cn++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
	{
		nbr = nb;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

int		ft_atoi(char *str)
{
	int cn;
	int minus;
	int res;

	cn = 0;
	minus = 1;
	res = 0;
	while (str[cn] != '\0' && (str[cn] == ' ' || \
				str[cn] == 32 || (str[cn] >= 9 && str[cn] <= 13)))
		cn++;
	if (str[cn] == '-')
		minus = -1;
	if (str[cn] == '-' || str[cn] == '+')
		cn++;
	while (str[cn] && str[cn] >= '0' && str[cn] <= '9')
	{
		res = (res * 10) + (str[cn] - 48);
		cn++;
	}
	return (res * minus);
}
