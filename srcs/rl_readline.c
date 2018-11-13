/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:04:20 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/13 14:39:53 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_keymap g_keymap[KEY_MAX] = {
								{KEY_CURSOR_LEFT, &key_cursor_left},
								{KEY_CURSOR_RIGHT, &key_cursor_right},
								{KEY_DEL_BACKSPACE, &key_del_backspace},
								{KEY_DEL_DELETE, &key_del_delete},
								{KEY_DEL_BEG, &key_del_beg},
								{KEY_DEL_END, &key_del_end},
								{KEY_HISTORY_UP, &key_history_up},
								{KEY_HISTORY_DOWN, &key_history_down},
								{KEY_NEWLINE, &key_newline},
								{KEY_CURSOR_UP, &key_cursor_up},
								{KEY_CURSOR_DOWN, &key_cursor_down},
								{KEY_CURSOR_BEG, &key_cursor_beg},
								{KEY_CURSOR_END, &key_cursor_end},
								{KEY_CURSOR_PWORD, &key_cursor_pword},
								{KEY_CURSOR_NWORD, &key_cursor_nword},
								{KEY_COPY, &key_copy},
								{KEY_PASTE, &key_paste},
								{KEY_SIG_INT, &key_sig_int},
								{KEY_SIG_EOF, &key_sig_eof}
								/*
								{KEY_HISTORY_SEARCH, &key_history_search},
								*/
};

static t_rl	*rl_init(void)
{
	t_rl	*new;

	new = (t_rl *)malloc(sizeof(t_rl));
	if (!new)
		return (NULL);
	new->key = 0;
	new->row = NULL;
	new->row_max = 0;
	rl_row_insert(new, NULL);
	new->prompt_size = 0;
	new->quote = 0;
	new->cx = 0;
	new->cy = 0;
	new->win_col = 0;
	new->win_row = 0;
	new->history_head = NULL;
	new->history_state = 0;
	new->status = 0;
	return (new);
}

static int	control_handle(t_rl *rl)
{
	int		i;

//	ft_printf("key = %d\n", rl->key);
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
	static t_dlist	*history = NULL;

	rl = rl_init();
	rl->history_head = history;
	raw_mode_enable();
	rl->prompt_size = put_prompt();
	while (!rl->status)
	{
		rl_display_clear(rl);
		rl_display_print(rl);
		rl->key = 0;
		read(0, &rl->key, 4);
		if (!rl->quote && rl->key == '\n')
		{
			ft_putstr("\n");
			break ;
		}
		rl_char_quote(rl);
		if (ft_isprint(rl->key))
			rl_char_insert(rl);
		else
			control_handle(rl);
	}
	raw_mode_disable();
	line = rl_row_join(rl);
	free(rl);
	history_add(line, &history);
	return (line);
}
