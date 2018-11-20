/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_stack_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:42:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 16:42:05 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_io	*io_stack_dup(t_io *io_stack)
{
	t_io	*head;
	t_io	*dup;

	head = io_stack;
	dup = NULL;
	if (head)
	{
		dup = io_stack_new(head->dst, head->src, head->op);
		dup->next = io_stack_dup(head->next);
	}
	return (dup);
}
