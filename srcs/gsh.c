/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:46:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/16 12:08:41 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		gsh_loop(void)
{
	char		*line;
	char		*prompt;
	int			psize;
	t_tree		*ast;

	signal(SIGINT, handle_sig);
	while (1)
	{
		psize = sh_prompt_get(&prompt);
		line = rl_readline(prompt, psize, DEFAULT);
		if (!line)
			continue ;
//		ft_printf(RED"> %s "RESET, line);
		ast = parse(line);
		if (!ast)
			continue ;
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
