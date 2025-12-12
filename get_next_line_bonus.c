/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:42:28 by qcorsius          #+#    #+#             */
/*   Updated: 2025/12/08 11:28:35 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

void	save(char old[BUFFER_SIZE], char *new)
{
	int	i;
	int	j;

	if (!new)
		return ;
	ft_bzero(old, ft_strlen(old));
	i = ft_strlen(old);
	j = 0;
	while (new[j])
	{
		old[i + j] = new[j];
		j++;
	}
	free(new);
}

char	*get_saved_line(char *saved)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	while (saved[i])
	{
		if (saved[i] == '\n')
		{
			temp = ft_substr(saved, 0, ft_strlen(saved));
			if (!temp)
				return (NULL);
			line = ft_substr(temp, 0, i + 1);
			if (!line)
			{
				free(temp);
				return (NULL);
			}
			save(saved, ft_substr(temp, i + 1, ft_strlen(temp) - i));
			free(temp);
			return (line);
		}
		i++;
	}
	return (NULL);
}

void	create_new_save(char **buff, char **old)
{
	int		i;
	int		j;
	char	*new_line;

	new_line = ft_calloc(ft_strlen(*buff) + ft_strlen(*old) + 1, sizeof(char));
	if (!new_line)
		return ;
	i = 0;
	while (old[0][i] != '\0')
	{
		new_line[i] = old[0][i];
		i++;
	}
	j = 0;
	while (buff[0][j])
	{
		new_line[i + j] = buff[0][j];
		j++;
	}
	free(*old);
	old[0] = new_line;
	ft_bzero(*buff, ft_strlen(*buff));
}

char	*read_and_save(int fd, char save_p[1024], char **buffer, char **raw)
{
	int		i;
	char	*line;

	i = -1;
	while ((*raw)[++i] != '\n')
	{
		if ((*raw)[i] == '\0')
		{
			if (read(fd, *buffer, BUFFER_SIZE) < 0)
			{
				ft_bzero(save_p, ft_strlen(save_p));
				return (NULL);
			}
			create_new_save(buffer, raw);
		}
		if ((*raw)[i] == '\0' || (*raw)[i] == '\n')
			break ;
	}
	line = ft_substr((*raw), 0, i + 1);
	save(save_p, ft_substr((*raw), i + 1, ft_strlen((*raw)) - i + 1));
	if (line && line[0] != '\0')
		return (line);
	if (line)
		free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	saved[1024][BUFFER_SIZE];
	char		*line;
	char		*buffer;
	char		*raw;

	if (fd < 0)
		return (NULL);
	line = get_saved_line(saved[fd]);
	if (line)
		return (line);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	raw = ft_substr(saved[fd], 0, ft_strlen(saved[fd]));
	if (!raw)
	{
		free(buffer);
		return (NULL);
	}
	line = read_and_save(fd, saved[fd], &buffer, &raw);
	free(buffer);
	free(raw);
	if (!line)
		return (NULL);
	return (line);
}
