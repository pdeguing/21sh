/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:43:54 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/20 13:23:58 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_io	*io_push(int dst, int src, t_io *io_stack, int op)
{
	t_io	*new;
	t_io	*head;

	head = io_stack;
	new = io_stack_new(dst, src, op);
	if (!head)
		return (new);
	while (head->next)
	{
		head = head->next;
	}
	head->next = new;
	return (io_stack);
}
