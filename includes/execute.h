/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:29:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/22 12:57:53 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "shell.h"
# include "builtins.h"

# define NO_PIPE		-1
# define STDIN			0
# define STDOUT			1
# define READ			0
# define WRITE			1
# define WAIT			0x1
# define BUILTIN_NBR	6

int				ft_echo(char **args);
int				ft_cd(char **args);
int				ft_env(char **args);
int				ft_setenv(char **args);
int				ft_unsetenv(char **args);
int				ft_exit(char **args);

char	*g_builtin_name[BUILTIN_NBR] =
{
	"echo",
	"cd",
	"env",
	"setenv",
	"unsetenv",
	"exit",
};

int		(*g_builtin_func[BUILTIN_NBR])(char **) =
{
	&ft_echo,
	&ft_cd,
	&ft_env,
	&ft_setenv,
	&ft_unsetenv,
	&ft_exit,
};

void				redirect_io(int fd_read, int fd_write);

void				execute_bin(char **args, char flag, int fd_read, int fd_write);
void				execute_cmd(char **args, char flag, int fd_read, int fd_write);
void				execute_tree(t_tree **root, char flag, int fd_read, int fd_write);
void				execute(t_tree **root);

#endif
