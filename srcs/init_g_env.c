/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_g_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:39:27 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/20 08:01:27 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		get_envlen(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
		i++;
	return (i);
}

void	init_g_env(char **env)
{
	int		i;
	int		len;

	len = get_envlen(env);
	if (len == 0)
		return ;
	g_env = (char **)malloc(sizeof(char *) * (len + 1));
	if (g_env == NULL)
	{
		ft_putendl_fd("21sh: cannot allocate memory", 2);
		exit(EXIT_FAILURE);
	}
	g_env[len] = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		g_env[i] = ft_strdup(env[i]);
		if (g_env[i] == NULL)
		{
			ft_putendl_fd("21sh: cannot allocate memory", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
