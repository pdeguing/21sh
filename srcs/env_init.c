/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:14:55 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 10:15:31 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	env_init(char **env)
{
	int		i;
	int		len;

	len = env_getlen(env);
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
