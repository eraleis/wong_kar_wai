/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-himd <sal-himd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 22:41:08 by sal-himd          #+#    #+#             */
/*   Updated: 2015/01/23 22:41:11 by sal-himd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void clear_tab(char *str)
{
	int i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
}

void ft_sh(char **av, t_env *env, t_env *env2)
{
	if (av[0] != NULL)
	{
		if (bultin(av, env, env2) == 1)
			return ;
		if (cmd(av, env, env2) == 1)
			return ;
		else
		{
			ft_putstr_fd("sh1: command not found: ", 2);
			ft_putendl_fd(av[0], 2);
		}
	}
}

void ft_sh1(t_env *env, t_env *env2)
{
	char	**av;
	char	**ins;
	char	*line;
	int		i;

	ft_putstr("Sh1 : $> ");
	get_next_line(0, &line);
	clear_tab(line);
	ins = ft_strsplit(line, ';');
	i = 0;
	while (ins[i] != NULL)
	{
		av = ft_strsplit(ins[i], ' ');
		ft_sh(av, env, env2);
		i++;
	}
}
