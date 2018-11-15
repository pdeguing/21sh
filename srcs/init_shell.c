/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:41:20 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/15 10:51:47 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		init_shell(char **env)
{
	char	*tname;
	char	tbuf[1024];

	tname = getenv("TERM");
	tgetent(tbuf, tname);
	init_env(env);
	signal(SIGTERM, SIG_IGN);
}
