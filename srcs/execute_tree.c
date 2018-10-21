/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 08:42:57 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/20 18:03:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char		**get_args(t_token *cmd)
{
	char	**args;

	args = malloc(sizeof(char *) * 2);
	args[0] = cmd->literal;
	args[1] = NULL;
	return (args);
}

/*
** I wanted to implement a stack here, keeping track of the fds used for each
** command. It would have been interesting, but sadly it seems smarter to go
** with a standard recursive method. We are parsing shell language, so the size
** of the input and thus the resulting tree should always be manageable
** within the stack. And using a manual stack would create an exceptional
** case where we should always let stdin (or the fd replacing it after a
** redirection) on top. This would lead to the necessicity to
** implement two parallel stacks or to do some value swapping within
** a stack storing an array of 2 fd, read end write end.
*/

void		execute_tree(t_tree **root, char flag, int fd_read, int fd_write)
{
	t_tree	*head;
	int		p[2];

	head = *root;
	if (!head)
		return ;
	// Execute cmd
	if (!head->left && !head->right)
		execute_cmd(get_args(head->token), flag, fd_read, fd_write);
	if (head->token->type == SEMICOLON)
	{
		execute_tree(&head->left, flag, fd_read, fd_write);
		execute_tree(&head->right, flag, fd_read, fd_write);
	}
	if (head->token->type == PIPELINE)
	{
		pipe(p);
		execute_tree(&head->left, flag ^ WAIT, fd_read, p[WRITE]);
		execute_tree(&head->left, flag, p[READ], fd_write);
	}
}
