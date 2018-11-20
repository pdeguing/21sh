/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:56:50 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/19 16:12:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_io	*io_stack_new(int dst, int src, int op)
{
	t_io	*new;

	new = (t_io *)malloc(sizeof(t_io));
	if (!new)
		return (NULL);
	new->dst = dst;
	new->src = src;
	new->op = op;
	return (new);
}
