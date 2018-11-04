/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:22:53 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/03 17:11:10 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	key_del_backspace(t_rl *rl)
{
	if (!(rl->cx > 0))
		return ;
	ft_memmove(rl->buf + rl->cx - 1, rl->buf + rl->cx, rl->blen - rl->cx + 1);
	rl->blen--;
	key_cursor_left(rl);
}

void	key_del_delete(t_rl *rl)
{
	if (!(rl->cx < rl->blen))
		return ;
	ft_memmove(rl->buf + rl->cx, rl->buf + rl->cx + 1, rl->blen - rl->cx + 1);
	rl->blen--;
}

void	key_del_beg(t_rl *rl)
{
	while (rl->cx)
		key_del_backspace(rl);
}

void	key_del_end(t_rl *rl)
{
	while (rl->cx < rl->blen)
		key_del_delete(rl);
}
