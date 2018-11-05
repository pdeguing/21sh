/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:06:46 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/05 13:03:49 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	rl_char_insert(t_rl *rl)
{
	char *tmp;

	tmp = rl->buf;
	rl->blen++;
	rl->buf = ft_strnew(rl->blen + 1);
	if (tmp)
	{
		ft_strcpy(rl->buf, tmp);
		ft_memmove(rl->buf + rl->cx + 1, rl->buf + rl->cx, rl->blen - rl->cx);
	}
	rl->buf[rl->cx] = rl->key;
	ft_strdel(&tmp);
	key_cursor_right(rl);
}

void	rl_char_quote(t_rl *rl)
{
	if (rl->key == '\\')
		rl->quote ^= Q_BSLASH;
	else if (!(rl->quote & Q_BSLASH) && rl->key == '\'')
		rl->quote ^= Q_SQUOTE;
	else if (!(rl->quote & Q_BSLASH) && rl->key == '\"')
		rl->quote ^= Q_DQUOTE;
	else
		rl->quote &= ~(Q_BSLASH);
}
