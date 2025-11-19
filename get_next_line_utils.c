/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:25:56 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/18 16:22:24 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	if (s == NULL)
		return ;
	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = (unsigned char) '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (!size || !nmemb)
		return (NULL);
	array = malloc(nmemb * size);
	if (array != NULL)
		ft_bzero(array, nmemb * size);
	return (array);
}

t_entry	*new_entry(int fd)
{
	t_entry	*entry;

	entry = malloc(sizeof(t_entry));
	if (entry == NULL)
		return (NULL);
	entry->fd = fd;
	entry->save = ft_calloc(1, sizeof(char));
	if (entry->save == NULL)
	{
		free(entry);
		return (NULL);
	}
	entry->next = NULL;
	return (entry);
}

void	append_entry(t_entry **entry, t_entry *new_entry)
{
	t_entry	*tmp;

	tmp = *entry;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_entry;
}

t_entry	*get_entry(t_entry *rep, const int fd)
{
	t_entry	*tmp;

	tmp = rep;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
