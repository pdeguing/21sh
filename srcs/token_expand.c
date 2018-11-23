/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:19:43 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/23 15:09:14 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#define NOT_QUOTE	!(quote & (Q_SQUOTE | Q_BSLASH))

static int	get_lparam(char *str, int start)
{
	int		i;

	i = start;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i - start);
}

static char	*expand_str(char *str, char *param, int start, int lparam)
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

char		*expand_param(char *str)
{
	int		i;
	int		quote;
	int		l;

	i = 0;
	quote = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			quote = remove_squote(quote, str + i, &i);
		else if (str[i] == '\"')
			quote = remove_dquote(quote, str + i, &i);
		else if (str[i] == '\\')
			quote = remove_bslash(quote, str + i, &i);
		else if (NOT_QUOTE && str[i] == '$' && ft_isalnum(str[i + 1]))
		{
			l = get_lparam(str, i + 1);
			str = expand_str(str, ft_strsub(str, i + 1, l), i + 1, l);
			i = 0;
		}
		else
			i++;
	}
	return (str);
}

void		token_expand(char **pstr)
{
	char	*str;

	str = *pstr;
	if (!str)
		return ;
	if (*str == '~' && (*(str + 1) == '/' || !*(str + 1)))
		str = expand_str(str, ft_strdup("HOME"), 0, 1);
	*pstr = expand_param(str);
}
