/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:04:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/25 12:08:45 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	precedence_cmp(t_tree *new, t_tree *head)
{
	int		tnew;
	int		thead;

	tnew = new->token->type;
	thead = head->token->type;
	/*
	ft_printf(RED"PRECEDENCE: "RESET"%d | vs | %d\n", type1, type2);
	*/
	if (IS_OP(tnew))
		tnew = LESS;
	if (IS_OP(thead))
		thead = LESS;
	return (tnew - thead);
}

void		tree_insert(t_tree **root, t_tree *new)
{
	t_tree	*head;

	head = *root;
	if (head == NULL)
		*root = new;
	else if (precedence_cmp(new, head) >= 0 && new->token->type != TOKEN)
	{
		*root = new;
		new->left = head;
	}
	else if (IS_OP(head->token->type) && head->right)
		tree_insert(&head->left, new);
	else
		tree_insert(&head->right, new);
}
