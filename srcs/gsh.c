/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:46:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/31 15:26:18 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
