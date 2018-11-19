/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:39:05 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 11:39:10 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		builtin_exit(char **args)
{
	(void)args;
	raw_mode_disable();
	exit(EXIT_SUCCESS); // clean exit
}
