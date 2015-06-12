# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 20:16:37 by vatourni          #+#    #+#              #
#    Updated: 2015/02/27 20:16:38 by vatourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

CC = gcc $(FLAG)

FLAG = -Wall -Werror -Wextra

SRC += main.c key.c resize.c board.c back.c signal.c change_size.c free_tab.c test_win_value.c
SRC += change_winscore.c print_end.c set_pos.c print_start.c free_map.c alloc_map.c rand_in.c
SRC += init_map.c game.c move_left.c move_right.c move_up.c move_down.c test_end.c test_full.c
SRC += init_term.c get_color.c ft_intlen.c colorstart.c change_key.c get_score.c credit.c enter_score.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc -o $(NAME) $(OBJ) libft/libft.a -lncurses
clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
