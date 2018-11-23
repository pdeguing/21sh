/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:11:56 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/23 09:58:51 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		get_dstart(char *arg)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != '$')
		i++;
	return (i);
}

static int		get_dend(char *arg, int dstart)
{
	int		i;

	i = dstart;
	while (arg[i] && (ft_isalnum(arg[i]) || arg[i] == '_'))
	{
		i++;
	}
	return (i);
}

static char		*append_varenv(char *old, char *varenv)
{
	if (varenv == NULL)
		return (old);
	return (ft_strffjoin(old, varenv));
}

static char		*expand(char *arg, char symbol)
{
	char	*new;
	char	*var_name;
	char	*suffix;
	int		start;
	int		end;

	start = 1;
	end = 1;
	if (symbol == '$')
	{
		start = get_dstart(arg) + 1;
		end = get_dend(arg, start);
		var_name = ft_strsub(arg, start, end - start);
	}
	else
		var_name = ft_strdup("HOME");
	new = ft_strsub(arg, 0, start - 1);
	suffix = ft_strsub(arg, end, ft_strlen(arg + end));
	new = append_varenv(new, env_getvar(var_name));
	new = ft_strfjoin(new, suffix);
	ft_strdel(&arg);
	ft_strdel(&var_name);
	return (new);
}

char			*rl_expansion(char *str)
{
	char	*symbol;
	int		offset;

	if (str[0] == '~' && (str[1] == '/' || str[1] == '\0'))
		str = expand(str, '~');
	offset = 0;
	while ((symbol = ft_strchr(str + offset, '$')))
	{
		if (ft_isalnum(*(symbol + 1)))
			str = expand(str + offset, '$');
		offset++;
	}
	return (str);
}
