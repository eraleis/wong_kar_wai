/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-himd <sal-himd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 19:02:02 by sal-himd          #+#    #+#             */
/*   Updated: 2015/01/23 19:02:05 by sal-himd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>

# include "libft.h"

typedef struct		s_env
{
	char			**envp;
	char			*path;
	char			*home;
	char			*user;
	char			*shell;
	char			*oldpwd;
}					t_env;

int					bultin(char **av, t_env *env, t_env *env2);
t_env				set_env(char **envp);
void				ft_sh1(t_env *env, t_env *env2);
int					wait_and_execute(char *path, char **av, t_env *env);
int					cmd(char **av, t_env *env, t_env *env2);
int					ft_setenv(char **av, t_env *env, t_env *env2);
int					ft_unsetenv(char **av, t_env *env, t_env *env2);
void				ft_sh(char **av, t_env *env, t_env *env2);
char				**ft_ralloctab(char **envp);
int					ft_env(char **av, t_env *env);
void				change_dir(t_env *env, t_env *env2, char *path);
int					ft_cd(char **av, t_env *env, t_env *env2);
char				**supress_var(char **envp, int index);

#endif
