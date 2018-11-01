/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:46:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/01 12:41:37 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Modify signal handling so that it restarts the loop instead of printing
** the prompt, maybe just put the while loop of line edition as a temp
** loop within gsh_loop
*/

static void		gsh_loop(t_shell *sh)
{
	char		*line;
	t_tree		*ast;
	t_dlist		*history;

	signal(SIGINT, handle_sig);
	history = NULL;
	while (1)
	{
		put_prompt();
		get_command_line(sh);
		get_next_line(0, &line);
		history_add(line, &history);
		ast = parse(line);
//		tree_print(&ast);
		execute(&ast);
	}
}

int		main(int ac, char **av, char **env)
{
	t_shell		*sh;

	(void)ac;
	(void)av;

	sh = init_shell(env);
	gsh_loop(sh);
	return (0);
}
