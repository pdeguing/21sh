/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 09:47:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/18 12:47:05 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/includes/libft.h"

# define STR_TEST "mkdir test ; cd test ; ls -a ; ls | 'cat | wc' -c > fifi ; <& >& && >> << >>&<> cat fifi"

# define BLACK "\x1b[1m"
# define BLUE "\x1b[0;34m"
# define RED "\x1b[1;31m"
# define PINK "\x1b[1;35m"
# define WHITE "\x1b[1;37m"
# define RESET "\x1b[0m"


/*
** LEXER
*/

# define B_BSLASH			0x01 /* 0b000'0001 */
# define B_SQUOTE			0x02 /* 0b000'0010 */
# define B_DQUOTE			0x04 /* 0b000'0100 */

typedef enum e_type			t_type;

enum						e_type
{
	DEFAULT,
	NEWLINE,
	IO_NUMBER,
	TOKEN,
	SEMICOLON,
	PIPELINE,
	LESS,
	GREAT,
	DLESS,
	DGREAT,
	LESSAND,
	GREATAND,
	WORD,
	TOTAL_TYPE
};

static char						*g_strtype[TOTAL_TYPE] = {
	[DEFAULT] = "default",
	[NEWLINE] = "newline",
	[IO_NUMBER] = "io_number",
	[TOKEN] = BLUE"token"RESET,
	[SEMICOLON] = RED"semicolon"RESET,
	[PIPELINE] = PINK"pipeline"RESET,
	[LESS] = PINK"less"RESET,
	[GREAT] = PINK"great"RESET,
	[DLESS] = PINK"dless"RESET,
	[DGREAT] = PINK"dgreat"RESET,
	[LESSAND] = PINK"lessand"RESET,
	[GREATAND] = PINK"greatand"RESET,
	[WORD] = BLUE"word"RESET
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
int							lex_get_operator(char **pstr, char *current_char,
		t_token *token);

/*
** PARSER
*/

void	parse_get_ast(const char *command_line);

#endif
