/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:01:35 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:01:36 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	aff_score(t_score score, t_rules rules)
{
	if (score.max >= rules.win_value)
		printw("  YOU WIN !! | score: [%d], max: [%d], winscore: [%d]\n\n",
			score.score, score.max, rules.win_value);
	else
		printw("  GAME OVER :( | score: [%d], max: [%d], winscore: [%d]\n\n",
			score.score, score.max, rules.win_value);
}

static char	**build_end_menu(void)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 4);
	tab[0] = ft_strdup("PLAY AGAIN");
	tab[1] = ft_strdup("MENU");
	tab[2] = ft_strdup("EXIT");
	tab[3] = 0;
	return (tab);
}

static void	print_end_menu(char **tab, int pos, t_score score, t_rules rules)
{
	int i;

	i = 0;
	aff_score(score, rules);
	while (tab[i] != 0)
	{
		printw("  ");
		if (pos == i)
			attron(COLOR_PAIR(3));
		if (i != 0)
			printw("  ");
		printw(" %s ", tab[i]);
		if (i != 0)
			printw("    ");
		if (pos == i)
			attroff(COLOR_PAIR(3));
		printw("\n");
		i++;
	}
}

int			print_score(t_rules rules, t_score score)
{
	int		key;
	int		i;
	char	**tab;

	i = 0;
	clear();
	tab = build_end_menu();
	(score.max >= rules.win_value) ? enter_score(rules, score) : 0;
	print_end_menu(tab, i, score, rules);
	while (42)
	{
		key = getch();
		if (key != -1)
		{
			if (key == 10)
				break ;
			if (key == 27)
				return (42);
			clear();
			i = set_pos(key, i, 3);
			print_end_menu(tab, i, score, rules);
		}
	}
	free_2d_tab(tab);
	return (i);
}
