/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:11:56 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:11:57 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	**alloc_map(int size)
{
	int **map;
	int i;

	map = (int**)malloc(sizeof(int*) * size);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map[i] = (int*)malloc(sizeof(int) * size);
		if (map[i] == NULL)
			return (NULL);
		i++;
	}
	return (map);
}
