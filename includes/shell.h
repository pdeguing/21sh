/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 09:47:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/17 12:49:29 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define STR_TEST "mkdir test ; cd test ; ls -a ; ls | cat | wc -c > fifi ; cat fifi"

# include "../libft/includes/libft.h"

/*
** LEXER
*/

typedef enum e_type			t_type;

enum						e_type
{
	DEFAULT,
	NEWLINE,
	IO_NUMBER,
	TOKEN
};

typedef struct s_token		t_token;

struct						s_token
{
	int						type;
	char					*literal;
};

int							lex_get_token(char **head, t_token *token);
int							lex_get_word(char **pstr, char *current_char,
		t_token *token);
int							lex_get_nl(char **pstr, char *current_char,
		t_token *token);

/*
** PARSER
*/

void	parse_get_ast(const char *command_line);

#endif
