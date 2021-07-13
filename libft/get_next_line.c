/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:30:45 by oavelar           #+#    #+#             */
/*   Updated: 2021/07/13 15:23:46 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ret(char **line, char **next, char *aux_ptr)
{
	char			*aux;

	if (aux_ptr)
	{
		*line = ft_strndup(*next, aux_ptr - *next);
		aux = ft_strndup(aux_ptr + 1, ft_strlen(aux_ptr + 1));
		free(*next);
		*next = aux;
		return (1);
	}
	if (*next)
	{
		*line = *next;
		*next = NULL;
	}
	return (0);
}

int	get_next_line(char **line)
{
	static char		*next;
	char			ptr[BUFFER_SIZE + 1];
	char			*aux_ptr;
	int				b;

	if (BUFFER_SIZE <= 0 || !line || read(1, ptr, 0) < 0)
		return (-1);
	if (!next)
		next = ft_strndup("", 1);
	aux_ptr = NULL;
	b = 1;
	while (!aux_ptr && (b > 0))
	{
		b = read(1, ptr, BUFFER_SIZE);
		ptr[b] = 0;
		if (next)
			aux_ptr = ft_strjoin(next, ptr);
		else
			aux_ptr = ft_strndup(ptr, b);
		if (next)
			free(next);
		next = aux_ptr;
		aux_ptr = ft_strchr(next, '\n');
	}
	return (ft_ret(line, &next, aux_ptr));
}