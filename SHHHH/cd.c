/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-himd <sal-himd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:09:01 by sal-himd          #+#    #+#             */
/*   Updated: 2015/02/05 15:09:04 by sal-himd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static int		isdir(const char *path)
{
	struct stat stats;

	if (stat(path, &stats) == 0 && S_ISDIR(stats.st_mode))
		return (1);
	return (0);
}

void			change_dir(t_env *env, t_env *env2, char *path)
{
	int		i;
	char	*oldpwd;
	char	*name;

	i = 0;
	name = NULL;
	while (env->envp[i] != NULL)
	{
		if (ft_strncmp(env->envp[i], "PWD=", 4) == 0)
			oldpwd = ft_strdup(env->envp[i]);
		i++;
	}
	i = 0;
	chdir(path);
	while (env->envp[i] != NULL)
	{
		if (ft_strncmp(env->envp[i], "PWD=", 4) == 0)
			env->envp[i] = ft_strjoin("PWD=", getcwd(name, 1024));
		if (ft_strncmp(env->envp[i], "OLDPWD=", 7) == 0)
			env->envp[i] = ft_strjoin("OLD", oldpwd);
		i++;
	}
	*env2 = set_env(env->envp);
	*env = set_env(env->envp);
}

static void		ft_cd_home(t_env *env, t_env *env2)
{
	if ((env->home)[0] == '\0')
		ft_putendl_fd("sh1: cd: HOME not set", 2);
	else
		change_dir(env, env2, env->home);
}

int				ft_cd(char **av, t_env *env, t_env *env2)
{
	if (ft_strcmp(av[0], "cd") == 0)
	{
		if (av[1] == NULL)
			ft_cd_home(env, env2);
		else if (ft_strcmp(av[1], "-") == 0)
			change_dir(env, env2, env->oldpwd);
		else if (isdir(av[1]) == 0)
		{
			ft_putstr_fd("cd: not a directory: ", 2);
			ft_putendl_fd(av[1], 2);
		}
		else if (access(av[1], F_OK) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putendl_fd(av[1], 2);
		}
		else
		{
			change_dir(env, env2, av[1]);
		}
		return (1);
	}
	return (0);
}
