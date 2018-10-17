/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_get_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:22:44 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/17 10:38:02 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token			*lex_get_token(char **pstr)
{
	t_token		*token;
	char		*str;
	int			i;
	int			j;
	int			len;

	token = (t_token *)malloc(sizeof(t_token));
	str = *pstr;
	i = 0;
	j = 0;
	len = ft_strlen(str);
	token->value = ft_strnew(len);
	while (i <= len)
	{
		if (str[i] == EOF || str[i] == '\0')
		{
			token->value[j] = '\0';
			break ;
		}
		else if (token->type == OPERATOR && !quoted && is_operator(str[i]))
			i++;
		else if (token->type == OPERATOR && !is_operator(str[i]))
		{
			token->value[j] = '\0';
			break ;
		}
		/* else if (str[i] == '\\' || str[i] == '\'' || str[i] == '\"') */
		/* else if (str[i] == '$' || str[i] == '`') */
		else if (is_operator(str[i]))
		{
			if (ft_strlen(token->value) != 0)
			{
				token->value[j] = '\0';
				break ;
			}
			else
			{
				token->type = OPERATOR;
				token->value[j] = str[i];
				i++;
				j++;
			}
		}
		else if (str[i] == '\n')
		{
			token->value[j] = '\0';
			break;
		}
		else if (str[i] == ' ' || str[i] == '	')
		{
			token->value[j] = '\0';
			i++;
			break ;
		}
		else if (token->type == TOKEN)
		{
			token->value[j] = str[i];
			i++;
			j++;
		}
		/* else if (str[i] == '#') */
		else
		{
			token->type = TOKEN;
			token->value[j] = str[i];
			i++;
			j++;
		}

	}
	if (ft_strlen(token) == 0)
	{
		token->type = EOF;
		token->value = ft_strdup(EOF);
	}
	*pstr = &str[i];
	return (token);
}
