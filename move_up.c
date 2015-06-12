/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:21:33 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:21:34 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	move_up_condition(int **map, int *y, int x, int *i)
{
	if (map[(*y) - 1][x] == 0 && map[(*y)][x] != 0)
	{
		map[(*y) - 1][x] = map[(*y)][x];
		map[(*y)][x] = 0;
		(*y) = (*i);
		return (1);
	}
	else if (map[(*y) - 1][x] == map[(*y)][x] && map[(*y)][x] != 0)
	{
		map[(*y) - 1][x] = 2 * map[(*y)][x];
		map[(*y)][x] = 0;
		(*i) = (*y);
		return (map[(*y) - 1][x]);
	}
	return (0);
}

int			move_up(int **map, int size, int *score)
{
	int x;
	int y;
	int i;
	int test_move;
	int score_plus;

	x = 0;
	while (x < size)
	{
		i = 0;
		y = 1;
		while (y < size)
		{
			score_plus = move_up_condition(map, &y, x, &i);
			if (score_plus >= 1)
				test_move = 1;
			if (score_plus > 1)
				(*score) += score_plus;
			y++;
		}
		x++;
	}
	return (test_move);
}
