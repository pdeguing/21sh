/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_line_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:19:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/05 12:52:22 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	rl_line_print(rl)
{
	int		i;

	if (!rl->row)
		return ;
	i = 0;
	while (i < rl->row_max)
	{
		if (rl->row[i].buf)
			ft_putstr(rl->row[i].buf);
		i++;
	}
	ft_putstr(tgoto(tgetstr("ch", NULL), 0, rl->prompt_size + rl->cx));
}
