/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cursor2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:07:04 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/08 16:31:51 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	key_cursor_beg(t_rl *rl)
{
	while (rl->cx)
		key_cursor_left(rl);
}

void	key_cursor_end(t_rl *rl)
{
	while (rl->cx < rl->row[rl->cy].bsize)
		key_cursor_right(rl);
}

void	key_cursor_nword(t_rl *rl)
{
	while (rl->cx < rl->row[rl->cy].bsize && !ft_strchr(" 	", rl->row[rl->cy].buf[rl->cx]))
		key_cursor_right(rl);
	while (rl->cx < rl->row[rl->cy].bsize && ft_strchr(" 	", rl->row[rl->cy].buf[rl->cx]))
		key_cursor_right(rl);
}

void	key_cursor_pword(t_rl *rl)
{
	while (rl->cx && !ft_strchr(" 	", rl->row[rl->cy].buf[rl->cx]))
		key_cursor_left(rl);
	while (rl->cx && ft_strchr(" 	", rl->row[rl->cy].buf[rl->cx]))
		key_cursor_left(rl);
}
