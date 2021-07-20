#include "minishell.h"
/*
o que a funcao get_dir faz e aquela parte inicial do terminal quando aparece seu login
EXEMPLO : esterco:$> sudo apt-get install pornhub
*/
char    *get_dir_with_pwd(char **send)
{
    int     count;
    int     len;
    char    *tmp;
    char    *str;

    count = -1;
    tmp = ft_strdup("");  // não sei se vale a pena usar strdub .... vou pensar
    while (send[++count])
        if (ft_strcmp(send[count], "LOGIN"))
        {
            free(tmp);   // porque usar essas porra de malloc vai dar leaks mais cedo ou mais tarde
            tmp = ft_strdup(send[++count]); // espero que não apareca leaks , em cas tenho valgrind ja vou ir olhando
            return ;
        }
        tmp = ft_strjoin(tmp, ":"); //juntar as xenas , tmp vem com o login e com join agracendo ':' 
        //
        len = ft_strlen(str);
        while (str[--len])
            if (str[len] == '/')
            {
                tmp = ft_strjoin(tmp, &str[++len]);
                return ;
            }
        free(str);
        return (ft_strjoin(tmp, "$>"));
}

void    read_input(t_shell *ptr)
{
    char *line;

    while (1)
    {
        if (g_pwd)
            free(g_pwd); // porque preciso ter o ficheiro livre
        g_signal = 0;
        g_pwd = get_dir_with_pwd(ptr->enviar); //criar função para chegar ao diretório atual
        ft_putstr(g_pwd); // write(1, g_pwd, 1); 
        get_next_line(&line); // vou usar o get next com apenas uma alteração que e quando utilizarmos algum comando vai para proxima linha
        
        if (g_signal != 8)
        // i need create one function for read comands    
            run_cmds(ptr);
        free(ptr); //nao sei se precisa da free , masi como odeio esse malloc vamos a isso
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
            write(1, "\n", 1);
            ft_putstr(g_pwd); // pode dar merda , tomara _|_       
            // return (0); tenho que retorna algo , porque qnd fazemos 'cmd + c' volta para o ficheiro atual
    }
    else if (flag == SIGQUIT)
        if (g_flags == 1)
            write(1, "Exit\n", 5);
}

int main(void)
{
    t_shell ptr;

    g_flags = 0;
    g_signal = 0;
    g_pwd = NULL;
    init_struct_ptr(&ptr);
    signal(SIGINT, signal_handler); //SIGINT e interrupçao do programa (normalmente usado CMD + C)
    signal(SIGQUIT, signal_handler); //SIGQUIT tambem é abortar programa e é usado "CMD + \"
    read_input(&ptr);
    return (0);
}