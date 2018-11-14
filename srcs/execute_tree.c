/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 08:42:57 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/13 15:56:53 by pdeguing         ###   ########.fr       */
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

void		execute_tree(t_tree **root, char flag, t_io *io_stack)
{
	t_tree	*head;
	int		p[2];
	int		fd;
	t_io	*io_cpy;

	head = *root;
	if (!head)
		return ;
	if (!head->left)
		execute_cmd(get_args(&head), flag, &io_stack);
	else if (head->token->type == SEMICOLON)
	{
		execute_tree(&head->left, flag, io_stack);
		execute_tree(&head->right, flag, io_stack);
	}
	else if (head->token->type == PIPELINE)
	{
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
	else if (head->token->type == GREAT)
	{
		fd = open(head->right->token->literal, O_WRONLY | O_CREAT, 0644);
		if (fd == -1)
		{
			perror(head->right->token->literal);
			exit(EXIT_FAILURE);
		}
		execute_tree(&head->left, flag, io_push(1, fd, io_stack, GREAT));
		close(fd);
	}
	else if (head->token->type == LESS)
	{
		fd = open(head->right->token->literal, O_RDONLY);
		if (fd == -1)
		{
			perror(head->right->token->literal);
			exit(EXIT_FAILURE);
		}
		execute_tree(&head->left, flag, io_push(0, fd, io_stack, LESS));
		close(fd);
	}
	else if (head->token->type == DGREAT)
	{
		fd = open(head->right->token->literal, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (fd == -1)
		{
			perror(head->right->token->literal);
			exit(EXIT_FAILURE);
		}
		execute_tree(&head->left, flag, io_push(1, fd, io_stack, DGREAT));
		close(fd);
	}
	else if (head->token->type == IO_NUMBER)
	{
		io_stack->dst = ft_atoi(head->token->literal);
		execute_tree(&head->left, flag, io_stack);

	}
	else if (head->token->type == GREATAND)
	{
		fd = '-';
		if (ft_strcmp(head->right->token->literal, "-"))
			fd = ft_atoi(head->right->token->literal);
		/* Check if open for output */
		execute_tree(&head->left, flag, io_push(1, fd, io_stack, GREATAND));
	}
	else if (head->token->type == LESSAND)
	{
		fd = ft_atoi(head->right->token->literal);
		/* Check if open for input */
		execute_tree(&head->left, flag, io_push(0, fd, io_stack, LESSAND));
	}
}
