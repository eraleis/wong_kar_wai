/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:05:16 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/05 19:19:01 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*res;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	res = (char *)s1;
	if (s2[0] == 0)
		return (res);
	if (n < ft_strlen(s2))
		return (NULL);
	while (*res && i <= (n - ft_strlen(s2)))
	{
		if (!(ft_memcmp(res, s2, ft_strlen(s2))))
			return (res);
		res++;
		i++;
	}
	return (NULL);
}
