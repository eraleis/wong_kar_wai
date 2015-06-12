/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-himd <sal-himd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 00:00:05 by sal-himd          #+#    #+#             */
/*   Updated: 2015/01/24 00:00:07 by sal-himd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int wait_and_execute(char *path, char **av, t_env *env)
{
	pid_t pid;
	pid_t pid2;

	if (access(path, F_OK | X_OK) == -1)
		return (0);
	pid = fork();
	pid2 = wait(NULL);
	pid = pid;
	if (pid != pid2)
	{
		signal(SIGINT, SIG_DFL);
		execve(path, av, env->envp);
		return (1);
	}
	return (1);
}

int cmd(char **av, t_env *env, t_env *env2)
{
	char	**path_array;
	char	*path;
	int		i;

	path_array = ft_strsplit(env->path, ':');
	i = 0;
	while (path_array[i] != NULL)
	{
		path = ft_strnew(ft_strlen(path_array[i]) + ft_strlen(av[0]) + 2);
		path = ft_strjoin(path_array[i], "/");
		path = ft_strjoin(path, av[0]);
		if (wait_and_execute(path, av, env2) == 1)
			return (1);
		i++;
	}
	return (0);
}
