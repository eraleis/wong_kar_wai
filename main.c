/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:13:34 by vatourni          #+#    #+#             */
/*   Updated: 2015/02/27 20:13:35 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	init_score(t_score *score)
{
	clear();
	score->score = 0;
	score->move = 0;
	score->max = 0;
}

static void	init_rules(t_rules *rules)
{
	srand(time(NULL));
	rules->size = 4;
	rules->rand_nb = 2;
	rules->win_value = WIN_VALUE;
	init_term();
}

static int	play(t_rules *rules, t_score *score)
{
	int		q;
	int		**map;

	map = alloc_map(rules->size);
	map = init_map(map, rules->size, rules->rand_nb);
	q = keyhook(map, rules, score);
	free_map(map, rules->size);
	return (q);
}

static void	back_noclear(void)
{
	echo();
	curs_set(1);
	endwin();
	ft_putstr_fd("WIN_VALUE not power 2\n", 2);
}

int			main(void)
{
	int		q;
	t_rules	rules;
	t_score	score;

	init_rules(&rules);
	q = (test_win_value(WIN_VALUE) == 0) ? 69 : 1;
	while (42)
	{
		init_score(&score);
		q = (q == 1) ? start_menu(&rules) : q;
		if (q == 0 || q == 69)
			break ;
		q = (q == 3) ? play(&rules, &score) : q;
		q = (q == 24) ? getscore() : q;
		q = (q == 9) ? credit() : q;
		if (q > 10)
		{
			q = print_score(rules, score);
			q = (q == 0) ? 3 : q;
			if (q == 2 || q == 42)
				break ;
		}
	}
	(q != 69) ? back_to_normal() : back_noclear();
	return (0);
}
