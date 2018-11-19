/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:39:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 11:39:41 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		builtin_unsetenv(char **args)
{
	int		i;

	i = -1;
	while (args[++i] != NULL)
	{
		if (ft_strchr(args[i], '=') || ft_strchr(args[i], '*'))
		{
			ft_printf("unsetenv: %s: not a valid identifier\n", args[i]);
			continue ;
		}
		if (ft_pstrcchr(g_env, args[i], '=') != NULL)
			env_remove(args[i]);
	}
	return (0);
}
