#include "minishell.c"
OLDPWD (OLDPrintWorkingDirectory) contains directory before the last cd command:
void ft_clear_oldpwd(t_msh *msh)
{
	t_list *list;

	list = msh->env;
	while (list)
	{
		if (!ft_strncmp(((t_env *)list->content)->key, "OLDPWD", 6))
		{
			free(((t_env *)list->content)->val);
			((t_env *)list->content)->val = NULL;
			return ;
		}
		list = list->next;
	}
}

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
			error_exit("Error: problem with create list\n");
		ft_lstadd_front(&g_mem, ft_lstnew(new_lst));
		msh->env_args = ft_split(env[i], '=');
		if (!msh->env_args)
			error_exit("Error: str split error\n");
		envp->key = msh->env_args[0];
		envp->val = msh->env_args[1];
		ft_lstadd_back(&msh->env, new_lst);
		free(msh->env_args);
	}
	ft_clear_oldpwd(msh);
}
