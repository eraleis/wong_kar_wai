/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:20:28 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:20:29 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	move_left_condition(int **map, int *x, int y, int *i)
{
	if (map[y][(*x) - 1] == 0 && map[y][(*x)] != 0)
	{
		map[y][(*x) - 1] = map[y][(*x)];
		map[y][(*x)] = 0;
		(*x) = (*i);
		return (1);
	}
	else if (map[y][(*x) - 1] == map[y][(*x)] && map[y][(*x)] != 0)
	{
		map[y][(*x) - 1] = 2 * map[y][(*x)];
		map[y][(*x)] = 0;
		(*i) = (*x);
		return (map[y][(*x) - 1]);
	}
	return (0);
}

int			move_left(int **map, int size, int *score)
{
	int x;
	int y;
	int i;
	int test_move;
	int score_plus;

	y = 0;
	test_move = 0;
	while (y < size)
	{
		x = 1;
		i = 0;
		while (x < size)
		{
			score_plus = move_left_condition(map, &x, y, &i);
			if (score_plus >= 1)
				test_move = 1;
			if (score_plus > 1)
				(*score) += score_plus;
			x++;
		}
		y++;
	}
	return (test_move);
}
