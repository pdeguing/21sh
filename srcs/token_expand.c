/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:19:43 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/23 10:19:19 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		get_lparam(char *str, int start)
{
	int		i;

	i = start;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i - start);
}

char	*expand_str(char *str, char *param, int start, int lparam)
{
	char	*new;
	char	*expansion;
	char	*prefix;
	char	*suffix;

	expansion = env_getvar(param);
	if (!expansion)
		expansion = ft_strnew(0);
	else
		expansion = ft_strdup(expansion);
	ft_strdel(&param);
	if (start > 0)
	{
		prefix = ft_strsub(str, 0, start - 1);
		new = ft_strfjoin(prefix, expansion);
	}
	else
		new = expansion;
	suffix = ft_strsub(str, lparam + start, ft_strlen(str + lparam + start));
	new = ft_strfjoin(new, suffix);
	ft_strdel(&str);
	return (new);
}	

void	token_expand(char **pstr)
{
	char	*str;
	int		i;
	int		quote;
	int		lparam;

	str = *pstr;
	if (!str)
		return ;
	i = 0;
	if (*str == '~' && (str[i + 1] == '/' || !str[i + 1]))
		str = expand_str(str, ft_strdup("HOME"), 0, 1);
	quote = 0;
	lparam = 0;
	while (str[i])
	{
		if (!(quote & (Q_SQUOTE | Q_BSLASH)) && str[i] == '$' && ft_isalnum(str[i + 1]))
		{
			i++;
			lparam = get_lparam(str, i);
			str = expand_str(str, ft_strsub(str, i, lparam), i, lparam);
			i = 0;
		}
		else
			i++;
	}
	*pstr = str;
}
