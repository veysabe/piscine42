/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:13:41 by eellie            #+#    #+#             */
/*   Updated: 2020/08/12 23:03:36 by eellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

extern int g_lines;

int			**arr_mallocer(int len)
{
	int		**matrix;
	int		i;

	i = 0;
	matrix = malloc(sizeof(int*) * g_lines);
	if (matrix)
	{
		while (i < g_lines)
		{
			matrix[i] = malloc(sizeof(int) * len);
			i++;
		}
	}
	return (matrix);
}

char		**char_mallocer(int len)
{
	char	**output;
	int		i;

	i = 0;
	output = malloc(sizeof(char*) * g_lines);
	if (output)
	{
		while (i < g_lines)
		{
			output[i] = malloc(sizeof(char) * len);
			i++;
		}
	}
	return (output);
}

t_list		*ft_create_elem(char data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}

void		ft_push_back(t_list **begin_list, char data)
{
	t_list	*end;

	if (begin_list == NULL)
	{
		return ;
	}
	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	end = *begin_list;
	while (end->next != NULL)
		end = end->next;
	end->next = ft_create_elem(data);
}

void		ft_list_clear(t_list **begin_list)
{
	while (*begin_list && ((*begin_list)->next != NULL))
		ft_list_clear(&(*begin_list)->next);
	free(*begin_list);
	*begin_list = NULL;
}
