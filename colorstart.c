/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorstart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:48:14 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:48:15 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	colorstart(int **tab, t_coord *c, t_coord *x, int size)
{
	while (x->y > (COLS / size * c->start_case) && c->start_case < size)
		(c->start_case)++;
	while (x->x > (LINES / size * c->line_case) && c->line_case < size)
		(c->line_case)++;
	c->color = get_color(tab[(c->line_case) - 1][(c->start_case) - 1]);
	if (x->y > 0 && x->x > 0)
	{
		if (x->y < (COLS / size * c->start_case) && x->x <
			(LINES / size * c->line_case))
			attron(COLOR_PAIR(c->color));
	}
}
