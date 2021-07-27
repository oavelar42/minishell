/*#include "minishell.h"


int ft_get_dollar_utils(t_msh *msh, int *beg, int *end_str, int *val)
{
	*val = ft_get_val_in_dlr(msh, &msh->line[*beg]);
	if (*val == -1)
		return (0);
	*end_str = *beg + *val;
	return (1);
}

int ft_get_dollar(t_msh *msh)
{
	int beg;
	int end_str;
	int val;
	
	beg = -1;
	end_str= 0;
	val = 0;
	while (msh->line[++beg].symb)
	{
		if (msh->line[beg].symb == '$' && msh->line[beg].flag == 0)
		{
			beg++;
			if (((ft_isalnum(msh->line[beg].symb) == 0)
					&& msh->line[beg].symb != '_'
					&& msh->line[beg].symb != '?'
					|| msh->line[beg].flag == 1))
					continue ;
			if (!ft_get_dollar_utils(msh, &beg, &end_str, &val))
				return (0);
			if (ft_check(msh, beg, end_str) == 1)
				return (0);
			beg = beg - 2;
		}
	}
	return (1);
}
*/