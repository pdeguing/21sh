/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:40:14 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/01 18:02:12 by pdeguing         ###   ########.fr       */
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

static t_rl	*rl_init(void)
{
	t_rl	*new;

	new = (t_rl *)malloc(sizeof(t_rl));
	if (!new)
		return (NULL);
	new->key = 0;
	new->buf = NULL;
	new->len = 0;
	new->quote = 0;
	new->cx = 0;
	new->cy = 0;
	new->win_col = 0;
	new->win_row = 0;
	return (new);
}

static int	control_handle(t_rl *rl)
{
	int		i;

	i = 0;
	while (i < KEY_MAX)
	{
		if (rl->key == g_keymap[i].key)
		{
			g_keymap[i].f(rl);
			break ;
		}
		i++;
	}
	return (0);
}

char	*rl_readline(void)
{
	t_rl	*rl;
	char	*line;
	int		status;

	rl = rl_init();
	raw_mode_enable();
	status = 0;
	while (1)
	{
		ft_putstr(tgetstr("ce", NULL));
		if (rl->buf)
			ft_putstr(rl->buf);
		rl->key = 0;
		read(0, &rl->key, 4);
		if (!rl->quote && rl->key == '\n')
			break ;
		if (ft_isprint(rl->key))
			rl_char_insert(rl); // or strjoin just need to check how to handle deletion
		else
			status = control_handle(rl);
	}
	raw_mode_disable();
	line = rl->buf;
	free(rl);
	return (line);
}
