/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:49:54 by vatourni          #+#    #+#             */
/*   Updated: 2015/02/27 23:49:54 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	init_var(t_coord *c, t_coord *t, t_coord *x)
{
	x->x = 1;
	x->y = 0;
	t->x = 0;
	t->y = 0;
	c->x = 0;
	c->y = 0;
	c->space = 0;
	c->color = 2;
	c->start_case = 1;
	c->line_case = 1;
}

static void	print_info(t_score *score, int win_value)
{
	printw(" move = %d | score = %d | %d / %d", score->move, score->score,
		score->max, win_value);
	if (score->max >= win_value)
		printw(" | YOU WIN !", win_value);
	printw("\n");
}

static void	process_char(int **tab, t_coord *c, t_coord *t, t_coord *x)
{
	c->start_case = 1;
	c->line_case = 1;
	colorstart(tab, c, x, c->size);
	if (x->y > (COLS / c->size) * c->size || x->x > (LINES / c->size) * c->size)
		(c->space <= 0) ? printw(" ") : (c->space--);
	else if (x->y == COLS / (c->size * 2) + t->x && x->x == LINES
		/ (c->size * 2) + t->y)
	{
		t->x += COLS / c->size;
		(tab[c->y][c->x] == 0) ? printw(" ") : printw("%d", tab[c->y][c->x]);
		(tab[c->y][c->x] == 0) ? c->space :
		(c->space += ft_intlen(tab[c->y][c->x]) - 1);
		(c->x)++;
	}
	else if ((x->y % (COLS / c->size)) == 0 && (x->x % (LINES / c->size)) == 0)
		printw(" ");
	else if (x->y == 0 || x->y == COLS - 1 || ((x->y % (COLS / c->size)) == 0))
		printw(" ");
	else if (x->x == 0 || x->x == LINES - 1 || (x->x % (LINES / c->size)) == 0)
		printw(" ");
	else
		(c->space <= 0) ? printw(" ") : (c->space--);
	attroff(COLOR_PAIR(c->color));
}

static void	process_numbers(t_coord *c, t_coord *t, int size)
{
	if (c->x >= size - 1)
	{
		c->x = 0;
		c->y++;
		t->x = 0;
		t->y += LINES / size;
	}
}

void		print_board(int **tab, t_score *score, t_rules rules)
{
	t_coord	c;
	t_coord	t;
	t_coord x;

	if (LINES < rules.size * 3 || COLS < rules.size * 10)
		mvprintw(LINES / 2, COLS / 2 - 8, "Window too small\n");
	else
	{
		print_info(score, rules.win_value);
		init_var(&c, &t, &x);
		while (x.x < LINES)
		{
			x.y = 0;
			while (x.y < COLS)
			{
				c.size = rules.size;
				process_char(tab, &c, &t, &x);
				x.y++;
			}
			process_numbers(&c, &t, rules.size);
			x.x++;
		}
	}
}
