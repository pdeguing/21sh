/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_op2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:49:31 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 11:47:18 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	exe_op_pipe(t_tree **root, char flag, t_io *io_stack)
{
	int		p[2];
	t_io	*io_cpy;
	t_tree	*head;

	head = *root;
	if (pipe(p) == -1)
	{
		perror("21sh");
		exit(EXIT_FAILURE);
	}
	io_cpy = io_stack_dup(io_stack);
	execute(&head->left, flag ^ WAIT, io_push(1, p[WRITE], io_stack, PIPELINE));
	close(p[WRITE]);
	execute(&head->right, flag, io_push(0, p[READ], io_cpy, PIPELINE));
	close(p[READ]);
}

void	exe_op_semicolon(t_tree **root, char flag, t_io *io_stack)
{
	t_tree	*head;

	head = *root;
	execute(&head->left, flag, io_stack);
	execute(&head->right, flag, io_stack);
}
