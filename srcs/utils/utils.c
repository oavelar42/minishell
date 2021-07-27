#include "minishell.h"
#include <readline/readline.h>
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

void error_exit(char *i)
{
	write(2, i, ft_strlen(i));
	exit(1);
}


