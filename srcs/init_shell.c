/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:41:20 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/31 15:26:43 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_shell		*init_shell(char **env)
{
	t_shell	*sh;

	init_env(env);
	// Need a QUOTED state in sh;
	// Need array of termcaps strings or just call str at runtime?
	sh = (t_shell *)malloc(sizeof(t_shell));
	sh->quote_status = 0;
	return (sh);
}
