/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-himd <sal-himd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 17:02:35 by sal-himd          #+#    #+#             */
/*   Updated: 2015/01/15 17:02:37 by sal-himd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		main(int ac, char **av, char **envp)
{
	t_env env;
	t_env env2;

	(void)ac;
	(void)av;
	signal(SIGINT, SIG_IGN);
	env = set_env(envp);
	env2 = set_env(envp);
	while (1)
		ft_sh1(&env, &env2);
	return (0);
}
