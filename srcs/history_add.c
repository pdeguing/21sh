/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:18:45 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/23 17:44:02 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_dlist	*history_new(void)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->line = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	history_add(char *line, t_dlist **history)
{
	t_dlist	*new;

	if (!line)
		return ;
	new = history_new();
	if (!new)
		return ;
	new->line = ft_strdup(line);
	if (!(*history))
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		new->prev = (*history)->prev;
		new->next = (*history);
		(*history)->prev = new;
		new->prev->next = new;
	}
	(*history) = new;
}
