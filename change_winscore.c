/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_winscore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:56:19 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 16:56:20 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		change_winscore(t_rules *rules)
{
	int	score;
	int	key;

	key = -1;
	score = 2048;
	clear();
	printw("  WIN SCORE: %d ", score);
	while (42)
	{
		key = getch();
		if (key != -1)
		{
			clear();
			if (key == 10)
				break ;
			if (key == KEY_UP && score < 131072)
				score *= 2;
			if (key == KEY_DOWN && score > 8)
				score /= 2;
			printw("  WIN SCORE: %d ", score);
		}
	}
	rules->win_value = score;
	return (1);
}
