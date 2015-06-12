/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:32:12 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/05 19:26:41 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_wd(const char *s, char c)
{
	int	k;
	int	wd;

	k = 0;
	wd = 0;
	while (s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		if (s[k] != c && s[k] != '\0')
			wd++;
		while (s[k] != c && s[k] != '\0')
			k++;
	}
	return (wd);
}

static int		len_wd(const char *str, int i, char c)
{
	int	max;

	max = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		max++;
		i++;
	}
	return (max);
}

static int		skip(const char *str, int k, char c)
{
	while (str[k] == c)
		k++;
	return (k);
}

char			**ft_strsplit(const char *str, char c)
{
	char	**tab;
	int		i[2];
	int		k;

	i[0] = 0;
	k = 0;
	if (str == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_wd(str, c) + 1));
	while (i[0] < count_wd(str, c))
	{
		k = skip(str, k, c);
		i[1] = 0;
		tab[i[0]] = (char *)malloc(sizeof(char) * (len_wd(str, k, c) + 1));
		while (str[k] != '\0' && str[k] != c)
		{
			tab[i[0]][i[1]] = str[k];
			k++;
			i[1]++;
		}
		tab[i[0]][i[1]] = '\0';
		i[0]++;
	}
	tab[i[0]] = NULL;
	return (tab);
}
