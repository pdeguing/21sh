/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:25:11 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/23 11:09:01 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		squote(int quote, t_token *token)
{
	if (!(quote & (Q_BSLASH | Q_DQUOTE)))
		quote ^= Q_SQUOTE;
	token->literal = append_char(token->literal, '\'');
	quote &= ~Q_BSLASH;
	return (quote);
}

static int		dquote(int quote, t_token *token)
{
	if (!(quote & (Q_BSLASH | Q_SQUOTE)))
		quote ^= Q_DQUOTE;
	token->literal = append_char(token->literal, '\"');
	quote &= ~Q_BSLASH;
	return (quote);
}

static int		bslash(int quote, char *pchar, t_token *token)
{
	if ((!(quote & (Q_BSLASH | Q_SQUOTE))
				|| ((quote & Q_DQUOTE) && ft_strchr("\\\"\n", *pchar + 1))))
		quote |= Q_BSLASH;
	else
		quote &= ~Q_BSLASH;
	token->literal = append_char(token->literal, *pchar);
	return (quote);
}

/*
** The management of quotes is disgusting but I can't find a way to make it
** better quickly, bad is better than nothing.
*/

int				token_get_word(char **pstr, char *pchar, t_token *token)
{
	int		quote;

	quote = 0;
	token->type = TOKEN;
	while (*pchar != '\0')
	{
		if (!quote && (ft_strchr(";|<>", *pchar)
					|| ft_strchr(" 	", *pchar)))
			break ;
		else if (*pchar == '\'')
			quote = squote(quote, token);
		else if (*pchar == '\"')
			quote = dquote(quote, token);
		else if (*pchar == '\\')
			quote = bslash(quote, pchar, token);
		else if (!(quote & Q_BSLASH) || *pchar != '\n')
		{
			token->literal = append_char(token->literal, *pchar);
			quote &= ~Q_BSLASH;
		}
		pchar++;
	}
	token_expand(&token->literal);
	*pstr = pchar;
	return (1);
}
