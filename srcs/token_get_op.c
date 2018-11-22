/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:43:15 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/21 09:29:11 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		get_less(char **pstr, char *pchar, t_token *token)
{
	pchar++;
	if (*pchar == '<')
	{
		token->type = DLESS;
		pchar++;
	}
	else if (*pchar == '&')
	{
		token->type = LESSAND;
		pchar++;
	}
	else
		token->type = LESS;
	*pstr = pchar;
	return (1);
}

static int		get_great(char **pstr, char *pchar, t_token *token)
{
	pchar++;
	if (*pchar == '>')
	{
		token->type = DGREAT;
		pchar++;
	}
	else if (*pchar == '&')
	{
		token->type = GREATAND;
		pchar++;
	}
	else
		token->type = GREAT;
	*pstr = pchar;
	return (1);
}

int				token_get_op(char **pstr, char *pchar, t_token *token)
{
	if (*pchar == ';')
	{
		token->type = SEMICOLON;
		pchar++;
	}
	else if (*pchar == '|')
	{
		token->type = PIPELINE;
		pchar++;
	}
	else if (*pchar == '<')
		return (get_less(pstr, pchar, token));
	else if (*pchar == '>')
		return (get_great(pstr, pchar, token));
	else
		pchar++;
	*pstr = pchar;
	return (1);
}
