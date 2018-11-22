# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 09:34:56 by pdeguing          #+#    #+#              #
#    Updated: 2018/11/22 08:48:03 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror

NAME	= 21sh 

SRCS	= srcs/*.c

LIBFT	= libft/libft.a
FT_READLINE	= ft_readline/ft_readline.a

all: $(NAME)

$(NAME): $(LIBFT) cmp

$(LIBFT):
	@ cd libft/ && make

cmp:
	@ gcc -o $(NAME) $(CFLAGS) $(SRCS) -Iincludes $(LIBFT) $(FT_READLINE) -ltermcap

clean:
	@ /bin/rm -f *.o
	@ cd libft/ && make clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ cd libft/ && make fclean

re: fclean all

.PHONY: clean fclean all re
