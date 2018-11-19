/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:08:30 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 10:30:44 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_prompt_get(char **ref)
{
	char	*pwd;
	char	*home;
	char	*prompt;
	int		psize;

	psize = 0;
	prompt = ft_strdup(BLACK"21sh: "RESET);
	psize -= ft_strlen(BLACK) + ft_strlen(RESET);
	if ((pwd = env_getvar("PWD")) != NULL)
	{
		if ((home = env_getvar("HOME")) && ft_strstr(pwd, home))
			prompt = ft_strffjoin(ft_strffjoin(prompt, "~"), pwd + ft_strlen(home));
		else
			prompt = ft_strffjoin(prompt, pwd);
	}
	prompt = ft_strffjoin(prompt, BLACK" >>> "RESET);
	psize -= ft_strlen(BLACK) + ft_strlen(RESET);
	psize += ft_strlen(prompt);
	*ref = prompt;
	return (psize);
}
