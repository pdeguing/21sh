/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_ast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:22:54 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/17 12:50:36 by pdeguing         ###   ########.fr       */
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

void	parse_get_ast(const char *command_line)
{
	t_token	*next;
	char	*head;

	if (command_line == NULL)
		return ;
	head = ft_strdup(command_line);
	next = init_token();
	while (lex_get_token(&head, next) == 1)
	{
		ft_printf("TYPE: %d | VALUE: %s\n", next->type, next->literal);
		next->type = DEFAULT;
		next->literal = NULL;
	}
}
