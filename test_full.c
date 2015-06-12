/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_full.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:25:56 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:25:57 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	test_full(int **map, int size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
