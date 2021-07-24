#include "minishell.c"

void ft_environment(t_msh *msh, char **env)
{
	int x;
	t_list *new_lst;
	t_env *envp;

	x = -1;
	while(env[++i])
	{
		envp = malloc(sizeof(t_env));
		if (!envp)
			error_exit("Error: Memory Allocation\n");
		ft_lstadd_front(g_mem, ft_lstnew(envp));
		new_lst = ft_lstnew(envp);
		if (!new_lst)
			error_exit("Error: 

	}
}
