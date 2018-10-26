/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:43:54 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/26 13:00:55 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** We need not to modify the stack between branches in pipes, so we don't
** use a standard push and don't actually update the head.
**
** Also if there is already a redirection for the destination, we will 
** update the source instead of pushing a new action.
*/

t_io	*io_push(int dst, int src, t_io *io_stack)
{
	t_io	*new;
	t_io	*head;

	head = io_stack;
	/*
	while (head)
	{
		if (head->dst == dst)
		{
			head->src = src;
			return (io_stack);
		}
		head = head->next;
	}
	*/
	new = (t_io *)malloc(sizeof(t_io));
	if (!new)
		return (NULL);
	if (io_stack)
		new->next = io_stack;
	else
		new->next = NULL;
	new->dst = dst;
	new->src = src;
	return (new);
}
