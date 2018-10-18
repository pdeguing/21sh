/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:17:42 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/18 08:23:49 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		lex_get_word(char **pstr, char *current_char, t_token *token)
{
	char	*first_char;
	int		i;


	token->type = TOKEN;
	first_char = current_char;
	i = 0;
	while (*current_char != '\0' && *current_char != ' ' && *current_char != '\n')
	{
		current_char++;
		i++;
	}
	token->literal = ft_strnew(i);
	ft_memcpy(token->literal, first_char, i);
	*pstr = current_char;
	return (1);
}

int		lex_get_nl(char **pstr, char *current_char, t_token *token)
{
	token->type = NEWLINE;
	*pstr = current_char + 1;
	return (1);
}

int		lex_get_operator(char **pstr, char *current_char, t_token *token)
{
	char	*first_char;
	int		i;

	first_char = current_char;
	i = 0;
	if (*current_char == ';')
	{
		token->type = SEMICOLON;
		current_char++;
	}
	else if (*current_char == '|')
	{
		token->type = PIPELINE;
		current_char++;
	}
	else if (*current_char == '<')
	{
		current_char++;
		if (*current_char == '<')
		{
			token->type = DLESS;
			current_char++;
		}
		else if (*current_char == '&')
		{
			token->type = LESSAND;
			current_char++;
		}
		else
			token->type = LESS;
	}
	else if (*current_char == '>')
	{
		current_char++;
		if (*current_char == '<')
		{
			token->type = DGREAT;
			current_char++;
		}
		else if (*current_char == '&')
		{
			token->type = GREATAND;
			current_char++;
		}
		else
			token->type = GREAT;
	}
	else
		return (-1);
	*pstr = current_char;
	return (1);
}
