/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:25:56 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/17 16:31:13 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_entry *get(t_repertory *rep, int index)
{
	t_repertory	*tmp;

	tmp = rep;
	while (tmp)
	{
		
		tmp = tmp->next;
	}
}