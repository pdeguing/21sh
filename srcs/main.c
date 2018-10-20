/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:31:23 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/19 16:57:04 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)env;
	(void)av;
//	init_21sh();
//	while (1)
//	{
//		put_prompt();
//		get_command_line();
		ft_printf("command: %s\n\n", STR_3);
		parse(STR_3);
//		execute();
//	}
	return (0);
}
