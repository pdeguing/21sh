/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:24:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 10:31:02 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*env_getvar(char *name)
{
	char	**var;

	var = ft_pstrcchr(g_env, name, '=');
	if (var == NULL)
		return (NULL);
	return (*var + ft_strlen(name) + 1);
}

int		env_getlen(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
		i++;
	return (i);
}

int		env_replace(char *arg)
{
	char	*tmp;
	char	**env;

	env = ft_pstrcchr(g_env, arg, '=');
	if (env == NULL)
	{
		ft_strdel(&arg);
		return (0);
	}
	tmp = *env;
	*env = arg;
	free(tmp);
	return (1);
}

void	env_add(char *arg)
{
	int		i;
	int		len;
	char	**tmp;

	len = env_getlen(g_env) + 1;
	tmp = g_env;
	g_env = (char **)malloc(sizeof(char *) * (len + 1));
	g_env[len] = NULL;
	i = 0;
	while (tmp[i] != NULL)
	{
		g_env[i] = ft_strdup(tmp[i]);
		i++;
	}
	g_env[i] = ft_strdup(arg);
	ft_pstrdel(tmp);
}

void	env_remove(char *arg)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;

	len = env_getlen(g_env) - 1;
	tmp = g_env;
	g_env = (char **)malloc(sizeof(char *) * (len + 1));
	g_env[len] = NULL;
	i = 0;
	j = 0;
	while (tmp[i] != NULL && j < len)
	{
		if (ft_strccmp(tmp[i], arg, '='))
		{
			g_env[j] = ft_strdup(tmp[i]);
			j++;
		}
		i++;
	}
	ft_pstrdel(tmp);
}
