/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:54:46 by vatourni          #+#    #+#             */
/*   Updated: 2015/01/01 18:35:50 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*destroyer;

	if (!alst || !*alst)
		return ;
	tmp = (*alst);
	destroyer = (*alst)->next;
	ft_lstdelone(&tmp, del);
	if (destroyer)
		ft_lstdel(&destroyer, del);
	*alst = NULL;
}
