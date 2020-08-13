/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:52:04 by eellie            #+#    #+#             */
/*   Updated: 2020/08/08 15:52:25 by eellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_h.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *tree;

	tree = (t_btree *)malloc(sizeof(t_btree));
	if (tree)
	{
		tree->item = item;
		tree->left = 0;
		tree->right = 0;
	}
	return (tree);
}
