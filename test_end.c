/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:23:21 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:23:22 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	test_fusion(int **map, int size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (y < size - 1)
			{
				if (map[y][x] == map[y + 1][x])
					return (0);
			}
			if (x < size - 1)
			{
				if (map[y][x] == map[y][x + 1])
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int			test_end(int **map, int size)
{
	if (test_full(map, size) == 0)
		return (0);
	return (test_fusion(map, size));
}
