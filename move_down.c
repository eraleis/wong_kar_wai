/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:22:34 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:22:35 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	move_down_condition(int **map, int *y, int x, int *i)
{
	if (map[(*y) + 1][x] == 0 && map[(*y)][x] != 0)
	{
		map[(*y) + 1][x] = map[(*y)][x];
		map[(*y)][x] = 0;
		(*y) = (*i);
		return (1);
	}
	else if (map[(*y) + 1][x] == map[(*y)][x] && map[(*y)][x] != 0)
	{
		map[(*y) + 1][x] = 2 * map[(*y)][x];
		map[(*y)][x] = 0;
		(*i) = (*y);
		return (map[(*y) + 1][x]);
	}
	return (0);
}

int			move_down(int **map, int size, int *score)
{
	int x;
	int y;
	int i;
	int test_move;
	int score_plus;

	x = 0;
	test_move = 0;
	while (x < size)
	{
		i = size - 1;
		y = size - 2;
		while (y >= 0)
		{
			score_plus = move_down_condition(map, &y, x, &i);
			if (score_plus >= 1)
				test_move = 1;
			if (score_plus > 1)
				(*score) += score_plus;
			y--;
		}
		x++;
	}
	return (test_move);
}
