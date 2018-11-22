/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_op1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:48:12 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/21 08:41:45 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			exe_op_greatand(t_ast **root, char flag, t_io *io_stack)
{
	int		fd;
	int		dst;
	t_ast	*head;

	head = *root;
	if (!head->right || !head->right->token->literal)
		fd = 1;
	else if (ft_strcmp(head->right->token->literal, "-"))
		fd = ft_atoi(head->right->token->literal);
	else
		fd = '-';
	dst = 1;
	if (head->left->token->type == IO_NUMBER)
		dst = ft_atoi(head->left->token->literal);
	execute(&head->left, flag, io_push(dst, fd, io_stack, GREATAND));
}

void			exe_op_lessand(t_ast **root, char flag, t_io *io_stack)
{
	int		fd;
	t_ast	*head;

	head = *root;
	if (!head->right || !head->right->token->literal)
		fd = 0;
	else if (ft_strcmp(head->right->token->literal, "-"))
		fd = ft_atoi(head->right->token->literal);
	else
		fd = '-';
	execute(&head->left, flag, io_push(0, fd, io_stack, LESSAND));
}
