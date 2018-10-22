/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 08:27:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/22 08:24:12 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

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

void		execute_cmd(char **args, char flag, int fd_read, int fd_write)
{
	pid_t		pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		/* Temporary */
		if (fd_read != STDIN)
		{
			close(0);
			dup(fd_read);
			close(fd_read);
		}
		if (fd_write != STDOUT)
		{
			close(1);
			dup(fd_write);
			close(fd_write);
		}
		if (exec_allpath(args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	if (pid > 0)
	{
		if (flag & ~WAIT)
			return ;
		wait(&pid);
	}
}

/*
void			execute_cmd(char **args)
{
	static int	p[2];
	static int	i = 0;

	if (i == 0)
		pipe(p);
	ft_printf("cmd = %s, STDIN = %d, STDOUT = %d\n", *args, p[STDIN], p[STDOUT]);
	execute_pipe(args, p);
	if (i == 0)
		p[STDOUT] = NO_PIPE;
	i++;
}
*/
