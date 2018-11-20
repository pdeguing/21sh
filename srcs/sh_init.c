/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:14:45 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 16:00:27 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		sh_init(char **env)
{
	char	*tname;
	char	tbuf[1024];

	tname = getenv("TERM");
	tgetent(tbuf, tname);
	env_init(env);
	signal(SIGTERM, SIG_IGN);
}
