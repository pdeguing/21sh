/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:13:39 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/22 12:14:59 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		put_prompt();
		signal(SIGINT, handle_sig);
	}
}

void	handle_childsig(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		signal(SIGINT, handle_childsig);
	}
}
