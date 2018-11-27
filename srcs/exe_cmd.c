/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:22:29 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/27 07:00:06 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*g_builtin_name[BUILTIN_NBR] =
{
	"echo",
	"cd",
	"env",
	"setenv",
	"unsetenv",
	"exit",
	"history"
};

int		(*g_builtin_func[BUILTIN_NBR])(char **) =
{
	&builtin_echo,
	&builtin_cd,
	&builtin_env,
	&builtin_setenv,
	&builtin_unsetenv,
	&builtin_exit,
	&history_builtin
};

void		exe_cmd(char **args, char flag, t_io *io_stack)
{
	int		i;

	if (args == NULL || args[0] == NULL)
		return ;
	i = 0;
	if (!ft_strchr(args[0], '/'))
	{
		while (i < BUILTIN_NBR)
		{
			if (ft_strcmp(args[0], g_builtin_name[i]) == 0)
			{
				io_redirect(io_stack);
				g_builtin_func[i](args + 1);
				free(args);
				return ;
			}
			i++;
		}
	}
	exe_bin(args, flag, io_stack);
}
