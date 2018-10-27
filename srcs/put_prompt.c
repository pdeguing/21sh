/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 06:31:23 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/27 07:01:11 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	put_prompt(void)
{
	char	*pwd;
	char	*home;

	ft_printf(BLACK "21sh: " RESET);
	if ((pwd = get_varenv("PWD")) != NULL)
	{
		if ((home = get_varenv("HOME")) && ft_strstr(pwd, home))
			ft_printf("~%s ", pwd + ft_strlen(home));
		else
			ft_printf("%s ", pwd);
	}
	ft_printf(BLACK ">>> " RESET);
}
