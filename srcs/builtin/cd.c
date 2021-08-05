/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:09:11 by oavelar           #+#    #+#             */
/*   Updated: 2021/08/05 16:08:40 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_get_dir(t_msh *msh, char *key)
{
	t_list	*list;

	list = msh->env;
	while (list)
	{
		if (!ft_strcmp(((t_env *)list->content)->key, key))
		{
			free(((t_env *)list->content)->val);
			((t_env *)list->content)->val = getcwd(NULL, 0);
		}
		list = list->next;
	}
}

char	*ft_get_home_path(t_msh *msh)
{
	t_list	*list;

	list = msh->env;
	while (list)
	{
		if (!ft_strcmp("HOME", ((t_env *)list->content)->key))
			return (((t_env *)list->content)->val);
		list = list->next;
	}
	return (NULL);
}

void	ft_cd_utils(t_msh *msh, char *home, char *err_msg)
{
	if (!home)
	{
		ft_putstr_fd("HOME path not found", 2);
		msh->return_code = 1;
	}
	else if (chdir(home) == 1)
	{
		err_msg = strerror(errno);
		ft_putstr_fd(err_msg, 2);
		msh->return_code = 0;
	}
}

void	ft_cd(t_msh *msh, t_com *com)
{
	char	*err_msg;
	char	*home;

	err_msg = NULL;
	ft_get_dir(msh, "OLDPWD");
	if (!com->args_new || !ft_strcmp(com->args_new[0], "~"))
	{
		home = ft_get_home_path(msh);
		ft_cd_utils(msh, home, err_msg);
		return ;
	}
	if (chdir(com->args_new[0]) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		write(1, "\n", 1);
		msh->return_code = 1;
		return ;
	}
	ft_get_dir(msh, "PWD");
	msh->return_code = 0;
}
