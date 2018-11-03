/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 09:47:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/03 10:37:09 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <termios.h>
# include <termcap.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

/* Colors ******************************************************************* */

# define BLACK				"\x1b[1m"
# define BLUE				"\x1b[0;34m"
# define RED				"\x1b[1;31m"
# define PINK				"\x1b[1;35m"
# define WHITE				"\x1b[1;37m"
# define RESET				"\x1b[0m"

/* Typedefs ***************************************************************** */

typedef struct s_token		t_token;
typedef enum e_type			t_type;
typedef struct s_tree		t_tree;
typedef struct s_dlist		t_dlist;
typedef struct s_io			t_io;
typedef struct s_keymap		t_keymap;
typedef struct termios		t_termios;
typedef struct s_rl			t_rl;

/* Environment ************************************************************** */

char						**g_env;

void						init_env(char **env);
char						*get_varenv(char *varname);
int							get_envlen(char **env);

/* General ****************************************************************** */

int							put_prompt(void);

void						init_shell(char **env);

/* Signals ****************************************************************** */

void						handle_sig(int sig);
void						handle_childsig(int sig);

/* Builtins ***************************************************************** */

# define BUILTIN_NBR		6

int							ft_echo(char **args);
int							ft_cd(char **args);
int							ft_env(char **args);
int							ft_setenv(char **args);
int							ft_unsetenv(char **args);
int							ft_exit(char **args);

int							replace_env(char *arg);


/* Debugging **************************************************************** */
 
# define STR_TEST			"mkdir test ; cd test ; ls -a ; ls | 'cat | wc' -c > fifi"
# define STR_1				"ls libft"
# define STR_2				"ls ; echo hello"
# define STR_3				"cat -e; ls | cat -e > file; cat -e > file < input"

void						tree_print(t_tree **root);

/* Execute ****************************************************************** */

# define NO_PIPE		-1
# define STDIN			0
# define STDOUT			1
# define READ			0
# define WRITE			1
# define WAIT			0x1

void				execute_bin(char **args, char flag, t_io **io_stack);
void				execute_cmd(char **args, char flag, t_io **io_stack);
void				execute_tree(t_tree **root, char flag, t_io *io_stack);
void				execute(t_tree **root);

/* Parsing ****************************************************************** */

# define B_BSLASH			0x01 /* 0b0000'0001 */
# define B_SQUOTE			0x02 /* 0b0000'0010 */
# define B_DQUOTE			0x04 /* 0b0000'0100 */

# define IS_OP(type)		(LESS <= type && type <= GREATAND)
# define IS_CTLOP(type)		(PIPELINE <= type && type <= SEMICOLON)

enum						e_type
{
	DEFAULT,
	NEWLINE,
	TOKEN,
	WORD,
	IO_NUMBER,
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
	[LESS] = PINK"less"RESET,
	[GREAT] = PINK"great"RESET,
	[DLESS] = PINK"dless"RESET,
	[DGREAT] = PINK"dgreat"RESET,
	[LESSAND] = PINK"lessand"RESET,
	[GREATAND] = PINK"greatand"RESET,
	[PIPELINE] = PINK"pipeline"RESET,
	[SEMICOLON] = RED"semicolon"RESET,
	[WORD] = BLUE"word"RESET
};

struct						s_token
{
	int						type;
	char					*literal;
};

int							token_get(char **pstr, t_token *token);
int							token_get_io(char **pstr, char *pchar, t_token *token);
int							token_get_op(char **pstr, char *pchar, t_token *token);
int							token_get_word(char **pstr, char *pchar, t_token *token);

struct						s_tree
{
	t_token					*token;
	t_tree					*left;
	t_tree					*right;
};

t_tree						*tree_new(t_token *token);
void						tree_insert(t_tree **root, t_tree *new);

t_tree						*parse(char *input);

/* History ****************************************************************** */

struct						s_dlist
{
	char					*line;
	t_dlist					*prev;
	t_dlist					*next;
};

t_dlist						*history_new(void);

void						history_add(char *line, t_dlist **history);
void						history_print(t_dlist **history);

/* I/O *********************************************************************** */

struct						s_io
{
	int						src;
	int						dst;
	int						op;
	t_io					*next;
};

void						io_redirect(t_io **io_stack);

t_io						*io_push(int dst, int src, t_io *io_stack, int op);
t_io						*io_stack_dup(t_io *io_stack);
t_io						*io_stack_new(int dst, int src, int op);

/* Line Edition ************************************************************** */

enum						e_keys
{
	 KEY_CURSOR_LEFT = 4479771,
	 KEY_CURSOR_RIGHT = 4414235,
	 KEY_DEL_BACKSPACE = 127,
	 KEY_DEL_DELETE = 2117294875,
	 KEY_DEL_BEG,
	 KEY_DEL_END,
	 KEY_HISTORY_UP = 4283163,
	 KEY_HISTORY_DOWN = 4348699,
	 KEY_HISTORY_SEARCH,
	 KEY_LINE_UP,
	 KEY_LINE_DOWN,
	 KEY_LINE_BEG,
	 KEY_LINE_END,
	 KEY_NEWLINE = 10,
	 KEY_WORD_PREV,
	 KEY_WORD_NEXT,
	 KEY_COPY,
	 KEY_PASTE,
	 KEY_MAX = 1
};

struct						s_keymap
{
	int						key;
	void					(*f)(t_rl *);
};

void						key_cursor_left(t_rl *rl);
void						key_cursor_right(t_rl *rl);
/*
void						key_del_backspace(t_shell *sh);
void						key_del_delete(t_shell *sh);
void						key_del_beg(t_shell *sh);
void						key_del_end(t_shell *sh);
void						key_history_up(t_shell *sh);
void						key_history_down(t_shell *sh);
void						key_line_up(t_shell *sh);
void						key_line_down(t_shell *sh);
void						key_line_beg(t_shell *sh);
void						key_line_end(t_shell *sh);
void						key_newline(t_shell *sh);
void						key_word_prev(t_shell *sh);
void						key_word_next(t_shell *sh);
void						key_copy(t_shell *sh);
void						key_paste(t_shell *sh);
*/

struct						s_rl
{
	int						key;
	char					*buf;
	int						blen;
	int						plen;
	int						quote;
	int						cx;
	int						cy;
	int						win_col;
	int						win_row;
};

void						raw_mode_enable(void);
void						raw_mode_disable(void);

void						rl_char_insert(t_rl *rl);

char						*rl_readline(void);

#endif
