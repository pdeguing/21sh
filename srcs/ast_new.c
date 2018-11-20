/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:46:18 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 15:52:47 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_ast		*ast_new(t_token *token)
{
	t_ast	*new;

	new = (t_ast *)malloc(sizeof(t_ast));
	if (new == NULL)
		return (NULL);
	new->token = token;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
