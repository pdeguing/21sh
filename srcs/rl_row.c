/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_row.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:01:21 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/05 12:51:53 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_row	rl_row_new(char *buf)
{
	t_row	new;

	if (buf)
		new->buf_size = ft_strlen(buf);
	else
		new->buf_size = 0;
	new->buf = buf;
	return (new);
}

void	rl_row_insert(t_rl *rl, char *buf)
{
	t_row	*tmp;
	int		i;

	tmp = rl->row;
	rl->row_max++;
	rl->row = (t_row *)malloc(sizeof(t_row) * rl->row_max);
	if (rl->row)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < rl->row_max)
	{
		rl->row[i] = tmp[i];
		i++;
	}
	rl->row[i] = rl_row_new(buf);
	free(tmp);
}
