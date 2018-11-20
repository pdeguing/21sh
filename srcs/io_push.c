/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:43:54 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 16:47:17 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_io	*io_push(int dst, int src, t_io *io_stack, int op)
{
	t_io	*new;
	t_io	*head;

	head = io_stack;
	if (op != GREATAND || op != LESSAND)
	{
		while (head)
		{
			if (head->op != PIPELINE && head->dst == dst)
			{
				head->src = src;
				head->op = op;
				return (io_stack);
			}
			head = head->next;
		}
	}
	new = io_stack_new(dst, src, op);
	if (io_stack)
		new->next = io_stack;
	else
		new->next = NULL;
	return (new);
}
