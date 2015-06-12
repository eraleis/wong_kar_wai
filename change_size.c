/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:56:28 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 16:56:29 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		change_size(t_rules *rules)
{
	int	size;
	int	key;

	key = -1;
	size = 4;
	clear();
	printw("  size: %d ", size);
	while (42)
	{
		key = getch();
		if (key != -1)
		{
			clear();
			if (key == 10)
				break ;
			if (key == KEY_UP && size < 27)
				size++;
			if (key == KEY_DOWN && size > 3)
				size--;
			printw("  size: %d ", size);
		}
	}
	rules->size = size;
	return (1);
}
