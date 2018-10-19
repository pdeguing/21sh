/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:04:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/19 12:51:23 by pdeguing         ###   ########.fr       */
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

void		tree_insert(t_tree **root, t_tree *new)
{
	t_tree	*head;

	head = *root;
	/* Set root to first token */
	if (head == NULL)
	{
		*root = new;
	}
	/* Push the left branch down one level */
	else if (new->token->type >= head->token->type)
	{
		*root = new;
		new->left = head;
	}
	else if (head->token->type == TOKEN)
	{
		/* Insert arguments as right child of command */
		while (head->right != NULL)
		{
			head = head->right;
		}
		head->right = new;
	}
	/* Insert new node as pipe right child */
	else if (head->token->type == PIPE)
	{
		tree_insert(&head->right, new);
	}
	/* Insert new node as right descendant */
	else if (head->token->type == SEMICOLON)
	{
		tree_insert(&head->right, new);
	}
}



/*
** Possibilities:
**
** 		-> root is NULL: we just insert new;
** 		-> new >= head: we push head down new->left;
** 		-> new < head: we call insert recursivily w/ head =  head->right; 
*/
