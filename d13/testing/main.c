/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:43:38 by eellie            #+#    #+#             */
/*   Updated: 2020/08/08 00:56:46 by eellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item);

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	applyf(root->item);
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
}

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (!*root)
		*root = btree_create_node(item);
	else if (cmpf((*root)->item, item) > 0)
		btree_insert_data(&((*root)->left), item, cmpf);
	else
		btree_insert_data(&((*root)->right), item, cmpf);
}

void	check()
{
	printf("%d\n", 1);
}

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*result;

	result = NULL;
	if (root->left)
		result = btree_search_item(root->left, data_ref, cmpf);
	if (!result && cmpf(root->item, data_ref) == 0)
		return (root->item);
	if (!result && root->right)
		result = btree_search_item(root->right, data_ref, cmpf);
	return (result);
}

int maxDepth(t_btree *node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
} 
int		main()
{
	char *node = "new item";
	char *new_node = "lll";
	t_btree *tree;
	
	tree = btree_create_node(node);
	tree->left = btree_create_node(node);
	tree->right = btree_create_node(node);
	btree_apply_prefix(tree, &check);
	tree->left->item = btree_create_node(node);
	tree->left->left = btree_create_node(node);
	tree->left->right = btree_create_node(node);
	tree->right->item = btree_create_node(node);
	tree->right->left = btree_create_node(node);
	tree->right->right = btree_create_node(node);
	tree->right->right->item = btree_create_node(node);
	tree->right->right->left = btree_create_node(node);
	tree->right->right->right = btree_create_node(node);
	printf("%d\n", maxDepth(tree));
	return (0);
}
