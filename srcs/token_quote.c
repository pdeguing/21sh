/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:58:50 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/23 15:09:15 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		remove_squote(int quote, char *str, int *i)
{
	if (!(quote & (Q_BSLASH | Q_DQUOTE)))
	{
		ft_strcpy(str, str + 1); 
		quote ^= Q_SQUOTE;
	}
	else
	{
		quote &= ~Q_BSLASH;
		*i = *i + 1;
	}
	return (quote);
}

int		remove_dquote(int quote, char *str, int *i)
{
	if (!(quote & (Q_BSLASH | Q_SQUOTE)))
	{
		ft_strcpy(str, str + 1); 
		quote ^= Q_DQUOTE;
	}
	else
	{
		quote &= ~Q_BSLASH;
		*i = *i + 1;
	}
	return (quote);
}

int		remove_bslash(int quote, char *str, int *i)
{
	if ((!(quote & (Q_BSLASH | Q_SQUOTE))
				|| ((quote & Q_DQUOTE) && ft_strchr("\\\"\n", *str + 1))))
	{
		ft_strcpy(str, str + 1); 
		quote |= Q_BSLASH;
	}
	else
	{
		quote &= ~Q_BSLASH;
		*i = *i + 1;
	}
	return (quote);
}
