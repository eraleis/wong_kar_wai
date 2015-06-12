/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:46:22 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/05 19:24:52 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		mem[i] = f(s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
