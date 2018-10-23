/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:00:08 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/23 10:12:40 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_tree		*tree_new(t_token *token)
{
	t_tree	*new;

	new = (t_tree *)malloc(sizeof(t_tree));
	if (new == NULL)
		return (NULL);
	new->token = token;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
