/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:01:05 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/13 14:10:46 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	key_sig_int(t_rl *rl)
{
	rl->status = 1;
}

void	key_sig_eof(t_rl *rl)
{
	if (rl->row_max == 0 || (rl->row_max == 1 && rl->row[1].bsize == 0))
	{
		raw_mode_disable();
		exit(EXIT_SUCCESS); // clean exit
	}
}
