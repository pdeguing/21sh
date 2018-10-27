/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:14:27 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/27 15:55:05 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	get_command_line(t_shell *sh)
{
	enter_row_mode();
	while (!newline)
	{
		read_char();
		if (is_ascii(key))
		{
			print_char();
			continue ;
		}
		while (i < MAX_KEYS)
		{
			if (key == g_ctl_function[i]->key)
			{
				g_ctl_function[i]->f();
				break ;
			}
			i++;
		}
	}
	send_line();
	quit_row_mode();
}

void	quoted_newline()
{
	tputs(move_down);
	tputs(carriage_return);
	print('>');
}

void	print_char()
{
	print(key);
	tputs(move_right);
}

void	left_arrow()
{
	if (!sol)
		tputs(move_left);
}

void	right_arrow()
{
	if (!eol)
		tputs(move_right);
}

void	backspace()
{
	if (!sol)
	{
		tputs(move_left);
		tputs(delete); //?
	}
}

void	del()
{
	if (!eol)
		tputs(delete);
}

void	ctl_up_arrow()
{
	if (!first_line)
		tputs(move_up);
}

void	ctl_down_arrow()
{
	if (!last_line)
		tputs(move_down);
}

void	ctl_left_arrow()
{
	while (!sol && !space)
		left_arrow();
	left_arrow();
}

void	ctl_rigth_arrow()
{
	while (!eol && !space)
		right_arrow();
	right_arrow();
}

void	up_arrow();
{
	if (history && head)
	{
		clear_line();
		print_cmd();
		move_head_next();
	}
}

void	down_arrow()
{
	if (head && head->prev)
	{
		move_head_prev();
		clear_line();
		print_cmd();
	}
}

void	home();
{
	tputs(carriage_return);
}

void	end()
{
	while (!eol)
		right_arrow();
}

void	ctl_u()
{
	while (!sol)
		backspace();
}

void	ctl_k()
{
	while (!eol)
		del();
}

void	ctl_alt_c()
{
	tputs(carriage_return);
	while (!eol)
		buffer = buffer + current;
}
void	ctl_alt_v()
{
	while (buffer)
		print_char();
}

void	ctl_r()
{
	clear_line();
	read_char();
	add_char_to_buf();
	search_history(buf);
}
