/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 07:29:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/23 08:00:42 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# define NO_PIPE		-1
# define STDIN			0
# define STDOUT			1
# define READ			0
# define WRITE			1
# define WAIT			0x1

typedef struct s_tree		t_tree;

void				redirect_io(int fd_read, int fd_write);

void				execute_bin(char **args, char flag, int fd_read, int fd_write);
void				execute_cmd(char **args, char flag, int fd_read, int fd_write);
void				execute_tree(t_tree **root, char flag, int fd_read, int fd_write);
void				execute(t_tree **root);

#endif
