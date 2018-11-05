/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_clipboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:29:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/05 09:59:17 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char						*g_clipboard = NULL;

void	key_copy(t_rl *rl)
{
	ft_strdel(&g_clipboard);
	g_clipboard = ft_strdup(rl->buf);
}

void	key_paste(t_rl *rl)
{
	ft_strdel(&rl->buf);
	rl->buf = ft_strdup(g_clipboard);
	rl->blen = ft_strlen(rl->buf);
	rl->cx = rl->blen;
}
