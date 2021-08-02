/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:34:39 by oavelar           #+#    #+#             */
/*   Updated: 2021/08/02 13:26:48 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_copy_lst_utils(t_list *lst, t_env *cont)
{
	if (((t_env *)lst->next->content)->key != NULL)
		cont->key = ft_strdup(((t_env *)lst->next->content)->key);
	else
		cont->val = ft_strdup("");
	if (((t_env *)lst->next->content)->val != NULL)
		cont->val = ft_strdup(((t_env *)lst->next->content)->val);
	else
		cont->val = ft_strdup("");
}

void	ft_copy_lst(t_list *lst, t_list **new)
{
	t_env	*cont;

	cont = malloc(sizeof(t_env));
	ft_lstadd_front(&g_mem, ft_lstnew(cont));
	ft_copy_lst_utils(lst, cont);
	(*new) = ft_lstnew(cont);
	ft_lstadd_front(&g_mem, ft_lstnew((*new)));
	while (lst->next)
	{
		cont = malloc(sizeof(t_env));
		ft_lstadd_back(&g_mem, ft_lstnew(cont));
		cont->key = ft_strdup(((t_env *)lst->next->content)->key);
		if (((t_env *)lst->next->content)->val != NULL)
			cont->val = ft_strdup(((t_env *)lst->next->content)->val);
		else
			cont->val = ft_strdup("");
		ft_lstadd_back(new, ft_lstnew(cont));
		lst = lst->next;
	}
}

void	ft_lstdel(t_list *lst, t_list *lst_main)
{
	t_list	*temp;

	temp = lst_main;
	while (temp->next != lst)
		temp = temp->next;
	temp->next = lst->next;
	free(lst);
}

int	ft_mshcmp(t_line_symbol *l1, char *l2)
{
	int	i;

	i = 0;
	while (l1[i].symb || l2[i])
	{
		if (l1[i].symb != l2[i])
			return (l1[i].symb - l2[i]);
		i++;
	}
	return (0);
}

int	ft_check_token_error(t_msh *msh)
{
	if (msh->token == '!')
	{
		ft_putstr_fd(
			"syntax error near unexpected token `newline'\n", 1);
		return (1);
	}
	if (msh->token == '|')
	{
		ft_putstr_fd("open pipe\n", 1);
		return (1);
	}
	return (0);
}
