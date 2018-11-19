/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:19:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 11:44:20 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		sh_loop(void)
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
		execute(&ast, WAIT, NULL);
	}
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	sh_init(env);
	sh_loop();
	return (0);
}
