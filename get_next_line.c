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
#include <stdio.h>

void	read_file(int fd)
{
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read(fd, buff, BUFFER_SIZE);
	get_repertory()[fd] = buff;
}

char	*get_next_line(int fd)
{
	if (fd < 0)
		return (NULL);
	read_file(fd);
	return (get_repertory()[fd]);
}
