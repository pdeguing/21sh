/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:03:52 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 13:18:55 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			token_get(char **pstr, t_token *token)
{
	char	*pchar;

	pchar = *pstr;
	while (*pchar != '\0')
	{
		if (*pchar == ' ' || *pchar == '	')
			pchar++;
		else if (ft_strchr(";|<>", *pchar))
			return (token_get_op(pstr, pchar, token));
		else if (ft_isdigit(*pchar) && token_get_io(pstr, pchar, token))
			return (1);
		else
			return (token_get_word(pstr, pchar, token));
	}
	return (0);
}
