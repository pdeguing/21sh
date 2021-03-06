/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:19:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/26 11:19:54 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		sh_loop(void)
{
	char		*line;
	char		*prompt;
	int			psize;
	t_ast		*ast;

	signal(SIGINT, handle_sig);
	line = NULL;
	prompt = NULL;
	ast = NULL;
	while (1)
	{
		psize = sh_prompt_get(&prompt);
		line = ft_readline(prompt, psize, RL_DEFAULT);
		line = history_substitution(line);
		ast = parse(line);
		if (ast)
		{
			execute(&ast, WAIT, NULL);
			ast_free(&ast);
		}
		ft_strdel(&prompt);
		ft_strdel(&line);
	}
}

int				main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	sh_init(env);
	sh_loop();
	return (0);
}
