/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:31:23 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/16 12:08:59 by pdeguing         ###   ########.fr       */
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
		parse_get_ast("ls -la ~/github\n");
//		execute();
//	}
	return (0);
}