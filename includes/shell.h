/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 09:47:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/20 07:53:54 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
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
# include "execute.h"

/*
** Environment
*/

char						**g_env;

void						init_g_env(char **env);

/*
** Utilities
*/

void						put_prompt(void);

void						init_gsh(char **env);

#endif
