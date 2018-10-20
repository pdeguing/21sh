/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 06:40:28 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/20 08:01:25 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

	// We need to go down left counting operators
	// Then execute from bottom left
	// Get args from right of cmd
	// And change the execution environment depending on
	// counted operators.


void			execute(t_tree **root)
{
	pid_t		pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		if (execve((*root)->token->literal, &(*root)->token->literal, g_env) == -1)
		{
			ft_putstr_fd((*root)->token->literal, 2);
			ft_putendl_fd(": command not found", 2);
			exit(EXIT_FAILURE);
		}
	}
	if (pid > 0)
		wait(&pid);
}


/*
** So we can either implement word expansion in order to build the **args for execve
** OR
** Work without args for now to build the execution tree
*/
