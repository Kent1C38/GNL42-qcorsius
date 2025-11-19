/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:25:58 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/18 16:32:01 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	save(t_entry *entry, char *content)
{
	char	*new_save;
	int		i;
	int		old_save_len;

	old_save_len = ft_strlen(entry->save);
	new_save = (char *) ft_calloc(old_save_len
			+ ft_strlen(content) + 1, sizeof(char));
	if (new_save == NULL)
		return ;
	i = -1;
	while (entry->save[++i])
		new_save[i] = entry->save[i];
	i = -1;
	while (content[++i])
		new_save[old_save_len + i] = content[i];
	free(entry->save);
	entry->save = new_save;
}

int	read_and_save(t_entry *entry)
{
	char	*buff;
	int		i;

	i = 0;
	while (entry->save[i] != '\n')
	{
		if (entry->save[i] == '\0')
		{
			buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
			if (!buff)
				return (0);
			read(entry->fd, buff, BUFFER_SIZE);
			save(entry, buff);
			free(buff);
			if (entry->save[i] == '\0')
				return (0);
		}
		else
			i++;
	}
	return (i + 1);
}

char	*get_line(t_entry *entry)
{
	int		i;
	int		line_len;
	char	*new_save;
	char	*line;

	line_len = read_and_save(entry);
	line = ft_calloc(line_len, sizeof(char));
	if (!line)
		return (NULL);
	new_save = ft_calloc(ft_strlen(entry->save) - line_len + 1, sizeof(char));
	if (!new_save)
	{
		free(line);
		return (NULL);
	}
	i = -1;
	while (entry->save[++i] != '\n')
		line[i] = entry->save[i];
	line[i] = entry->save[i];
	i = -1;
	while (entry->save[++i + line_len] != '\0')
		new_save[i] = entry->save[i + line_len];
	free(entry->save);
	entry->save = new_save;
	return (line);
}

char	*get_next_line(int fd)
{
	static t_entry	*repertory;
	t_entry			*entry;

	if (fd < 0)
		return (NULL);
	if (repertory == NULL)
		repertory = new_entry(fd);
	entry = get_entry(repertory, fd);
	if (entry == NULL)
	{
		entry = new_entry(fd);
		append_entry(&repertory, entry);
	}
	return (get_line(entry));
}
