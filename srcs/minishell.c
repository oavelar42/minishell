#include "minishell.h"
/*
to tentando fazer por de ma explicao desses sites e de alguns alunos da escola
*/
char    get_dir_with_pwd(char **send)
{
    //ja sei como comecar ....
}

void    read_input(t_shell *ptr)
{
    char *line;

    while (1)
    {
        if (g_pwd)
            free(g_pwd);
        g_signal = 0;
        g_pwd = get_dir_with_pwd(ptr->enviar); //criar função para chegar ao diretório atual
        write(1, g_pwd, 1);
        get_next_line(&line); // vou usar o get next com apenas uma alteração que e quando utilizarmos algum comando vai para proxima linha
        
        if (g_signal != 8)
        // i need create one function for read comands    
            run_cmds(ptr);
    }
}

/*
** signal_handler funciona como mandar bytes por bytes quando pressionar algum comando 
**quando precionamos cmd + c para fechar um arquivo executavel vou utilizar uma variavel PWD 
** que vai funcionar para voltar para pasta de origim e nao voltar para home
*/

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
    g_pwd = NULL;
    signal(SIGINT, signal_handler); //SIGINT e interrupçao do programa (normalmente usado CMD + C)
    signal(SIGQUIT, signal_handler); //SIGQUIT tambem é abortar programa e é usado "CMD + \"
    read_input(&ptr);
    return (0);
}