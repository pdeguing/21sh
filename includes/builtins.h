/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:42:09 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/22 12:57:52 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "shell.h"

int				ft_echo(char **args);
int				ft_cd(char **args);
int				ft_env(char **args);
int				ft_setenv(char **args);
int				ft_unsetenv(char **args);
int				ft_exit(char **args);

#endif
