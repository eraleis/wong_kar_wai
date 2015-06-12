/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:28:21 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:28:22 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	colorinit(void)
{
	int	i;

	init_color(0, 1000, 1000, 1000);
	init_color(2, 680, 384, 664);
	init_color(1, 850, 850, 850);
	init_color(3, 948, 788, 252);
	init_color(4, 876, 708, 488);
	init_color(5, 980, 496, 380);
	init_color(6, 820, 284, 108);
	init_color(7, 250, 250, 250);
	i = 0;
	while (i < 8)
	{
		init_pair(i, 7, i);
		i++;
	}
}

void		init_term(void)
{
	catch_signal();
	initscr();
	curs_set(0);
	start_color();
	colorinit();
	timeout(200);
	g_signal = 0;
	noecho();
	keypad(stdscr, 1);
}
