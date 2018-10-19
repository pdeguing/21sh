/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_ast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:22:54 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/19 12:51:25 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_token	*init_token(void)
{
	t_token		*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new == NULL)
		return (NULL);
	new->type = DEFAULT;
	new->literal = NULL;
	return (new);
}

void	parse_get_ast(const char *command_line)
{
	t_token	*next;
	char	*head;
	t_tree	*root;

	if (command_line == NULL)
		return ;
	head = ft_strdup(command_line);
	root = NULL;
	while (lex_get_token(&head, next = init_token()) == 1)
	{
		tree_insert(&root, tree_new(next));
		ft_printf("%-20s > %s\n", g_strtype[next->type], next->literal);
	}
}
