#ifndef MINISHELL_H
# define MINISHELL_H

//just add some ".h" that we may need in the future...

# include <unistd.h>
# include <errno.h>
# include <error.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

/*
quando utilizo "g_" sera sempre um valor global 
g_signal e g_flags, um valor global que e utilizado quando a biblioteca SIGNAL é usada 
uma ideia que vi por isso estou usando assim , nao sei se vai funcionar
*/

int g_flags;
int g_signal;
int g_pwd;

typedef struct s_shell
{
    int         check;
    int         enviar;
}               t_shell;

#endif