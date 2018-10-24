/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:03:52 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/23 17:17:19 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			token_get(char **head, t_token *token)
{
	char	*current_char;

	current_char = *head;
	while (*current_char != '\0')
	{
		if (*current_char == ' ' || *current_char == '	')
			current_char++;
		if (*current_char == '\n')
			return (lex_get_nl(head, current_char, token));
		// IO_NUMBER
		if (ft_strchr(";|<>", *current_char))
			return (lex_get_operator(head, current_char, token));
		else
			return (lex_get_word(head, current_char, token));
	}
	return (0);
}

















/* ------------------------------ Initial draft ------------------------------
 
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
		// else if (str[i] == '\\' || str[i] == '\'' || str[i] == '\"')
		// else if (str[i] == '$' || str[i] == '`')
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
		// else if (str[i] == '#')
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
*/
