/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:52:55 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/05 19:07:12 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	int			a;
	size_t		res;

	i = 0;
	a = 0;
	res = ft_strlen(dst) + ft_strlen(src);
	while (dst[i] != 0 && i < size)
		i = i + 1;
	if (size - i == 0)
		return (i + ft_strlen(src));
	while (i != (size - 1) && src[a] != 0)
	{
		dst[i] = src[a];
		i++;
		a++;
	}
	dst[i] = 0;
	return (res);
}
