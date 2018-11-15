/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:22:00 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/15 09:17:52 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	exe_op_semicolon(t_tree **root, char flag, t_io *io_stack)
{
	t_tree	*head;

	head = *root;
	execute_tree(&head->left, flag, io_stack);
	execute_tree(&head->right, flag, io_stack);
}

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
	execute_tree(&head->left, flag ^ WAIT, io_push(1, p[WRITE], io_stack, PIPELINE));
	close(p[WRITE]);
	execute_tree(&head->right, flag, io_push(0, p[READ], io_cpy, PIPELINE));
	close(p[READ]);
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

void	exe_op_dless(t_tree **root, char flag, t_io *io_stack)
{
	(void)root;
	(void)flag;
	(void)io_stack;
}

void	exe_op_io(t_tree **root, char flag, t_io *io_stack)
{
	t_tree	*head;

	head = *root;
	io_stack->dst = ft_atoi(head->token->literal);
	execute_tree(&head->left, flag, io_stack);
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
