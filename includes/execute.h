/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:29:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/20 13:08:47 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "shell.h"

# define NO_PIPE	-1
# define STDIN		0
# define STDOUT		1

void				execute_cmd(char **args);
void				execute_tree(t_tree **root);
void				execute(t_tree **root);

#endif
