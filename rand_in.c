/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:14:39 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:14:40 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	rand_in(int **map, int size)
{
	int x;
	int y;
	int v;

	if (test_full(map, size) == 1)
		return ;
	x = (int)rand() % size;
	y = (int)rand() % size;
	v = ((int)rand() % 10) ? 2 : 4;
	if (map[x][y] == 0)
	{
		map[x][y] = v;
		return ;
	}
	else
		rand_in(map, size);
}
