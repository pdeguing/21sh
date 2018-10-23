/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 08:27:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/23 07:52:30 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		execute_cmd(char **args, char flag, int fd_read, int fd_write)
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
				redirect_io(fd_read, fd_write);
				g_builtin_func[i](args + 1);
				return ;
			}
			i++;
		}
	}
	execute_bin(args, flag, fd_read, fd_write);
}
