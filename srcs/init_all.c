#include "minishell.h"

/*
** vou usar esse ficheiro para iniciar e allocar memoria 
**   de tudo que precisamos....
*/
void    init_struct_ptr(t_shell *ptr)
{
    ptr->base = NULL;
    ptr->cmd = NULL;
    ptr->enviar = (char **)malloc(sizeof(char *) * 1);
    if (!(ptr->enviar))
        printf("MALLOC FILHO DA PUTA TEM PROBLEMA");
}