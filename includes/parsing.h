/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 08:54:55 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/19 12:13:43 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "shell.h"

/*
** Abstract Syntax Tree
*/

typedef struct s_tree		t_tree;

struct						s_tree
{
	t_token					*token;
	t_tree					*left;
	t_tree					*right;
};

t_tree						*tree_new(t_token *token);
void						tree_insert(t_tree **root, t_tree *new);

#endif
