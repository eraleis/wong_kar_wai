/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:17:50 by vatourni          #+#    #+#             */
/*   Updated: 2015/02/27 20:17:51 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <curses.h>
# include "libft/libft.h"
# include <fcntl.h>

int				g_signal;

enum	e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_coord
{
	int x;
	int	y;
	int	start_case;
	int	line_case;
	int	color;
	int space;
	int	size;
}				t_coord;

typedef struct	s_score
{
	int			move;
	int			max;
	int			score;
}				t_score;

typedef struct	s_topscore
{
	int			rank;
	char		**name;
	t_score		score;
}				t_topscore;

typedef struct	s_rules
{
	int			size;
	int			rand_nb;
	int			win_value;
}				t_rules;

void			free_map(int **map, int size);
void			free_2d_tab(char **tab);
void			rand_in(int **map, int size);
int				keyhook(int **map, t_rules *rules, t_score *score);
void			print_board(int **map, t_score *score, t_rules rules);
void			resize_board(int **map, t_score *score, t_rules rules);
void			catch_signal(void);
void			back_to_normal(void);
int				game(int **map, t_rules rules, t_score *score, int key);
int				test_full(int **map, int size);
int				change_winscore(t_rules *rules);
int				change_size(t_rules *rules);
int				print_score(t_rules rules, t_score score);
int				set_pos(int key, int i, int max);
int				start_menu(t_rules *rules);
int				**alloc_map(int size);
int				test_win_value(int win_value);
int				**init_map(int **map, int size, int rand_nb);
int				game(int **map, t_rules rules, t_score *score, int key);
int				move_right(int **map, int size, int *score);
int				move_left(int **map, int size, int *score);
int				move_up(int **map, int size, int *score);
int				move_down(int **map, int size, int *score);
int				test_end(int **map, int size);
int				test_full(int **map, int size);
void			init_term(void);
int				get_color(int nb);
int				ft_intlen(int nb);
void			colorstart(int **tab, t_coord *c, t_coord *x, int size);
void			colorback(void);
int				change_key(t_rules *rules, int key, int i);
int				getscore(void);
int				credit(void);
void			enter_score(t_rules rules, t_score score);

#endif
