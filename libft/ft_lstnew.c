/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:10:43 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/06 14:43:29 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	tmp->content = NULL;
	if (content == NULL)
		tmp->content_size = 0;
	else
	{
		tmp->content = ft_memalloc(content_size);
		ft_bzero(tmp->content, content_size);
		ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}
