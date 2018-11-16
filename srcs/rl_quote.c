/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:39:01 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/16 08:53:43 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#define IS_SINGLE_QUOTE(x) x == 39
#define IS_DOUBLE_QUOTE(x) x == 34
#define IS_SIDE_QUOTE(x) x == 96
#define IS_SLESH_QUOTE(x) x == 92
#define SGLQUOTE 	0
#define DBLQUOTE 	1
#define SDQUOTE 2
#define SLESH  	3

/*
** Returns 1 if all quotes are closed (the next newline will not be quoted).
** 0 otherwise.
*/
static unsigned char	ft_clearbit(char name, int position)
{
	unsigned int	mask;

	mask = 0;
	mask = 1 << position;
	return (name & ~mask);
}

static unsigned char	ft_setbit(char name, int position)
{
	unsigned int	mask;
	int				ret;

	mask = 0;
	mask = 1 << position;
	ret = (mask | name);
	return (ret);
}

static unsigned char	ft_togglebit(char name, int position)
{
	int mask ;

	mask = 1 << position;
  name ^= mask;
	return (name);
}


static void parse_row_buffer(char *buffer,unsigned char *ptr_to_bit_store)
{
	unsigned char status;

	status = *ptr_to_bit_store;
	while (*buffer != '\0')
	{
		if (IS_SINGLE_QUOTE (*buffer))
			status = ft_togglebit(status, SGLQUOTE);
		else if (IS_DOUBLE_QUOTE (*buffer))
			status = ft_togglebit(status, DBLQUOTE);
		else if (IS_SIDE_QUOTE (*buffer))
			status = ft_togglebit(status, SDQUOTE);
		else if (IS_SLESH_QUOTE (*buffer))
			status = ft_togglebit(status, SLESH);
		buffer++;
	}
	*ptr_to_bit_store = status;
	return ;
}



int		rl_quote(t_rl *rl)
{
	t_row *buffer;
	unsigned char status;
	int i;
	int max;

	status = 0;
	i = -1;
	max = rl->row_max;
	buffer = rl->row;
	while (++i < max)
			parse_row_buffer(buffer[i].buf, &status);
	return (!status);
}
