/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:46:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/03 17:19:55 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Modify signal handling so that it restarts the loop instead of printing
** the prompt, maybe just put the while loop of line edition as a temp
** loop within gsh_loop
*/

static void		gsh_loop(void)
{
	char		*line;
	t_tree		*ast;

//	signal(SIGINT, handle_sig);
	while (1)
	{
		line = rl_readline();
		ast = parse(line);
//		tree_print(&ast);
		execute(&ast);
	}
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	init_shell(env);
	gsh_loop();
	return (0);
}
