/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:04:21 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 16:50:56 by pdeguing         ###   ########.fr       */
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

static void		catch_unexpected(t_token *prev, t_token *next)
{
	if (prev == NULL)
		return ;
	if (IS_OP(prev->type) && IS_OP(next->type))
		exit(EXIT_FAILURE);
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
			break ;
		}
		catch_unexpected(prev, next);
		ast_insert(&root, ast_new(next));
		prev = next;
	}
	return (root);
}
