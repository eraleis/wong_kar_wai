/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:21:37 by vatourni          #+#    #+#             */
/*   Updated: 2014/12/03 13:21:38 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
