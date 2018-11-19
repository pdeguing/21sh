/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:39:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 11:39:22 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		builtin_setenv(char **args)
{
	int		i;

	i = -1;
	while (args[++i] != NULL)
	{
		if (!ft_strchr(args[i], '='))
		{
			ft_printf("usage: setenv NAME=value\n");
			return (0);
		}
		else if (!env_replace(ft_strdup(args[i])))
			env_add(args[i]);
	}
	return (0);
}
