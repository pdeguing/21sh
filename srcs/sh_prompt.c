/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:08:30 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 16:45:45 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_prompt_get(char **ref)
{
	char	*pwd;
	char	*home;
	char	*str;
	int		psize;

	psize = 0;
	str = ft_strdup(BLACK"21sh: "RESET);
	psize -= ft_strlen(BLACK) + ft_strlen(RESET);
	if ((pwd = env_getvar("PWD")) != NULL)
	{
		if ((home = env_getvar("HOME")) && ft_strstr(pwd, home))
			str = ft_strffjoin(ft_strffjoin(str, "~"), pwd + ft_strlen(home));
		else
			str = ft_strffjoin(str, pwd);
	}
	str = ft_strffjoin(str, BLACK" >>> "RESET);
	psize -= ft_strlen(BLACK) + ft_strlen(RESET);
	psize += ft_strlen(str);
	*ref = str;
	return (psize);
}
