
#include "../include/minishell.h"

void	handle_signals(int signo)
{
	if (signo == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(1, "  ", 2);
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	z;

	z = 0;
	while (s1[z] != '\0' || s2[z] != '\0')
	{
		if (s1[z] != s2[z])
			return ((unsigned char)s1[z] - (unsigned char)s2[z]);
		z++;
	}
	return (0);
}

char 	**ft_get_envs(t_msh *msh)
{
	t_list	*list;
	char	**envs;
	int		i;
	int		j;

	i = ft_lstsize(msh->env);
	envs = malloc((i + 1) * sizeof(char *));
	if (!envs)
		close_prog("malloc error\n");
	ft_lstadd_front(&g_mem, ft_lstnew(envs));
	j = 0;
	list = msh->env;
	while (list)
	{
		if (((t_env *)list->content)->val)
		{
			if (!ft_get_envs_values((t_env *)list->content, &envs[j]))
				return (NULL);
			j++;
		}
		list = list->next;
	}
	envs[j] = NULL;
	return (envs);
}

void	ft_file_check_utils(t_msh *msh, t_rdr rdr, int rdr_num, int *fd)
{
	if (!ft_strcmp(rdr.kind, "<"))
	{
		msh->rdr_type[0] = rdr_num;
		*fd = open(rdr.arg, O_RDONLY);
		close(*fd);
	}
	else if (!ft_strcmp(rdr.kind, "<<"))
		msh->rdr_type[0] = rdr_num;
}

int	ft_get_token_utils(t_msh *msh, int *len)
{
	if (ft_check_token2(msh, len))
		return (1);
	if ((msh->line[*len].symb == '>' || msh->line[*len].symb == '<')
		&& msh->line[*len].flag == 0)
	{
		ft_putstr_fd(
			"syntax error near unexpected token 'redirect'\n", 1);
		return (1);
	}
	return (0);
}
