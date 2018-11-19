/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:43:15 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 08:53:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		token_get_op(char **pstr, char *pchar, t_token *token)
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
	}
	else if (*pchar == '>')
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
	}
	else
		pchar++;
	*pstr = pchar;
	return (1);
}
