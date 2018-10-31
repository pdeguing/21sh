/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:25:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/30 17:15:45 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	key_word_prev(t_shell *sh)
{
	while (!sol && !space)
		key_left_arrow();
	key_left_arrow();
}

void	key_word_next(t_shell *sh)
{
	while (!eol && !space)
		key_right_arrow(sh);
	key_right_arrow(sh);
}
