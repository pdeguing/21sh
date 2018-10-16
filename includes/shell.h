/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 09:47:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/16 12:09:02 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/includes/libft.h"

/*
** LEXER
*/

typedef enum e_type			t_type;

enum						e_type
{
	NEWLINE,
	IO_NUMBER,
	TOKEN
};

typedef struct s_token		t_token;

struct						s_token
{
	int						type;
	char					*value;
};

t_token						*lex_get_token(char **pstr);

/*
** PARSER
*/

void	parse_get_ast(const char *command_line);

#endif
