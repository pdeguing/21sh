/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get_io.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:23:05 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/26 11:31:42 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		token_get_io(char **pstr, char *pchar, t_token *token)
{
	char	*ref;
	int		i;

	ref = pchar;
	i = 0;
	while (*pchar != '\0' && ft_isdigit(*pchar))
	{
		pchar++;
		i++;
	}
	if (!*pchar || !ft_strchr("<>", *pchar))
		return (0);
	token->type = IO_NUMBER;
	token->literal = ft_strnew(i);
	ft_memcpy(token->literal, ref, i);
	*pstr = pchar;
	return (1);
}
