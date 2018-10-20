/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 08:42:57 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/20 13:08:45 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char		**get_args(t_token *cmd)
{
	char	**args;

	args = malloc(sizeof(char *) * 2);
	args[0] = cmd->literal;
	args[1] = NULL;
	return (args);
}

void		execute_tree(t_tree **root)
{
	t_tree	*head;

	head = *root;
	if (!head)
		return ;
	if (head->left)
		execute_tree(&head->left);
	if (!head->left && !head->right)
		execute_cmd(get_args(head->token));
	if (head->right)
		execute_tree(&head->right);
}
