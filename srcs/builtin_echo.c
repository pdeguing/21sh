/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:38:40 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 11:38:47 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		builtin_echo(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		ft_printf("%s", args[i]);
		i++;
		if (args[i])
			ft_printf(" ");
	}
	ft_printf("\n");
	return (0);
}
