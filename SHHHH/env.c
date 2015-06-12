/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-himd <sal-himd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:41:16 by sal-himd          #+#    #+#             */
/*   Updated: 2015/02/04 17:42:32 by sal-himd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char			**env_set_end(char **av2, char *str, int j)
{
	av2 = ft_realloc_tab(av2);
	av2[j] = ft_strdup(str);
	av2[j + 1] = NULL;
	return (av2);
}

static char		**env_set_new(char **av, char **av2, int i, int test)
{
	int		j;

	if (av2 == NULL)
	{
		av2 = (char**)malloc(sizeof(char*) * 2);
		av2[0] = ft_strdup(av[i]);
		av2[1] = NULL;
		test = 1;
	}
	if (av2 != NULL)
	{
		j = 0;
		while (av2[j] != NULL)
		{
			if (ft_strncmp(av[i], av2[j], ft_strchr(av[i], '=') - av[i]) == 0)
			{
				av2[j] = ft_strdup(av[i]);
				test = 1;
			}
			j++;
		}
		av2 = (test == 0) ? env_set_end(av2, av[i], j) : av2;
		test = 0;
	}
	return (av2);
}

static int		env_set(char **av, char **av2, t_env *env, int start)
{
	t_env	env2;
	int		i;

	i = start;
	while (ft_strchr(av[i], '=') != NULL)
	{
		av2 = env_set_new(av, av2, i, 0);
		i++;
	}
	env2 = set_env(av2);
	if (i > start)
	{
		if (av[i] == NULL)
		{
			ft_put_strsplit(env2.envp);
			return (1);
		}
	}
	ft_sh(av + i, env, &env2);
	return (1);
}

int				ft_env(char **av, t_env *env)
{
	char	**av2;

	if (av[0] != NULL && av[1] != NULL)
	{
		if (ft_strcmp(av[0], "env") == 0 && ft_strcmp(av[1], "-i") == 0)
		{
			av2 = NULL;
			env_set(av, av2, env, 2);
			return (1);
		}
		else if (ft_strcmp(av[0], "env") == 0 && ft_strcmp(av[1], "-i") != 0)
		{
			av2 = ft_realloc_tab(env->envp);
			env_set(av, av2, env, 1);
			return (1);
		}
	}
	if (ft_strcmp(av[0], "env") == 0 && av[1] == NULL)
	{
		ft_put_strsplit(env->envp);
		return (1);
	}
	return (0);
}
