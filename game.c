/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:17:41 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:17:42 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	get_max(int **map, int size)
{
	int x;
	int y;
	int score;

	score = 2;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (score < map[y][x])
				score = map[y][x];
			x++;
		}
		y++;
	}
	return (score);
}

int			game(int **map, t_rules rules, t_score *score, int key)
{
	int test_move;

	test_move = 0;
	if (key == 0)
		test_move = move_up(map, rules.size, &(score->score));
	if (key == 1)
		test_move = move_down(map, rules.size, &(score->score));
	if (key == 2)
		test_move = move_left(map, rules.size, &(score->score));
	if (key == 3)
		test_move = move_right(map, rules.size, &(score->score));
	if (test_move == 1)
	{
		score->move++;
		rand_in(map, rules.size);
	}
	score->max = get_max(map, rules.size);
	if (test_end(map, rules.size) == 1)
	{
		if (score->max == rules.win_value)
			return (1);
		else
			return (-1);
	}
	return (0);
}
