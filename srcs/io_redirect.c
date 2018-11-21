/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:16:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/20 16:18:51 by pdeguing         ###   ########.fr       */
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

void	io_print(t_io **io_stack)
{
	t_io *head;

	head = *io_stack;
	ft_printf(RED"stack:\n"RESET);
	while (head)
	{
		ft_printf("{op = %d, copy = %d, into = %d}\n", head->op, head->src, head->dst);
		head = head->next;
	}
	ft_putchar('\n');
}

void	io_redirect(t_io **io_stack)
{
	t_io	*head;

	io_print(io_stack);
	head = *io_stack;
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

/*
 * So we have a stack with: {op, src, dst}.
 *
 * If op is aggregation:
 * 							IF src is minus = close dst, move to next and continue
 * 							ELSE WHILE redo a loop from the start of the stack with ref until we reach head again
 * 								IF head->src equal ref->dst THEN head->src = ref->src
 * 								(we do that to replace all previous apparitions of the fd that we are about to aggregate,
 * 								so that with redirected to another destination a fd that served as a source, we replace it
 * 								eg. if we redirect 2 to 1 but we previously redirected 3 to 2 then we need to be redirecting
 * 								3 to 1 instead.
 * 								the stack would be: 1 > 3 		=>		{op = GREAT, src = 1, dst = 3} 
 * 													2 >& 1		=>		{op = GREATAND, src = 2, dst = 1}
 *
 * 							
 */
