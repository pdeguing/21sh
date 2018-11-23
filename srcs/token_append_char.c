/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_append_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:08:18 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/23 11:08:55 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*append_char(char *str, char c)
{
	int		size;
	char	*new;

	size = 1;
	if (str)
		size += ft_strlen(str);
	new = ft_strnew(size + 1);
	if (!new)
		return (NULL);
	new[size] = '\0';
	if (str)
		ft_strcpy(new, str);
	ft_strdel(&str);
	new[size - 1] = c;
	return (new);
}
