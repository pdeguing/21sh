/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:39:50 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/21 11:17:15 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#define HEAD	head->token->type
#define NEW		new->token->type

static int	precedence_cmp(t_ast *new, t_ast *head)
{
	int		tnew;
	int		thead;

	tnew = new->token->type;
	thead = head->token->type;
	if (tnew == IO_NUMBER)
		tnew = LESS;
	if (IS_OP(tnew))
		tnew = LESS;
	if (IS_OP(thead))
		thead = LESS;
	return (tnew - thead);
}

void		ast_insert(t_ast **root, t_ast *new)
{
	t_ast	*head;

	head = *root;
	if (head == NULL)
		*root = new;
	else if (NEW != TOKEN && precedence_cmp(new, head) >= 0)
	{
		*root = new;
		new->left = head;
	}
	else if (NEW == TOKEN && ((head->right && IS_OP(HEAD))
				|| HEAD == IO_NUMBER))
		ast_insert(&head->left, new);
	else
		ast_insert(&head->right, new);
}

#undef NEW
#undef HEAD
