#include "minishell.h"

void error_exit(char *i)
{
	write(2, i, ft_strlen(i));
	exit(1);
}
