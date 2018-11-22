/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 09:47:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/11/22 11:47:52 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"
# include "../ft_readline/ft_readline.h"

# define BLACK				"\x1b[1m"
# define BLUE				"\x1b[0;34m"
# define RED				"\x1b[1;31m"
# define PINK				"\x1b[1;35m"
# define WHITE				"\x1b[1;37m"
# define RESET				"\x1b[0m"

typedef struct s_token		t_token;
typedef enum e_type			t_type;
typedef struct s_ast		t_ast;

char						**g_env;

void						env_init(char **env);

int							env_getlen(char **env);
int							env_replace(char *arg);
void						env_add(char *arg);
void						env_remove(char *arg);
char						*env_getvar(char *varname);

int							sh_prompt_get(char **ref);

void						sh_init(char **env);

char						*rl_expansion(char *str);

void						handle_sig(int sig);
void						handle_childsig(int sig);
void						handle_sig_zom(int sig);

# define BUILTIN_NBR		6

int							builtin_echo(char **args);
int							builtin_cd(char **args);
int							builtin_env(char **args);
int							builtin_setenv(char **args);
int							builtin_unsetenv(char **args);
int							builtin_exit(char **args);

# define B_BSLASH			0x01
# define B_SQUOTE			0x02
# define B_DQUOTE			0x04

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
int							token_get_io(char **pstr, char *pchar,
		t_token *token);
int							token_get_op(char **pstr, char *pchar,
		t_token *token);
int							token_get_word(char **pstr, char *pchar,
		t_token *token);

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

# define NO_PIPE			-1
# define STDIN				0
# define STDOUT				1
# define READ				0
# define WRITE				1
# define WAIT				0x1

void						exe_op_io(t_ast **root, char flag,
		t_io *io_stack);
void						exe_op_less(t_ast **root, char flag,
		t_io *io_stack);
void						exe_op_great(t_ast **root, char flag,
		t_io *io_stack);
void						exe_op_dless(t_ast **root, char flag,
		t_io *io_stack);
void						exe_op_dgreat(t_ast **root, char flag,
		t_io *io_stack);
void						exe_op_lessand(t_ast **root, char flag,
		t_io *io_stack);
void						exe_op_greatand(t_ast **root, char flag,
		t_io *io_stack);
void						exe_op_pipe(t_ast **root, char flag,
		t_io *io_stack);
void						exe_op_semicolon(t_ast **root, char flag,
		t_io *io_stack);

void						exe_bin(char **args, char flag, t_io *io_stack);
void						exe_cmd(char **args, char flag, t_io *io_stack);
void						execute(t_ast **root, char flag, t_io *io_stack);

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

void						ast_print(t_ast **root);

#endif
