/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:16:41 by eellie            #+#    #+#             */
/*   Updated: 2020/08/05 17:52:22 by eellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"
#include <stdio.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *temp;

	if (*begin_list == NULL)
		*begin_list = ft_create_elem(data);
	else
	{
		temp = *begin_list;
		while ((*temp).next != NULL)
			temp = (*temp).next;
		(*temp).next = ft_create_elem(data);
	}
}
