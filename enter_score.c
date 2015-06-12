/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:01:35 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 23:01:36 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	void_param(t_rules rules, t_score score)
{
	(void)rules;
	(void)score;
}

void		enter_score(t_rules rules, t_score score)
{
	int		key;
	char	name[6];

	key = -1;
	name[0] = 0;
	printw("  YOU WIN !! - PRESS ENTER TO CONTINUE");
	timeout(-42);
	while (key != 10)
		key = getch();
	echo();
	curs_set(1);
	printw("\n\n  ENTER YOUR NAME: ");
	getnstr(name, 5);
	timeout(200);
	if (name[0] == 0)
	{
		name[0] = 'G';
		name[1] = 'O';
		name[2] = 'D';
		name[3] = 0;
	}
	void_param(rules, score);
	curs_set(0);
	noecho();
	clear();
}
