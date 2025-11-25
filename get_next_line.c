/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:13:25 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/22 12:13:25 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

void	save(char *rep, int start, char *buff)
{
	int		i;
	char	*buff_cp;

	buff_cp = ft_substr(buff, start, ft_strlen(buff) - start);
	ft_bzero(rep, BUFFER_SIZE);
	i = 0;
	while (buff_cp[i])
	{
		rep[i] = buff_cp[i];
		i++;
	}
	free(buff_cp);
}

char	*read_file(int fd, char *old_save)
{
	size_t	malloc_size;
	char	*new_save;
	char	*buff;
	int		i;
	int		j;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read(fd, buff, BUFFER_SIZE);
	if (buff == NULL || buff[0] == '\0')
	{
		if (old_save[0] == '\0')
			return (NULL);
		return (old_save);
	}
	malloc_size = ft_strlen(old_save) + ft_strlen(buff) + 1;
	new_save = ft_calloc(malloc_size, sizeof(char));
	i = -1;
	j = -1;
	while (old_save[++i])
		new_save[i] = old_save[i];
	while (buff[++j])
		new_save[i + j] = buff[j];
	free(buff);
	return (new_save);
}

char	*get_line(int fd, char *rep)
{
	char	*buff;
	char	*line;
	int		i;

	i = -1;
	while (rep[++i])
	{
		if (rep[i] == '\n')
		{
			line = ft_substr(rep, 0, i + 1);
			save(rep, i + 1, rep);
			return (line);
		}
	}
	buff = read_file(fd, rep);
	if (buff == NULL)
		return (NULL);
	while (buff[i] != '\n')
	{
		if (buff[i] == '\0')
			buff = read_file(fd, buff);
		if (buff[i] == '\0')
			return (buff);
		i++;
	}
	line = ft_substr(buff, 0, i + 1);
	save(rep, i + 1, buff);
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	repertory[1024][BUFFER_SIZE];

	if (fd < 0)
		return (NULL);
	return (get_line(fd, repertory[fd]));
}
