/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:16:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/21 11:07:37 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	io_redirect(t_io *io_stack)
{
	t_io	*head;

	head = io_stack;
	while (head)
	{
		if (head->op == GREATAND || head->op == LESSAND)
		{
			if (head->src == '-')
			{
				close(head->dst);
				head = head->next;
				continue ;
			}
		}
		if (dup2(head->src, head->dst) == -1)
		{
			perror("21sh");
			exit(EXIT_FAILURE);
		}
		head = head->next;
	}
}
