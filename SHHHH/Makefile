# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sal-himd <sal-himd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/15 20:36:42 by sal-himd          #+#    #+#              #
#    Updated: 2014/12/15 20:36:47 by sal-himd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_minishell1

SRC		+= main.c
SRC		+= ft_sh1.c
SRC		+= set_env.c
SRC		+= bultin.c
SRC		+= cmd.c
SRC		+= ft_setenv.c
SRC		+= env.c
SRC		+= cd.c

OBJ		+= $(subst .c,.o,$(SRC))

INC		+= $(DIR_INC)/ft_ls.h

GCC		= gcc -Wall -Werror -Wextra

LIBFT 	= /libft/libft.a


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ 
	$(GCC) -o $@ $^ -L libft/ -lft
	
%.o: %.c 
	$(GCC) -I libft/includes -o $@  -c $< 

clean:
	make clean -C libft/ 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)

re: fclean all

