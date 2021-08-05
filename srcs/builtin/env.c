/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:08:55 by oavelar           #+#    #+#             */
/*   Updated: 2021/08/05 16:08:49 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_env(t_list *env, int fd, int declare)
{
	t_env	*envp;

	while (env)
	{
		envp = malloc(sizeof(t_env));
		ft_lstadd_front(&g_mem, ft_lstnew(envp));
		envp = env->content;
		if (declare == 1)
			write(fd, "declare -x ", 11);
		write(fd, envp->key, strlen(envp->key));
		if (envp->val != NULL)
		{
			write(fd, "=", 1);
			if (declare == 1)
			{
				ft_putstr_fd("\"", 1);
				write(fd, envp->val, strlen(envp->val));
				ft_putstr_fd("\"", 1);
			}
			else
				write(fd, envp->val, strlen(envp->val));
		}
		write(fd, "\n", 1);
		env = env->next;
	}
}

void	ft_env(t_msh *msh, t_com *com)
{
	if (com->args_new == NULL)
		ft_print_env(msh->env, 1, 0);
	else
	{
		ft_putstr_fd("command \"env\" shouldnt get arguments\n", 2);
		msh->return_code = 1;
		return ;
	}
	msh->return_code = 0;
}
