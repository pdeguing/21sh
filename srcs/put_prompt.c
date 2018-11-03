/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 06:31:23 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/03 11:50:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	put_prompt(void)
{
	char	*pwd;
	char	*home;
	int		len;

	len = ft_printf(BLACK "21sh: " RESET);
	len -= (ft_strlen(BLACK) + ft_strlen(RESET));
	if ((pwd = get_varenv("PWD")) != NULL)
	{
		if ((home = get_varenv("HOME")) && ft_strstr(pwd, home))
			len += ft_printf("~%s ", pwd + ft_strlen(home));
		else
			len += ft_printf("%s ", pwd);
	}
	len += ft_printf(BLACK ">>> " RESET);
	len -= (ft_strlen(BLACK) + ft_strlen(RESET));
	return (len);
}
