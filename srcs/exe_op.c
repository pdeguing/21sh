/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:22:00 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 10:05:40 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	exe_op_io(t_tree **root, char flag, t_io *io_stack)
{
	t_tree	*head;

	head = *root;
	io_stack->dst = ft_atoi(head->token->literal);
	execute_tree(&head->left, flag, io_stack);
}

void	exe_op_great(t_tree **root, char flag, t_io *io_stack)
{
	int		fd;
	t_tree	*head;

	head = *root;
	fd = open(head->right->token->literal, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror(head->right->token->literal);
		exit(EXIT_FAILURE);
	}
	execute_tree(&head->left, flag, io_push(1, fd, io_stack, GREAT));
	close(fd);
}

void	exe_op_less(t_tree **root, char flag, t_io *io_stack)
{
	int		fd;
	t_tree	*head;

	head = *root;
	fd = open(head->right->token->literal, O_RDONLY);
	if (fd == -1)
	{
		perror(head->right->token->literal);
		exit(EXIT_FAILURE);
	}
	execute_tree(&head->left, flag, io_push(0, fd, io_stack, LESS));
	close(fd);
}
