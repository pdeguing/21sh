/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:29:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/20 18:03:52 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "shell.h"

# define NO_PIPE	-1
# define STDIN		0
# define STDOUT		1
# define READ		0
# define WRITE		1
# define WAIT		0x1

void				execute_cmd(char **args, char flag, int fd_read, int fd_write);
void				execute_tree(t_tree **root, char flag, int fd_read, int fd_write);
void				execute(t_tree **root);

#endif
