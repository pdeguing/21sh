/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:03:52 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/25 12:08:46 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			token_get(char **head, t_token *token)
{
	char	*pchar;

	pchar = *head;
	while (*pchar != '\0')
	{
		if (*pchar == ' ' || *pchar == '	')
			pchar++;
		// NEWLINE?
		// IO_NUMBER
		if (ft_strchr(";|<>", *pchar))
			return (token_get_op(head, pchar, token));
		else
			return (token_get_word(head, pchar, token));
	}
	return (0);
}
