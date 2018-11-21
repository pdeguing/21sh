/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:16:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/20 18:42:26 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** So we could actually use a stack of duplications to do for a specific
** stage in recursion, or rather an array of fd to duplicate with their
** destination at each level so that at the end we execute with:
** 			-> replace 0, per 3
**			-> replace 1, per 4
**			-> replace 2, per 1
**			-> replace 3, per 6
** or whatever.
*/

void	io_redirect(t_io *io_stack)
{
	t_io	*head;

	head = io_stack;
	while (head)
	{
		ft_printf(RED"{op = %d, src = %d, dst = %d}\n"RESET, head->op, head->src, head->dst);
		/*
		if (head->op == GREATAND || head->op == LESSAND)
		{
			if (head->src == '-')
			{
				close(head->dst);
				head = head->next;
				continue ;
			}
		}
		*/
		if (dup2(head->src, head->dst) == -1)
		{
			perror("21sh");
			exit(EXIT_FAILURE);
		}
		head = head->next;
	}
}
