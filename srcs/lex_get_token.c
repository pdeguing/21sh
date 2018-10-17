/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_get_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:22:44 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/16 14:37:44 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token			*lex_get_token(char **pstr)
{
	t_token		*token;
	char		*str;
	int			i;

	token = (t_token *)malloc(sizeof(t_token));
	str = *pstr;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\n')
		{
			*pstr = &str[i + 1];
			token->type = TOKEN;
			token->value = ft_strnew(i);
			ft_strncpy(token->value, str, i);
			return (token);
		}
		i++;
	}
	if (i < 0)
	{
		token->type = TOKEN;
		token->value = ft_strnew(i);
		ft_strncpy(token->value, str, i);
		return (token);
	}
	return (NULL);
}


// JUST DO DISPACTH TABLE FOR ALL POSSIBLE CHARACTERS
