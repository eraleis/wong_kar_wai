/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-himd <sal-himd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 22:39:54 by sal-himd          #+#    #+#             */
/*   Updated: 2015/01/23 22:39:56 by sal-himd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char			**supress_var(char **envp, int index)
{
	while (envp[index] != NULL)
	{
		envp[index] = envp[index + 1];
		index++;
	}
	return (envp);
}

static t_env	set_env_null(void)
{
	t_env env;

	env.envp = (char **)malloc(sizeof(char *) * 2);
	env.envp[0] = NULL;
	env.home = ft_strnew(1);
	env.user = ft_strnew(1);
	env.path = ft_strdup("/bin:/usr/bin");
	env.shell = ft_strdup("sh1");
	return (env);
}

static t_env	set_env_full(t_env env, char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		env.envp[i] = ft_strdup(envp[i]);
		if (ft_strncmp(envp[i], "HOME=", 5) == 0)
			env.home = ft_strdup(ft_strsub(envp[i], 5, ft_strlen(envp[i]) - 5));
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			env.path = ft_strdup(ft_strsub(envp[i], 5, ft_strlen(envp[i]) - 5));
		if (ft_strncmp(envp[i], "USER=", 5) == 0)
			env.user = ft_strdup(ft_strsub(envp[i], 5, ft_strlen(envp[i]) - 5));
		if (ft_strncmp(envp[i], "OLDPWD=", 7) == 0)
			env.oldpwd = ft_strdup(ft_strsub(envp[i], 7,
				ft_strlen(envp[i]) - 7));
		if (ft_strncmp(envp[i], "SHELL=", 6) == 0)
		{
			env.envp[i] = ft_strdup("SHELL=sh1");
			env.shell = ft_strdup("sh1");
		}
		i++;
	}
	env.envp[i] = NULL;
	return (env);
}

t_env			set_env(char **envp)
{
	t_env	env;
	int		i;

	if (envp == NULL)
		return (set_env_null());
	if (envp[0] == NULL)
		return (set_env_null());
	i = 0;
	while (envp[i] != NULL)
		i++;
	env = set_env_null();
	env.envp = (char **)malloc(sizeof(char *) * (i + 1));
	env = set_env_full(env, envp);
	return (env);
}
