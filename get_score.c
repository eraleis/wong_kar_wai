/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:54:34 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 22:54:36 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int			getscore(void)
{
	int		fd;
	int		nb;
	int		key;
	char	buf[1024];

	clear();
	key = -1;
	nb = 1;
	if ((fd = open("scores.txt", O_RDONLY)) != -1)
	{
		while ((nb = read(fd, buf, 1022)) != 0)
		{
			buf[nb] = 0;
			printw(buf);
		}
		close(fd);
	}
	else
		printw("can't open: \'scores.txt\'");
	printw("\nPRESS ANY KEY TO EXIT\n");
	while (key == -1)
		key = getch();
	return (1);
}
