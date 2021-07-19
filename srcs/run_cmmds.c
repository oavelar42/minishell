#include "minishell.h"

void    run_cmds(int *ptr)
{
    int     count;
    t_cmmd    *cmd;

    cmd->commands;
    if (cmd == NULL)
        return ;
    while (cmd)
    {
        if (cmd == '|')
            count = treat_pipe(cmd); // just try something
    }
}

int treat_pipe(t_cmmd *cmd)
{
    int len;
    t_cmmd *new;

    len = 1;
    new = cmd;
    while (new == '|')
    {
        len++;
        new = new->next;
    }
    return (len);
}