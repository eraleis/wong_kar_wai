/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:07:48 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:07:49 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static char	**build_start_menu(void)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 7);
	tab[0] = ft_strdup("PLAY");
	tab[1] = ft_strdup("CHANGE WIN SCORE");
	tab[2] = ft_strdup("CHANGE SIZE");
	tab[3] = ft_strdup("SCORE");
	tab[4] = ft_strdup("CREDIT");
	tab[5] = ft_strdup("EXIT");
	tab[6] = 0;
	return (tab);
}

static void	print_start(char **tab, int pos, t_rules *rules)
{
	int	i;

	i = 0;
	printw("  BIENVENUE :) ");
	attron(COLOR_PAIR(5));
	printw(" SIZE = %d ", rules->size);
	attroff(COLOR_PAIR(5));
	printw(" | ");
	attron(COLOR_PAIR(4));
	printw(" WIN SCORE = %d \n\n", rules->win_value);
	attroff(COLOR_PAIR(4));
	while (tab[i] != 0)
	{
		printw(" ");
		if (pos == i)
			attron(COLOR_PAIR(3));
		printw(" %s \n", tab[i]);
		if (pos == i)
			attroff(COLOR_PAIR(3));
		i++;
	}
}

static int	choose_key(int key, int i)
{
	if (key == 27)
		return (0);
	if (i == 0)
		return (3);
	if (i == 4)
		return (9);
	if (i == 3)
		return (24);
	return (0);
}

int			start_menu(t_rules *rules)
{
	int		key;
	int		i;
	char	**tab;

	i = 0;
	key = -1;
	clear();
	tab = build_start_menu();
	print_start(tab, i, rules);
	while (42)
	{
		key = getch();
		if (key != -1)
		{
			if ((change_key(rules, key, i) == 0) && (key == 10 || key == 27))
				break ;
			clear();
			i = set_pos(key, i, 6);
			print_start(tab, i, rules);
		}
	}
	clear();
	free_2d_tab(tab);
	return (choose_key(key, i));
}
