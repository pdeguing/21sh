/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:25:11 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/13 15:05:18 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		token_get_word(char **pstr, char *pchar, t_token *token)
{
	int		quote;
	char	*first_char;
	int		i;

	quote = 0;
	token->type = TOKEN;
	first_char = pchar;
	i = 0;
	while (*pchar != '\0')
	{
		if (!quote && ft_strchr(";|<>", *pchar))
			break ;
		else if (!quote && ft_strchr(" 	", *pchar))
			break ;
		else if (*pchar == '\'')
			quote ^= B_SQUOTE;
		else if (*pchar == '\"')
			quote ^= B_DQUOTE;
		pchar++;
		i++;
	}
	token->literal = ft_strnew(i);
	ft_memcpy(token->literal, first_char, i);
	*pstr = pchar;
	return (1);
}
