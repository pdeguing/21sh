/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:04:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/19 15:05:55 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
** For error checking, we can set a state of expectation, if new is not
** expected, then we exit.
*/

/*
** We will be able to make the rules clean by working with priority, indexing
** the enum by order of priority from less to more so that we can just do:
**
** 		if (new->type >= head->type)
**				push_left_branch_down();
*/

static int	precedence_cmp(t_tree *node1, t_tree *node2)
{
	int		type1;
	int		type2;

	type1 = node1->token->type;
	type2 = node2->token->type;
	if (LESS <= type1 && type1<= GREATAND)
		type1 = LESS;
	if (LESS <= type2 && type2 <= GREATAND)
		type2 = LESS;
	return (type1 - type2);
}

void		tree_insert(t_tree **root, t_tree *new)
{
	t_tree	*head;

	head = *root;
	if (head == NULL)
		*root = new;
	else if (precedence_cmp(new, head) > 0)
	{
		*root = new;
		new->left = head;
	}
	else
		tree_insert(&head->right, new);
}



/*
** Possibilities:
**
** 		-> root is NULL: we just insert new;
** 		-> new >= head: we push head down new->left;
** 		-> new < head: we call insert recursivily w/ head =  head->right; 
*/
