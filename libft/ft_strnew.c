/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:18:47 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/04 21:25:11 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*strmem;

	i = 0;
	strmem = malloc(sizeof(char) * (size + 1));
	if (strmem == NULL)
		return (NULL);
	while (i++ < size)
		strmem[i] = '\0';
	strmem[i] = '\0';
	return (strmem);
}
