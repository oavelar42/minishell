#include "minishell.h"
/*
mai frendi im lost
*/

void    read_input(int *ptr)
{
    char *line;

    while (1)
    {
        g_signal = 0;
        if (g_signal != 8)
        // i need create one function for read comands    
    }
}

void    signal_handler(int flag)
{
    if (g_signal == 7)
    {
        g_signal = 8;
        write(1, "\n", 1);
        return ;
    }
    if (g_signal == 2)
    {
        g_signal = 1;
        write(1, "\n", 1);
        return ;
    }
    if (flag == SIGINT)
    {
        if (g_flags == 1)
            write(1, "\n", 1);
        else
            return (0);
    }
    else if (flag == SIGQUIT)
        if (g_flags == 1)
            write(1, "Exit\n", 5);
}

int main(void)
{
    int ptr;

    g_flags = 0;
    g_signal = 0;
    signal(SIGINT, signal_handler); //SIGINT e interrupçao do programa (normalmente usado CMD + C)
    signal(SIGQUIT, signal_handler); //SIGQUIT tambem é abortar programa e é usado "CMD + \"
    read_input(&ptr);
    return (0);
}