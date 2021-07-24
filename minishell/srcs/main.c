#include "minishell.h"

void main_init(char **env, t_msh *msh)
{
	ft_bzero(msh, sizeof(t_msh));
	

}

int main(int ac, char **av, char **env)
{
	t_msh *msh;
	
	if (ac > 1 || av)
		error_exit("Error: Too Many Arguments\n);
	msh = (t_msh *)malloc(sizeof(t_msh));
	if (!msh)
		error_exit("Error: Memory allocate\n");
	ft_lstadd_front(&g_mem, ft_lstnew(msh));
	main_init(env, msh);
		
}
