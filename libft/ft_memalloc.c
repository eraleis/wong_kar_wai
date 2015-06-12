/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:48:19 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/05 19:02:22 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	size_t			i;
	void			*mem;
	unsigned char	*p;

	i = 0;
	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	p = mem;
	while (i++ < size)
		*p++ = 0;
	return (mem);
}
