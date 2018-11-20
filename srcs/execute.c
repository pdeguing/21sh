/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:46:06 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/20 12:16:59 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			get_nbr_args(t_ast **root)
{
	t_ast	*head;
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

char		**get_args(t_ast **root)
{
	char	**args;
	t_ast	*head;
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

void				(*g_exe[TOTAL_TYPE])(t_ast **, char, t_io *) = {
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

void		execute(t_ast **root, char flag, t_io *io_stack)
{
	t_ast	*head;

	head = *root;
	if (!head)
		return ;
	io_print(&io_stack);
	if (!head->left)
	{
		exe_cmd(get_args(&head), flag, &io_stack);
		io_free(&io_stack);
	}
	else
		return (g_exe[head->token->type](root, flag, io_stack));
}
