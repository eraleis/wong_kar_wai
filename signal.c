/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:52:32 by vatourni          #+#    #+#             */
/*   Updated: 2015/02/27 23:52:33 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	ft_signal(int sig)
{
	if (sig == SIGWINCH)
	{
		g_signal = 1;
	}
	else if (sig == SIGINT)
	{
		back_to_normal();
		exit(0);
	}
}

void		catch_signal(void)
{
	signal(SIGWINCH, ft_signal);
	signal(SIGINT, ft_signal);
}
