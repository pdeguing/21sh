/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_newline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:38:22 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/17 09:25:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	key_newline(t_rl *rl)
{
	rl->quote_status &= ~Q_BSLASH;
	rl_row_insert(rl, NULL);
	rl->cx = 0;
	rl->cy++;
	ft_putstr(tgetstr("do", NULL));
	ft_putstr(tgetstr("cr", NULL));
	ft_putstr("> ");
}
