/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-himd <sal-himd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 22:34:02 by sal-himd          #+#    #+#             */
/*   Updated: 2015/01/23 22:34:07 by sal-himd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static int	ft_ex(char **av, t_env *env)
{
	if (ft_strncmp(av[0], "./", 2) == 0 || av[0][0] == '/'
		|| ft_strncmp(av[0], "../", 3) == 0)
	{
		if (access(av[0], F_OK) == -1)
		{
			ft_putstr_fd("sh1 : no such file or directory: ", 2);
			ft_putendl_fd(av[0], 2);
			return (1);
		}
		if (access(av[0], X_OK) == -1)
		{
			ft_putstr_fd("sh1: permission denied: ", 2);
			ft_putendl_fd(av[0], 2);
			return (1);
		}
		if (av[0][0] == '/' || ft_strncmp(av[0], "../", 3) == 0)
			wait_and_execute(av[0], av, env);
		else
			wait_and_execute(ft_strsub(av[0], 2,
				ft_strlen(av[0]) - 2), av, env);
		return (1);
	}
	return (0);
}

int			bultin(char **av, t_env *env, t_env *env2)
{
	if (ft_ex(av, env2) == 1)
		return (1);
	if (ft_env(av, env2) == 1)
		return (1);
	if (ft_cd(av, env2, env) == 1)
		return (1);
	if (ft_setenv(av, env2, env) == 1)
		return (1);
	if (ft_unsetenv(av, env2, env) == 1)
		return (1);
	if (ft_strcmp(av[0], "exit") == 0)
		exit(0);
	return (0);
}
