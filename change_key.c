/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:49:06 by vatourni          #+#    #+#             */
/*   Updated: 2015/03/01 22:49:07 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	change_key(t_rules *rules, int key, int i)
{
	if (key == 10 && i == 2)
	{
		change_size(rules);
		return (1);
	}
	else if (key == 10 && i == 1)
	{
		change_winscore(rules);
		return (1);
	}
	return (0);
}
