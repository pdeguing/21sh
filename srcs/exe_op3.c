/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_op3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 08:41:17 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/21 09:00:00 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		quote_remove(char **str)
{
	char	*new;
	char	*old;
	int		i;

	if (!*str || ft_strchr(*str, '\\') || ft_strchr(*str, '\'')
			|| ft_strchr(*str, '\"'))
		return (0);
	old = *str;
	new = ft_strnew(ft_strlen(old));
	i = 0;
	while (*old)
	{
		if (!ft_strchr("\\\'\"", *old))
		{
			new[i] = *old;
			i++;
		}
		old++;
	}
	new[i] = '\0';
	ft_strdel(str);
	*str = new;
	return (1);
}

static char		*get_heredoc(char *delimiter)
{
	char	*line;
	char	*heredoc;
	int		expand;

	expand = quote_remove(&delimiter);
	line = ft_strnew(0);
	heredoc = ft_strnew(0);
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
	ft_strdel(&delimiter);
	if (expand)
		heredoc = rl_expansion(heredoc);
	return (heredoc);
}

void			exe_op_dless(t_ast **root, char flag, t_io *io_stack)
{
	char	*heredoc;
	t_ast	*head;
	int		p[2];

	head = *root;
	if (pipe(p) == -1)
	{
		perror("21sh");
		exit(EXIT_FAILURE);
	}
	heredoc = get_heredoc(ft_strdup(head->right->token->literal));
	ft_putstr_fd(heredoc, p[WRITE]);
	ft_strdel(&heredoc);
	close(p[WRITE]);
	execute(&head->left, flag, io_push(0, p[READ], io_stack, DLESS));
	close(p[READ]);
}

void			exe_op_dgreat(t_ast **root, char flag, t_io *io_stack)
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
