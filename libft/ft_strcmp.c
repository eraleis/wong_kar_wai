/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatourni <vatourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:23:00 by vatourni          #+#    #+#             */
/*   Updated: 2014/11/05 19:05:51 by vatourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (us1[i] != '\0')
	{
		if (us2[i] != us1[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (us2[i] != us1[i])
		return (us1[i] - us2[i]);
	return (0);
}
