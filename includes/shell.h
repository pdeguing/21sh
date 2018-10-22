/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 09:47:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/22 12:48:13 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

/*
** Colors
*/

# define BLACK				"\x1b[1m"
# define BLUE				"\x1b[0;34m"
# define RED				"\x1b[1;31m"
# define PINK				"\x1b[1;35m"
# define WHITE				"\x1b[1;37m"
# define RESET				"\x1b[0m"


/*
** Typedefs
*/

typedef struct s_tree		t_tree;
typedef struct s_token		t_token;
typedef enum e_type			t_type;

/*
** Intern headers
*/

# include "parsing.h"
# include "debugging.h"
# include "builtins.h"
# include "execute.h"

/*
** Environment
*/

char						**g_env;

void						init_g_env(char **env);
char						*get_varenv(char *varname);

/*
** Utilities
*/

void						put_prompt(void);
void						init_gsh(char **env);

/*
** Signals
*/

void						handle_sig(int sig);
void						handle_childsig(int sig);

#endif
