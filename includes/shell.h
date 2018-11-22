/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 09:47:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/21 08:55:05 by pdeguing         ###   ########.fr       */
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
typedef struct s_ast		t_ast;
typedef struct s_dlist		t_dlist;
typedef struct s_io			t_io;
typedef struct s_keymap		t_keymap;
typedef struct termios		t_termios;
typedef struct s_rl			t_rl;
typedef struct s_row		t_row;

/* Environment ************************************************************** */

char						**g_env;

void						env_init(char **env);

int							env_getlen(char **env);
int							env_replace(char *arg);
void						env_add(char *arg);
void						env_remove(char *arg);
char						*env_getvar(char *varname);

/* General ****************************************************************** */

int							sh_prompt_get(char **ref);

void						sh_init(char **env);

/* Signals ****************************************************************** */

void						handle_sig(int sig);
void						handle_childsig(int sig);
void						handle_sig_zom(int sig);

/* Builtins ***************************************************************** */

# define BUILTIN_NBR		6

int							builtin_echo(char **args);
int							builtin_cd(char **args);
int							builtin_env(char **args);
int							builtin_setenv(char **args);
int							builtin_unsetenv(char **args);
int							builtin_exit(char **args);

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

struct						s_token
{
	int						type;
	char					*literal;
};

int							token_get(char **pstr, t_token *token);
int							token_get_io(char **pstr, char *pchar, t_token *token);
int							token_get_op(char **pstr, char *pchar, t_token *token);
int							token_get_word(char **pstr, char *pchar, t_token *token);

struct						s_ast
{
	t_token					*token;
	t_ast					*left;
	t_ast					*right;
};

t_ast						*ast_new(t_token *token);
void						ast_insert(t_ast **root, t_ast *new);
void						ast_free(t_ast **root);


t_ast						*parse(char *input);

/* Execute ****************************************************************** */

# define NO_PIPE		-1
# define STDIN			0
# define STDOUT			1
# define READ			0
# define WRITE			1
# define WAIT			0x1

void				exe_op_io(t_ast **root, char flag, t_io *io_stack);
void				exe_op_less(t_ast **root, char flag, t_io *io_stack);
void				exe_op_great(t_ast **root, char flag, t_io *io_stack);
void				exe_op_dless(t_ast **root, char flag, t_io *io_stack);
void				exe_op_dgreat(t_ast **root, char flag, t_io *io_stack);
void				exe_op_lessand(t_ast **root, char flag, t_io *io_stack);
void				exe_op_greatand(t_ast **root, char flag, t_io *io_stack);
void				exe_op_pipe(t_ast **root, char flag, t_io *io_stack);
void				exe_op_semicolon(t_ast **root, char flag, t_io *io_stack);

void				exe_bin(char **args, char flag, t_io *io_stack);
void				exe_cmd(char **args, char flag, t_io *io_stack);
void				execute(t_ast **root, char flag, t_io *io_stack);

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

void						io_redirect(t_io *io_stack);
void						io_free(t_io **io_stack);

t_io						*io_push(int dst, int src, t_io *io_stack, int op);
t_io						*io_stack_dup(t_io *io_stack);
t_io						*io_stack_new(int dst, int src, int op);

/* Readline ****************************************************************** */

/* Execution modes */

# define DEFAULT			0x0
# define NO_QUOTE			0b0000001
# define NO_HISTORY			0b0000010

# define IS_QUOTE(c)		ft_strchr("\\\'\"", c)

# define Q_BSLASH			0b00000001
# define Q_SQUOTE			0b00000010
# define Q_DQUOTE			0b00000100

struct						s_row
{
	int						bsize;
	char					*buf;
};

enum						e_keys
{
	 KEY_CURSOR_LEFT = 4479771,
	 KEY_CURSOR_RIGHT = 4414235,
	 KEY_DEL_BACKSPACE = 127,
	 KEY_DEL_DELETE = 2117294875,
	 KEY_DEL_BEG = 21,
	 KEY_DEL_END = 11,
	 KEY_HISTORY_UP = 4283163,
	 KEY_HISTORY_DOWN = 4348699,
	 KEY_HISTORY_SEARCH,
	 KEY_CURSOR_BEG = 4741915,
	 KEY_CURSOR_END = 4610843,
	 KEY_CTL_ARROW = 993090331,
	 KEY_NEWLINE = 10,
	 KEY_COPY = 16,
	 KEY_PASTE = 12,
	 KEY_SIG_INT = 3,
	 KEY_SIG_EOF = 4,
	 KEY_MAX = 16
};

# define KEY_CTL_UP			16693
# define KEY_CTL_DOWN		16949
# define KEY_CTL_LEFT		17461
# define KEY_CTL_RIGHT		17205

struct						s_keymap
{
	int						key;
	void					(*f)(t_rl *);
};

void						key_cursor_left(t_rl *rl);
void						key_cursor_right(t_rl *rl);
void						key_del_backspace(t_rl *rl);
void						key_del_delete(t_rl *rl);
void						key_del_beg(t_rl *rl);
void						key_del_end(t_rl *rl);
void						key_history_up(t_rl *rl);
void						key_history_down(t_rl *rl);
void						key_newline(t_rl *rl);
void						key_cursor_beg(t_rl *rl);
void						key_cursor_end(t_rl *rl);
void						key_copy(t_rl *rl);
void						key_paste(t_rl *rl);
void						key_sig_int(t_rl *rl);
void						key_sig_eof(t_rl *rl);
void						key_ctl_arrow(t_rl *rl);
void						key_ctl_up(t_rl *rl);
void						key_ctl_down(t_rl *rl);
void						key_ctl_left(t_rl *rl);
void						key_ctl_right(t_rl *rl);

struct						s_rl
{
	int						key;
	t_row					*row;
	int						row_max;
	int						prompt_size;
	int						quote_status;
	int						cx;
	int						cy;
	int						win_col;
	int						win_row;
	t_dlist					*history_head;
	int						history_state;
	int						status;
};

void						raw_mode_enable(void);
void						raw_mode_disable(void);

char						*rl_expansion(char *str);

void						rl_char_insert(t_rl *rl);

void						rl_row_insert(t_rl *rl, char *buf);
char						*rl_row_join(t_rl *rl);

void						rl_display_print(t_rl *rl);
void						rl_display_clear(t_rl *rl);

char						*rl_readline(const char *prompt, int psize, int mode);

/* Debugging **************************************************************** */
 
# define STR_TEST			"mkdir test ; cd test ; ls -a ; ls | 'cat | wc' -c > fifi"
# define STR_1				"ls libft"
# define STR_2				"ls ; echo hello"
# define STR_3				"cat -e; ls | cat -e > file; cat -e > file < input"

void						ast_print(t_ast **root);

#endif
