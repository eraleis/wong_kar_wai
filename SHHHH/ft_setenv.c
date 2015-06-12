/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-himd <sal-himd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 03:47:40 by sal-himd          #+#    #+#             */
/*   Updated: 2015/01/24 03:47:42 by sal-himd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static int		ft_setenv_main(char **av, t_env *env, t_env *env2)
{
	int		i;
	char	*var;

	var = ft_strjoin(av[1], "=");
	i = 0;
	while (env->envp[i] != NULL)
	{
		if (ft_strncmp(var, env->envp[i], ft_strlen(var)) == 0)
		{
			env->envp[i] = ft_strjoin(var, av[2]);
			*env = set_env(env->envp);
			*env2 = set_env(env->envp);
			return (1);
		}
		i++;
	}
	env->envp = ft_realloc_tab(env->envp);
	env->envp[i] = ft_strjoin(var, av[2]);
	env->envp[i + 1] = NULL;
	*env = set_env(env->envp);
	*env2 = set_env(env->envp);
	return (1);
}

int				ft_setenv(char **av, t_env *env, t_env *env2)
{
	if (ft_strcmp(av[0], "setenv") == 0)
	{
		if (av[1] == NULL)
		{
			ft_put_strsplit(env->envp);
			return (1);
		}
		ft_setenv_main(av, env, env2);
		return (1);
	}
	return (0);
}

static void		ft_unsetenv_main(char **av, t_env *env, t_env *env2)
{
	int		i;
	char	*var;

	var = ft_strjoin(av[1], "=");
	i = 0;
	while (env->envp[i] != NULL)
	{
		if (ft_strncmp(var, env->envp[i], ft_strlen(var)) == 0)
			env->envp = supress_var(env->envp, i);
		i++;
	}
	*env = set_env(env->envp);
	*env2 = set_env(env->envp);
}

int				ft_unsetenv(char **av, t_env *env, t_env *env2)
{
	if (ft_strcmp(av[0], "unsetenv") == 0)
	{
		if (av[1] == NULL)
		{
			ft_putendl_fd("unsetenv: no variable name", 2);
			return (1);
		}
		if (ft_strcmp(av[1], "*") == 0)
		{
			*env = set_env(NULL);
			*env2 = set_env(NULL);
			return (1);
		}
		ft_unsetenv_main(av, env, env2);
		return (1);
	}
	return (0);
}
