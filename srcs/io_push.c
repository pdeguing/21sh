/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:43:54 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/21 08:24:11 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_io	*io_push(int dst, int src, t_io *io_stack, int op)
{
	t_io	*new;
	t_io	*head;

	new = io_stack_new(dst, src, op);
	if (!io_stack)
		return (new);
	head = io_stack;
	while (head->op == PIPELINE)
	{
		if (!head->next || head->next->op != PIPELINE)
		{
			new->next = head->next;
			head->next = new;
			return (io_stack);
		}
		head = head->next;
	}
	new->next = head;
	return (new);
}
