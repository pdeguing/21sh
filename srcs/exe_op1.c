/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_op1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:48:12 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 16:27:22 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	exe_op_dless(t_ast **root, char flag, t_io *io_stack)
{
	char	*line;
	char	*delimiter;
	char	*heredoc;
	int		expand;
	t_ast	*head;
	int		p[2];

	head = *root;
	heredoc = ft_strnew(0);
	line = ft_strnew(0);
	delimiter = head->right->token->literal;
	if (pipe(p) == -1)
	{
		perror("21sh");
		exit(EXIT_FAILURE);
	}
	expand = 1;
	if (ft_strchr(delimiter, '\\') || ft_strchr(delimiter, '\'') || ft_strchr(delimiter, '\"'))
	{
		expand = 0;
		delimiter = parse_quote_remove(delimiter);
	}
	while (1)
	{
		ft_strdel(&line);
		line = rl_readline("> ", 2, NO_QUOTE | NO_HISTORY);
		if (!line)
			line = ft_strnew(0);
		if (!ft_strcmp(delimiter, line))
			break ;
		line = ft_strffjoin(line, "\n");
		heredoc = ft_strffjoin(heredoc, line);
	}
	ft_strdel(&line);
	if (expand)
		heredoc = rl_expansion(heredoc);
	ft_putstr_fd(heredoc, p[WRITE]);
	ft_strdel(&heredoc);
	close(p[WRITE]);
	execute(&head->left, flag, io_push(0, p[READ], io_stack, PIPELINE));
	close(p[READ]);
}

void	exe_op_dgreat(t_ast **root, char flag, t_io *io_stack)
{
	int		fd;
	t_ast	*head;

	head = *root;
	fd = open(head->right->token->literal, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
	{
		perror(head->right->token->literal);
		exit(EXIT_FAILURE);
	}
	execute(&head->left, flag, io_push(1, fd, io_stack, DGREAT));
	close(fd);
}

void	exe_op_greatand(t_ast **root, char flag, t_io *io_stack)
{
	int		fd;
	t_ast	*head;

	head = *root;
	if (!head->right || !head->right->token->literal)
		fd = 1;
	else if (ft_strcmp(head->right->token->literal, "-"))
		fd = ft_atoi(head->right->token->literal);
	else
		fd = '-';
	/* Check if open for output */
	execute(&head->left, flag, io_push(1, fd, io_stack, GREATAND));
}

void	exe_op_lessand(t_ast **root, char flag, t_io *io_stack)
{
	int		fd;
	t_ast	*head;

	head = *root;
	if (!head->right || !head->right->token->literal)
		fd = 0;
	else if (ft_strcmp(head->right->token->literal, "-"))
		fd = ft_atoi(head->right->token->literal);
	else
		fd = '-';
	/* Check if open for input */
	execute(&head->left, flag, io_push(0, fd, io_stack, LESSAND));
}
