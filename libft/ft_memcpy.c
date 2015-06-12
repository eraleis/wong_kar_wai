/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:21:04 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/06 17:12:09 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char *dest;
	unsigned char *source;

	dest = dst;
	source = src;
	while (n-- != 0)
		*dest++ = *source++;
	return (dst);
}
