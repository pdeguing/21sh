/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:22:00 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/21 11:07:04 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	exe_op_io(t_ast **root, char flag, t_io *io_stack)
{
	t_ast	*head;

	head = *root;
	execute(&head->left, flag, io_stack);
}

void	exe_op_great(t_ast **root, char flag, t_io *io_stack)
{
	int		fd;
	int		dst;
	t_ast	*head;

	head = *root;
	fd = open(head->right->token->literal, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror(head->right->token->literal);
		exit(EXIT_FAILURE);
	}
	dst = 1;
	if (head->left->token->type == IO_NUMBER)
		dst = ft_atoi(head->left->token->literal);
	execute(&head->left, flag, io_push(dst, fd, io_stack, GREAT));
	close(fd);
}

void	exe_op_less(t_ast **root, char flag, t_io *io_stack)
{
	int		fd;
	t_ast	*head;

	head = *root;
	fd = open(head->right->token->literal, O_RDONLY);
	if (fd == -1)
	{
		perror(head->right->token->literal);
		exit(EXIT_FAILURE);
	}
	execute(&head->left, flag, io_push(0, fd, io_stack, LESS));
	close(fd);
}
