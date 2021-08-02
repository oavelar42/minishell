/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:36:56 by oavelar           #+#    #+#             */
/*   Updated: 2021/08/02 13:20:31 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_get_symbol_flag(t_msh *msh, int *i, int *qte, int *dlr)
{
	if ((msh->str[*i] == '\'' && *qte != 2)
		|| (msh->str[*i] == '"' && *qte != 1))
	{
		*qte = ft_get_quote_flag(msh, i, *qte);
		return (0);
	}
	else if (msh->str[*i] == '\\' && ft_get_symbol_flag_utils(msh, i, *qte))
		return (1);
	else
	{
		if ((*dlr) && (msh->str[*i] != '_') && (!ft_isalnum(msh->str[*i])))
		{
			*dlr = 0;
			return (0);
		}
		else if ((*dlr == 0) && (*qte == 1 || (*qte == 2 && msh->str[*i] != '$'
					&& msh->str[*i] != '\\' && msh->str[*i] != '"')))
			return (1);
		else
		{
			if (msh->str[*i] == '$')
				*dlr = 1;
			return (0);
		}
	}
}

t_line_symbol	*ft_get_struct_line(t_msh *msh, int mlc_len)
{
	int				len;
	int				chr;
	int				qte;
	int				dlr;
	t_line_symbol	*line;

	len = -1;
	chr = 0;
	qte = 0;
	dlr = 0;
	line = malloc((mlc_len + 1) * sizeof(t_line_symbol));
	if (!line)
		return (NULL);
	ft_lstadd_front(&g_mem, ft_lstnew(line));
	while (msh->str[++len])
	{
		line[chr].flag = ft_get_symbol_flag(msh, &len, &qte, &dlr);
		if (msh->str[len] == '\\' && ft_get_symbol_flag_utils(msh, &len, qte))
			len++;
		line[chr].symb = msh->str[len];
		chr++;
	}
	line[chr].symb = '\0';
	return (line);
}
