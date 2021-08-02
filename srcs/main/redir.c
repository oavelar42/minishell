/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:06:21 by oavelar           #+#    #+#             */
/*   Updated: 2021/08/02 11:48:46 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_rdr_init(t_msh *msh, t_rdr *rdr, char **in, char **out)
{
	msh->rdr_fd[0] = NONE;
	msh->rdr_fd[1] = NONE;
	(*in) = rdr[msh->rdr_type[0]].arg;
	(*out) = rdr[msh->rdr_type[1]].arg;
}

void	ft_launch_rdr_utils_0(t_msh *msh, t_rdr *rdr, char *in)
{
	char	*buff;

	if (!ft_strcmp(rdr[msh->rdr_type[0]].kind, "<"))
		msh->rdr_fd[0] = open(in, O_RDONLY);
	if (!ft_strcmp(rdr[msh->rdr_type[0]].kind, "<<"))
	{
		pipe(msh->rdr_fd2);
		while (1)
		{
			buff = readline("> ");
			if (!ft_strcmp(rdr[msh->rdr_type[0]].arg, buff))
			{
				free(buff);
				break ;
			}
			ft_putstr_fd(buff, msh->rdr_fd2[1]);
			ft_putstr_fd("\n", msh->rdr_fd2[1]);
			free(buff);
		}
		close(msh->rdr_fd2[1]);
		msh->rdr_fd[0] = msh->rdr_fd2[0];
	}
}

void	ft_launch_rdr(t_msh *msh, t_rdr *rdr, t_com *com)
{
	char	*out;
	char	*in;

	ft_rdr_init(msh, rdr, &in, &out);
	if (msh->rdr_type[1] != NONE)
		ft_launch_rdr_utils_1(msh, rdr, out);
	if (msh->rdr_type[0] != NONE)
		ft_launch_rdr_utils_0(msh, rdr, in);
	if (com->com)
	{
		if (msh->rdr_fd[1] != NONE)
		{
			dup2(STDOUT_FILENO, msh->fd_1);
			dup2(msh->rdr_fd[1], STDOUT_FILENO);
			close(msh->rdr_fd[1]);
		}
		if (msh->rdr_fd[0] != -1)
		{
			dup2(msh->rdr_fd[0], msh->fd_0);
			close(msh->rdr_fd[0]);
		}
		ft_builtin(msh, com);
	}
}

void	ft_execute_rdr(t_msh *msh, t_rdr *rdr, t_com *com)
{
	int		num;
	int		status;
	pid_t	pid;

	num = 0;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		ft_launch_rdr(msh, rdr, com);
		exit(msh->return_code);
	}
	if (pid < 0)
		ft_putstr_fd("process crush\n", 2);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	wait(&status);
	ft_rdr_signal(msh, &status);
	ft_free_rdr(rdr, com, &num);
	free(rdr);
}

void	ft_redir_mng(t_com *com, t_msh *msh)
{
	t_rdr	*rdr;
	int		delete;
	int		size;

	msh->return_code = 0;
	ft_rdr_count(com);
	rdr = malloc(com->num_redir * sizeof(t_rdr));
	ft_lstadd_front(&g_mem, ft_lstnew(rdr));
	msh->rdr_type[0] = NONE;
	msh->rdr_type[1] = NONE;
	msh->fd_1 = 1;
	msh->fd_0 = 0;
	delete = com->num_redir * 2;
	size = com->num_args - delete;
	if (size > 0)
	{
		com->args_new = malloc(size * sizeof (char *));
		if (!com->args_new)
			close_prog("malloc error\n");
		ft_lstadd_front(&g_mem, ft_lstnew(com->args_new));
	}
	if (ft_loop(rdr, com))
		ft_exit(msh, com);
	free(com->args);
	ft_redir_mng_utils(com, msh, &delete, rdr);
}
