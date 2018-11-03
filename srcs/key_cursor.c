/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:24:39 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/03 10:50:10 by pdeguing         ###   ########.fr       */
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
	if (!(rl->cx <= rl->blen))
		return ;
	ft_putstr(tgetstr("nd", NULL));
	rl->cx++;
}
