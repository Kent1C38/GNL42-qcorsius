/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:48:08 by qcorsius          #+#    #+#             */
/*   Updated: 2025/12/01 15:55:29 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_min(size_t t1, size_t t2)
{
	if (t1 > t2)
		return (t2);
	return (t1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	if (s == NULL)
		return ;
	i = 0;
	p = s;
	while (i < n)
		p[i++] = (unsigned char) '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*array;
	unsigned long long	malloc_size;

	malloc_size = nmemb * size;
	if (malloc_size > INT_MAX)
		return (NULL);
	array = malloc(malloc_size);
	if (array != NULL)
		ft_bzero(array, nmemb * size);
	return (array);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		sub_len;
	int		i;
	int		st;
	char	*sub;

	if (s == NULL)
		return (NULL);
	st = (int) ft_min(start, ft_strlen(s));
	sub_len = (int) ft_min(ft_strlen(s) - st, len);
	sub = ft_calloc(sub_len + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (s[st + i] != '\0' && i < sub_len)
	{
		sub[i] = s[st + i];
		i++;
	}
	return (sub);
}
