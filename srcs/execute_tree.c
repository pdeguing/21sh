/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 08:42:57 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/15 10:42:24 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			get_nbr_args(t_tree **root)
{
	t_tree	*head;
	int		i;

	i = 0;
	head = *root;
	while (head)
	{
		i++;
		head = head->right;
	}
	return (i);
}

char		**get_args(t_tree **root)
{
	char	**args;
	t_tree	*head;
	int		size;
	int		i;

	size = get_nbr_args(root);
	args = malloc(sizeof(char *) * (size + 1));
	args[size] = NULL;
	head = *root;
	i = 0;
	while (i < size)
	{
		args[i] = head->token->literal;
		head = head->right;
		i++;
	}
	return (args);
}

void				(*g_exe[TOTAL_TYPE])(t_tree **, char, t_io *) = {
	[IO_NUMBER] = &exe_op_io,
	[LESS] = &exe_op_less,
	[GREAT] = &exe_op_great,
	[DLESS] = &exe_op_dless,
	[DGREAT] = &exe_op_dgreat,
	[LESSAND] = &exe_op_lessand,
	[GREATAND] = &exe_op_greatand,
	[PIPELINE] = &exe_op_pipe,
	[SEMICOLON] = &exe_op_semicolon
};

void		execute_tree(t_tree **root, char flag, t_io *io_stack)
{
	t_tree	*head;

	head = *root;
	if (!head)
		return ;
	if (!head->left)
		execute_cmd(get_args(&head), flag, &io_stack);
	else
		return (g_exe[head->token->type](root, flag, io_stack));
}
