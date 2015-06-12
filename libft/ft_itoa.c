/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:13:46 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/05 19:29:24 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			len(int n)
{
	int		res;

	res = 1;
	while (n < -9 || n > 9)
	{
		res++;
		n = n / 10;
	}
	if (n >= 0)
		return (res);
	else
		return (res + 1);
}

char				*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		neg;

	if (n < 0)
		neg = 1;
	else
		neg = 0;
	i = len(n);
	res = (char *)ft_memalloc(sizeof(char) * i + 1);
	while (i-- != 0)
	{
		if (n < 0)
			res[i] = (((n % 10) * -1) + '0');
		else
			res[i] = ((n % 10) + '0');
		n = n / 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
