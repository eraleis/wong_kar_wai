/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:22:34 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/05 19:09:52 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*res;

	res = NULL;
	len = 0;
	while (s[len])
	{
		if (s[len] == (char)c)
			res = (char *)&s[len];
		len++;
	}
	if (s[len] == (char)c)
		res = (char *)&s[len];
	return (res);
}
