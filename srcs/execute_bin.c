/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:23:27 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/15 10:51:49 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**get_path(void)
{
	char	*path;

	path = get_varenv("PATH");
	if (path == NULL)
		return (NULL);
	return (ft_strsplit(path, ':'));
}

int		check_permissions(char *path)
{
	if (!access(path, F_OK) && access(path, X_OK))
	{
		ft_printf("%s: permission denied\n", path);
		return (-1);
	}
	return (0);
}

int		try_path(char *path, char **args)
{
	path = ft_strffjoin(path, "/");
	path = ft_strffjoin(path, args[0]);
	if (check_permissions(path) == -1)
		return (-2);
	if (execve(path, args, g_env) == -1)
		return (-1);
	ft_strdel(&path);
	return (0);
}

int		exec_allpath(char **args)
{
	int		i;
	char	**allpath;

	if (ft_strchr(args[0], '/'))
	{
		if (check_permissions(args[0]) == -1)
			return (-2);
		return (execve(args[0], args, g_env));
	}
	allpath = get_path();
	if (allpath == NULL)
		return (-1);
	i = 0;
	while (allpath[i] != NULL)
	{
		if (try_path(ft_strdup(allpath[i]), args) != -1)
			return (0);
		i++;
	}
	return (-1);
}

void		execute_bin(char **args, char flag, t_io **io_stack)
{
	pid_t		pid;

	pid = fork();
	signal(SIGINT, handle_childsig);
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		/*
		ft_printf(RED"cmd: %s\n"RESET, args[0]);
		*/
		io_redirect(io_stack);
		if (exec_allpath(args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	if (pid > 0)
	{
		if (!(flag & WAIT))
			signal(SIGCHLD, handle_sig_zom);
		else
			wait(&pid);
		signal(SIGINT, handle_sig);
	}
}
