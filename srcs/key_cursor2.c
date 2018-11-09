/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cursor2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:07:04 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/08 16:09:26 by pdeguing         ###   ########.fr       */
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
