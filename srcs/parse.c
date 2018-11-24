/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:04:21 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/23 16:54:21 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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

static int		catch_unexpected(t_ast *root, t_token *prev, t_token *next)
{
	if (prev == NULL)
		return (0);
	if (IS_ALLOP(prev->type) && (!next || IS_ALLOP(next->type)))
	{
		ft_putendl_fd("21sh: incorrect token", 2);
		ast_free(&root);
		return (1);
	}
	return (0);
}

t_ast			*parse(char *line)
{
	t_ast	*root;
	t_token	*next;
	t_token	*prev;

	if (line == NULL)
		return (NULL);
	root = NULL;
	prev = NULL;
	next = NULL;
	while (1)
	{
		if (!token_get(&line, next = init_token()))
		{
			ft_strdel(&next->literal);
			free(next);
			if (catch_unexpected(root, prev, NULL))
				return (NULL);
			break ;
		}
		ast_insert(&root, ast_new(next));
		if (catch_unexpected(root, prev, next))
			return (NULL);
		prev = next;
	}
	return (root);
}
