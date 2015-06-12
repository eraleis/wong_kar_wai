/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:16:14 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:16:15 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	**init_map(int **map, int size, int rand_nb)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			map[y][x] = 0;
			x++;
		}
		y++;
	}
	x = 0;
	while (x < rand_nb)
	{
		rand_in(map, size);
		x++;
	}
	return (map);
}
