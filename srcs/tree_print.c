/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:02:10 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/15 09:17:31 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char						*g_strtype[TOTAL_TYPE] = {
	[DEFAULT] = "default",
	[NEWLINE] = "newline",
	[IO_NUMBER] = "io_number",
	[TOKEN] = BLUE"token"RESET,
	[LESS] = PINK"less"RESET,
	[GREAT] = PINK"great"RESET,
	[DLESS] = PINK"dless"RESET,
	[DGREAT] = PINK"dgreat"RESET,
	[LESSAND] = PINK"lessand"RESET,
	[GREATAND] = PINK"greatand"RESET,
	[PIPELINE] = PINK"pipeline"RESET,
	[SEMICOLON] = RED"semicolon"RESET,
	[WORD] = BLUE"word"RESET
};

void	tree_print(t_tree **root)
{
	t_tree	*head;

	head = *root;
	if (head->left != NULL)
		tree_print(&head->left);
	ft_printf("%-20s > %s\n", g_strtype[head->token->type], head->token->literal);
	if (head->right != NULL)
		tree_print(&head->right);
}
