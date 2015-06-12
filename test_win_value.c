/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_win_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:13:14 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 17:13:15 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	test_power2(int value)
{
	if (value == 1)
		return (1);
	if (value % 2 == 0)
		return (test_power2(value / 2));
	return (0);
}

int			test_win_value(int win_value)
{
	if (win_value <= 4)
		return (0);
	return (test_power2(win_value));
}
