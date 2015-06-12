/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:47:54 by vatourni          #+#    #+#             */
/*   Updated: 2015/02/27 23:47:55 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int		compute_key(int key)
{
	int	move;

	if (key == KEY_UP)
		move = 0;
	else if (key == KEY_DOWN)
		move = 1;
	else if (key == KEY_LEFT)
		move = 2;
	else if (key == KEY_RIGHT)
		move = 3;
	return (move);
}

static int		compute_end(int key, t_score score, t_rules rules)
{
	(void)score;
	(void)rules;
	if (key == 27)
		return (1);
	else if (score.max >= rules.win_value)
		return (11);
	else if (score.max < rules.win_value)
		return (12);
	return (0);
}

int				keyhook(int **map, t_rules *rules, t_score *score)
{
	int	w;
	int	key;

	w = 0;
	print_board(map, score, *rules);
	while (42)
	{
		key = getch();
		if (key == 27)
			break ;
		if (key == KEY_UP || key == KEY_DOWN ||
			key == KEY_LEFT || key == KEY_RIGHT)
		{
			if ((w = game(map, *rules, score, compute_key(key))) != 0)
				break ;
			clear();
			print_board(map, score, *rules);
		}
		if (g_signal == 1)
			resize_board(map, score, *rules);
	}
	return (compute_end(key, *score, *rules));
}
