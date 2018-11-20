/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:08:59 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 16:18:58 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	io_free(t_io **io_stack)
{
	t_io	*head;
	t_io	*tmp;

	head = *io_stack;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
