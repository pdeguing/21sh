/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_get_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 06:24:51 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/18 08:13:24 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "shell.h"

static int		lex_lookup_operator(t_token *token)
{
	int		i;
	static const char	*map_type[TOTAL_TYPE] = {
		[SEMICOLON] = ";",
		[PIPELINE] = "|",
		[LESS] = "<",
		[GREAT] = ">",
		[DLESS] = "<<",
		[DGREAT] = ">>",
		[LESSAND] = "<&",
		[GREATAND] = ">&"
	};

	i = SEMICOLON;
	while (i < GREATAND)
	{
		if (ft_strcmp(token->literal, map_type[i]))
		{
			token->type = i;
			return (1);
		}
		i++;
	}
	return (0);
}

*/
