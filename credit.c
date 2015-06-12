/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   credit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:55:06 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 22:55:07 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		credit(void)
{
	int		fd;
	int		key;
	int		nb;
	char	buf[1024];

	clear();
	key = -1;
	printw("vatourni & sal-himd did that shit\n");
	if ((fd = open("ascii.txt", O_RDONLY)) != -1)
	{
		while ((nb = read(fd, buf, 1022)) != 0)
		{
			buf[nb] = 0;
			printw(buf);
		}
		close(fd);
	}
	printw("\n\nPRESS ANY KEY TO EXIT\n");
	while (key == -1)
		key = getch();
	return (1);
}
