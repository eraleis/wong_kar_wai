/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:37:50 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/05 19:08:47 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (src[i] != 0 && i < n)
	{
		dst[i] = src[i];
		i = i + 1;
	}
	while (n > i)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
