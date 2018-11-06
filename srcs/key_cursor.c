/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:24:39 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/06 14:55:43 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	key_cursor_left(t_rl *rl)
{
	if (!(rl->cx > 0))
		return ;
	ft_putstr(tgetstr("le", NULL));
	rl->cx--;
}

void	key_cursor_right(t_rl *rl)
{
	if (!(rl->cx <= rl->row[rl->cy].bsize))
		return ;
	ft_putstr(tgetstr("nd", NULL));
	rl->cx++;
}

void	key_cursor_up(t_rl *rl)
{
	if (rl->cy == 0)
		return ;
	ft_putstr(tgetstr("up", NULL));
	rl->cy--;
	if (rl->cx > rl->row[rl->cy].bsize)
		rl->cx = rl->row[rl->cy].bsize;
}

void	key_cursor_down(t_rl *rl)
{
	if (rl->cy >= rl->row_max - 1)
		return ;
	ft_putstr(tgetstr("do", NULL));
	rl->cy++;
	if (rl->cx > rl->row[rl->cy].bsize)
		rl->cx = rl->row[rl->cy].bsize;
}
