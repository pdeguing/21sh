/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:01:55 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/23 07:52:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_cd(char **args)
{
	char	*old;

	if (args[0] != NULL && *args[0] == '-')
	{
		old = get_varenv("OLDPWD");
		if (old == NULL)
			return (-1);
		replace_env(ft_strfljoin("OLDPWD=", getcwd(NULL, 0)));
		if (chdir(old) == -1)
			return (-1);
	}
	else
	{
		replace_env(ft_strfljoin("OLDPWD=", getcwd(NULL, 0)));
		if (args[0] == NULL)
		{
			if (chdir(get_varenv("HOME")) == -1)
				return (-1);
		}
		else if (chdir(args[0]) == -1)
			return (-1);
	}
	replace_env(ft_strfljoin("PWD=", getcwd(NULL, 0)));
	return (0);
}
