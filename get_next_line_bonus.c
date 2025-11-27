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

#include "get_next_line_bonus.h"
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

char	*read_file(int fd, char *old)
{
	char	*new_save;
	char	buff[BUFFER_SIZE + 1];
	int		i;
	int		j;

	ft_bzero(buff, sizeof(buff));
	read(fd, buff, BUFFER_SIZE);
	if (buff[0] == '\0')
	{
		if (old[0] == '\0')
		{
			free(old);
			return (NULL);
		}
		return (old);
	}
	new_save = ft_calloc(ft_strlen(old) + ft_strlen(buff) + 1, sizeof(char));
	i = -1;
	j = -1;
	while (old[++i])
		new_save[i] = old[i];
	free(old);
	while (buff[++j])
		new_save[i + j] = buff[j];
	return (new_save);
}

char	*read_from_save(char *rep, int *i)
{
	char	*line;

	while (rep[*i])
	{
		if (rep[*i] == '\n')
		{
			line = ft_substr(rep, 0, *i + 1);
			save(rep, *i + 1, rep);
			return (line);
		}
		*i = *i + 1;
	}
	return (NULL);
}

char	*get_line(int fd, char *rep)
{
	char	*buff;
	char	*line;
	int		i;

	i = 0;
	line = read_from_save(rep, &i);
	if (line)
		return (line);
	buff = read_file(fd, ft_substr(rep, 0, BUFFER_SIZE));
	if (buff == NULL)
		return (NULL);
	while (buff[i] != '\n')
	{
		if (buff[i] == '\0')
			buff = read_file(fd, buff);
		if (buff[i] == '\0' || buff[i] == '\n')
			break ;
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
