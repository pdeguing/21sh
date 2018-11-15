/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_op1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:48:12 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/15 09:49:20 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	exe_op_dless(t_tree **root, char flag, t_io *io_stack)
{
	(void)root;
	(void)flag;
	(void)io_stack;
}

void	exe_op_dgreat(t_tree **root, char flag, t_io *io_stack)
{
	int		fd;
	t_tree	*head;

	head = *root;
	fd = open(head->right->token->literal, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
	{
		perror(head->right->token->literal);
		exit(EXIT_FAILURE);
	}
	execute_tree(&head->left, flag, io_push(1, fd, io_stack, DGREAT));
	close(fd);
}

void	exe_op_greatand(t_tree **root, char flag, t_io *io_stack)
{
	int		fd;
	t_tree	*head;

	head = *root;
	fd = '-';
	if (ft_strcmp(head->right->token->literal, "-"))
		fd = ft_atoi(head->right->token->literal);
	/* Check if open for output */
	execute_tree(&head->left, flag, io_push(1, fd, io_stack, GREATAND));
}

void	exe_op_lessand(t_tree **root, char flag, t_io *io_stack)
{
	int		fd;
	t_tree	*head;

	head = *root;
	fd = ft_atoi(head->right->token->literal);
	/* Check if open for input */
	execute_tree(&head->left, flag, io_push(0, fd, io_stack, LESSAND));
}
