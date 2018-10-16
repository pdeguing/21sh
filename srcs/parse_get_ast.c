/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_ast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:22:54 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/16 12:08:58 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	parse_get_ast(const char *command_line)
{
	t_token	*next;
	char	*head;
	char	*ref;

	if (command_line == NULL)
		return ;
	head = ft_strdup(command_line);
	ref = head;
	while ((next = lex_get_token(&head)) != NULL)
	{
		ft_printf("TYPE: %d / VALUE: %s\n", next->type, next->value);
	}
	ft_strdel(&ref);
}
