/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 08:54:55 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/19 17:04:41 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "shell.h"

/*
** Lexer
*/

# define B_BSLASH			0x01 /* 0b000'0001 */
# define B_SQUOTE			0x02 /* 0b000'0010 */
# define B_DQUOTE			0x04 /* 0b000'0100 */


enum						e_type
{
	DEFAULT,
	NEWLINE,
	IO_NUMBER,
	TOKEN,
	WORD,
	LESS,
	GREAT,
	DLESS,
	DGREAT,
	LESSAND,
	GREATAND,
	PIPELINE,
	SEMICOLON,
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

struct						s_token
{
	int						type;
	char					*literal;
};

int							token_get(char **head, t_token *token);
int							lex_get_word(char **pstr, char *current_char,
		t_token *token);
int							lex_get_nl(char **pstr, char *current_char,
		t_token *token);
int							lex_get_operator(char **pstr, char *current_char,
		t_token *token);

/*
** Abstract Syntax Tree
*/


struct						s_tree
{
	t_token					*token;
	t_tree					*left;
	t_tree					*right;
};

t_tree						*tree_new(t_token *token);
void						tree_insert(t_tree **root, t_tree *new);


/*
** Parser
*/

void	parse(char *input);

#endif
