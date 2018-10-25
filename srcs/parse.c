/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:04:21 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/25 10:37:17 by pdeguing         ###   ########.fr       */
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
	if (prev->type >= LESS && next->type >= LESS)
		exit(EXIT_FAILURE);
}

t_tree	*parse(char *input)
{
	t_tree	*root;
	t_token	*next;
	t_token	*prev;

	if (input == NULL)
		return (NULL);
	root = NULL;
	prev = NULL;
	while (token_get(&input, next = init_token()) == 1)
	{
		/*
		ft_printf("TOKEN: %s > %s\n", g_strtype[next->type], next->literal);
		*/
		catch_unexpected(prev, next);
		tree_insert(&root, tree_new(next));
		prev = next;
	}
	return (root);
}
