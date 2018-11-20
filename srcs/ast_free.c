/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:14:11 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 16:03:33 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ast_free(t_ast **root)
{
	t_ast	*head;

	head = *root;
	if (!head)
		return ;
	ast_free(&head->left);
	ast_free(&head->right);
	ft_strdel(&head->token->literal);
	free(head->token);
	free(head);
}
