#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *x;
	
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	x = ft_lstlast(*lst);
	x->new = new;
