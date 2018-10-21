/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 08:27:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/20 18:03:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

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
		if (execve(args[0], args, g_env) == -1)
		{
			perror(args[0]);
			/*
			ft_putstr_fd(args[0], 2);
			ft_putendl_fd(": command not found", 2);
			*/
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
