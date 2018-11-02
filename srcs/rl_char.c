/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:06:46 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/01 17:39:54 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	rl_char_insert(t_rl *rl)
{
	char *tmp;

	tmp = rl->buf;
	rl->len++;
	rl->buf = ft_strnew(rl->len + 1);
	if (tmp)
	{
		ft_strcpy(rl->buf, tmp);
		ft_memmove(rl->buf + rl->cx + 1, rl->buf + rl->cx, rl->len - rl->cx);
	}
	rl->buf[rl->cx] = rl->key;
	ft_strdel(&tmp);
	// move_cursor_right();
}
