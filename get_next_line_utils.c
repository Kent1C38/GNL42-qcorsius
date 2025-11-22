/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:29:34 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/22 12:29:39 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	**get_repertory()
{
	static char	*repertory[1024];
	atexit(cleanup);
	return (repertory);
}

static void	cleanup()
{
	int		i;
	char	**arr;

	arr = get_repertory();
	i = 0;
	while (i < 1024)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
}

