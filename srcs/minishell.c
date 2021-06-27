#include "minishell.h"
/*
mai frendi im lost
*/

void    signal_handler(int flag)
{
    if (flag == SIGINT)
    {
        if (g_flags == 1)
            write(1, "\n", 2);
        else
            return (0);
    }
    else if (flag == SIGQUIT)
        if (g_flags == 1)
            write(1, "Exit\n", 5);
}

int main(void)
{
    g_flags = 0;
    signal(SIGINT, signal_handler); //SIGINT e interrupçao do programa (normalmente usado CMD + C)
    signal(SIGQUIT, signal_handler); //SIGQUIT tambem é abortar programa e é usado "CMD + \"
    return (0);
}