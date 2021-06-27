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

/*
quando utilizo "g_" sera sempre um valor global 
g_signal e um valor global que e utilizado quando a biblioteca SIGNAL é usada 
*/

int g_flags;

#endif