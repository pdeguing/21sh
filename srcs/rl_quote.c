/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:39:01 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/16 12:54:59 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#define CHECK(status, mask) (status & mask)

/*
** Returns 0 if all quotes are closed (the next newline will not be quoted).
** 1 otherwise.
*/

int		rl_quote(t_rl *rl)
{
	int		i;
	int		j;
	int		status;
	char	*str;

	status = 0;
	i = 0;
	while (i < rl->row_max)
	{
		str = rl->row[i].buf;
		j = 0;
		while (str && str[j])
		{
			if (str[j] == '\'' && !CHECK(status, (Q_BSLASH | Q_DQUOTE)))
				status ^= Q_SQUOTE;
			if (str[j] == '"' && !CHECK(status, (Q_BSLASH | Q_SQUOTE)))
				status ^= Q_DQUOTE;
			if (str[j] == '\\' && (!CHECK(status, (Q_BSLASH | Q_SQUOTE)) || (CHECK(status, Q_DQUOTE) && ft_strchr("\"\\\n", rl->key))))
				status |= Q_BSLASH;
			else
				status &= ~Q_BSLASH;
			j++;
		}
		i++;
	}
	return (status);
}
