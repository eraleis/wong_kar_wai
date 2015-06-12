/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 09:42:42 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/06 17:06:43 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (s == d)
		return (dst);
	if (s < d)
	{
		s = s + len - 1;
		d = d + len - 1;
		while (len-- != 0)
			*d-- = *s--;
	}
	else
	{
		while (len-- != 0)
			*d++ = *s++;
	}
	return (dst);
}
