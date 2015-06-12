/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:50:36 by vatourni          #+#    #+#             */
/*   Updated: 2015/02/27 23:50:37 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	resize_board(int **map, t_score *score, t_rules rules)
{
	clear();
	endwin();
	refresh();
	print_board(map, score, rules);
	g_signal = 0;
}
