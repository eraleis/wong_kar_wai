/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:58:32 by vatourni          #+#    #+#             */
/*   Updated: 2015/01/01 18:37:21 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	len(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	k;
	char			*str;

	i = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL ||
		(str = malloc(sizeof(char) * (len(s1) + len(s2) + 1))) == NULL)
		return (NULL);
	while (k != len(s1))
	{
		str[i] = s1[k];
		i++;
		k++;
	}
	k = 0;
	while (k != len(s2))
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = '\0';
	return (str);
}
