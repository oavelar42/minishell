#include "minishell.h"

/*handle_signals function that will except ctrl-\ and ctrlc-
SIGINT looks for ctrl-c which has a value of 2
SIGQUIT looks for ctrl-\ which has a value of 9
signal returns the previous value of func that's associated with the given signal. For example, if the previous value of func was SIG_IGN, the return value is also SIG_IGN

char **env:
The main parameter envp is not specified by POSIX but is widely supported.
An alternative method of accessing the environment list is to declare a third argument to the main() function:
This argument can then be treated in the same way as environ, with the difference that its scope is local to main(). Although this feature is widely implemented on UNIX systems, its use should be avoided since, in addition to the scope limitation, it is not specified in SUSv3.
The third line above, where main accepts three parameters, is a Microsoft extension to the ANSI C standard. The third parameter, envp, is an array of pointers to environment variables. The envp array is terminated by a null pointer.

readline will read a line from the terminal and return it, using
prompt as a prompt.  If prompt is NULL or the empty string, no
prompt is issued.
*/


void main_init(char **env, t_msh *msh)
{
	ft_bzero(msh, sizeof(t_msh));
	ft_environment(msh, env);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_signals);
}

void main_loop(t_msh *msh)
{
	while (MINISHELL_LOOP)
	{
		msh->line = NULL;
		msh->com = NULL;
		msh->str = readline("minishell> ");
		if (!msh->str)
		{
			ft_putstr_fd("exit\n", 1);
			break ;
		}
		add_history(msh->str);
		msh->numwaits_pipe = 0;
		msh->pipe_read_fd = 0;
		//ft_handle_process(msh);
	}

}

int main(int ac, char **av, char **env)
{
	t_msh *msh;
	
	if (ac > 1 || av[1])
		error_exit("Error: Too Many Arguments\n");
	msh = (t_msh *)malloc(sizeof(t_msh));
	if (!msh)
		error_exit("Error: Memory allocate\n");
	ft_lstadd_front(&g_mem, ft_lstnew(msh));
	main_init(env, msh);
	main_loop(msh);
	return (0);
}



//ola merda meu git foi a merda