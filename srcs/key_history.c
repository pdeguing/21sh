/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:17:20 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/03 18:33:18 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	key_history_up(t_rl *rl)
{
	if (!rl->history_head)
		return ;
	ft_strdel(&rl->buf);
	rl->buf = ft_strdup(rl->history_head->line);
	rl->blen = ft_strlen(rl->buf);
	if (rl->history_head->next)
		rl->history_head = rl->history_head->next;
	rl->cx = rl->blen;
}

void	key_history_down(t_rl *rl)
{
	if (!rl->history_head)
		return ;
	ft_strdel(&rl->buf);
	if (!rl->history_head->prev)
	{
		rl->buf = NULL;
		rl->blen = 0;
	}
	else
	{
		rl->history_head = rl->history_head->prev;
		rl->buf = ft_strdup(rl->history_head->line);
		rl->blen = ft_strlen(rl->buf);
	}
	rl->cx = rl->blen;
}

/*
void	key_history_search(t_shell *sh)
{
	clear_line();
	read_char();
	add_char_to_buf();
	search_history(buf);
}
*/
