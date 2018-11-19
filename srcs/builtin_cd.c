/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:38:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 11:38:26 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		builtin_cd(char **args)
{
	char	*old;

	if (args[0] != NULL && *args[0] == '-')
	{
		old = env_getvar("OLDPWD");
		if (old == NULL)
			return (-1);
		env_replace(ft_strfljoin("OLDPWD=", getcwd(NULL, 0)));
		if (chdir(old) == -1)
			return (-1);
	}
	else
	{
		env_replace(ft_strfljoin("OLDPWD=", getcwd(NULL, 0)));
		if (args[0] == NULL)
		{
			if (chdir(env_getvar("HOME")) == -1)
				return (-1);
		}
		else if (chdir(args[0]) == -1)
			return (-1);
	}
	env_replace(ft_strfljoin("PWD=", getcwd(NULL, 0)));
	return (0);
}
