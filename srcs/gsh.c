/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:46:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/25 10:38:09 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		gsh_loop(void)
{
	char		*line;
	t_tree		*ast;
	t_dlist		*history;

	signal(SIGINT, handle_sig);
	history = NULL;
	while (1)
	{
		put_prompt();
		get_next_line(0, &line);
//		get_command_line();
		history_add(line, &history);
		ast = parse(line);
//		tree_print(&ast);
		execute(&ast);
	}
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	init_gsh(env);
	gsh_loop();
	return (0);
}
