/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:26:39 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/30 17:14:31 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	key_line_up(t_shell *sh)
{
	if (!first_line)
		tputs(move_up);
}

void	key_line_down(t_shell *sh)
{
	if (!last_line)
		tputs(move_down);
}

void	key_line_beg(t_shell *sh)
{
	tputs(carriage_return);
}

void	key_line_end(t_shell *sh)
{
	while (!eol)
		right_arrow();
}
