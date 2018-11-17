/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:04:21 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/17 09:47:08 by pdeguing         ###   ########.fr       */
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
		catch_unexpected(prev, next);
		tree_insert(&root, tree_new(next));
		prev = next;
	}
	return (root);
}
