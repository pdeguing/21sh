/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:14:27 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/31 15:36:01 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_keymap g_keymap[KEY_MAX + 1] = {
								{KEY_CURSOR_LEFT, &key_cursor_left},
								{KEY_CURSOR_RIGHT, &key_cursor_right}
								/*
								{KEY_DEL_BACKSPACE, &key_backspace},
								{KEY_DEL_DELETE, &key_delete},
								{KEY_DEL_BEG, &key_del_beg},
								{KEY_DEL_END, &key_del_end},
								{KEY_HISTORY_UP, &key_history_up},
								{KEY_HISTORY_DOWN, &key_history_down},
								{KEY_HISTORY_SEARCH, &key_history_search},
								{KEY_LINE_UP, &key_line_up},
								{KEY_LINE_DOWN, &key_line_down},
								{KEY_LINE_BEG, &key_line_beg},
								{KEY_LINE_END, &key_line_end},
								{KEY_NEWLINE, &key_newline},
								{KEY_WORD_PREV, &key_word_prev},
								{KEY_WORD_NEXT, &key_word_next},
								{KEY_COPY, &key_copy},
								{KEY_PASTE, &key_paste}
								*/
};

void	key_handle(t_shell *sh, int key)
{
	int		i;

	if (ft_isascii(key))
	{
		ft_putchar(key);
		key_cursor_right(sh);
		return ;
	}
	i = 0;
	while (i < KEY_MAX)
	{
		if (key == g_keymap[i].key)
		{
			g_keymap[i].f(sh);
			break ;
		}
		i++;
	}
}

// Reading input as int does not work exactly as expected, we don't get ASCII
// value of the key. So we need to read as char and treat control sequence
// specifically, or map letter to their in value

void	get_command_line(t_shell *sh)
{
	char		key;

	raw_mode_enable();
	while (1)
	{
		read(0, &key, 4);
		ft_printf(RED"key pressed = %d\n"RESET, key);
		if (!sh->quote_status && key == '\n')
			break ;
		key_handle(sh, key);
	}
	raw_mode_disable();
}

// if we can get the input with get_next_line, we need to rename this function
