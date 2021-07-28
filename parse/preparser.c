#include "minishell.h"

int ft_get_quote_flag(t_msh *msh, const *count, int q_flag)
{
	if (msh->str[*count] == '\' && q_flag != 2)
	{
		if (q_flag == 0)
			q_flag = 1;
		else if (q_flag == 1)
			q_flag = 0;
	}
	else if (msh->str[*count] == '"' && q_flag != 1)
	{
		if (q_flag == 0)
			q_flag = 2;
		else if (q_flag == 2)
			q_flag = 0;
	}
	return (q_flag)
}

int ft_line_size(t_msh *msh)
{
	int q_flags;
	int count;
	int str_len;
	int err;
	
	q_flag = 0;
	count = -1;
	str_len = 0;
	while(msh->str[++count])
	{
		q_flag = ft_get_quote_flag(msh, &count, q_flag);


int	ft_preparser(t_msh *msh)
{
	int str_len;
	
	str_len = ft_line_size(msh);
