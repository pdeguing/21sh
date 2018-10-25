/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:02:10 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/25 09:40:27 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	tree_print(t_tree **root)
{
	t_tree	*head;

	head = *root;
	if (head->left != NULL)
		tree_print(&head->left);
	ft_printf("%-20s > %s\n", g_strtype[head->token->type], head->token->literal);
	if (head->right != NULL)
		tree_print(&head->right);
}
