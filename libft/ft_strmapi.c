/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 22:02:38 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/05 19:28:18 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		mem[i] = f(i, s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
