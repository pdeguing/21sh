/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:42:09 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/23 08:45:18 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define BUILTIN_NBR	6

int				ft_echo(char **args);
int				ft_cd(char **args);
int				ft_env(char **args);
int				ft_setenv(char **args);
int				ft_unsetenv(char **args);
int				ft_exit(char **args);

int				ft_echo(char **args);
int				ft_cd(char **args);
int				ft_env(char **args);
int				ft_setenv(char **args);
int				ft_unsetenv(char **args);
int				ft_exit(char **args);

int				replace_env(char *arg);

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

#endif
