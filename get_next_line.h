/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:23:09 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/17 10:31:06 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_entry
{
	int	index;
	int	fd;
}	t_entry;

typedef struct s_repertory
{
	t_entry		entry;
	t_repertory	next;
}	t_repertory;
#endif