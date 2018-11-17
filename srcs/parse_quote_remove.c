/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 10:23:33 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/17 10:44:46 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*parse_quote_remove(char *str)
{
	char	*new;
	char	*old;
	int		i;

	if (!str)
		return (NULL);
	old = str;
	new = ft_strnew(ft_strlen(str));
	i = 0;
	while (*old)
	{
		if (!ft_strchr("\\\'\"", *old))
		{
			new[i] = *old;
			i++;
		}
		old++;
	}
	new[i] = '\0';
	ft_strdel(&str);
	return (new);
}
