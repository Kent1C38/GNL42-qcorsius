/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:23:09 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/18 16:22:45 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>

typedef struct s_entry
{
	int				fd;
	char			*save;
	struct s_entry	*next;
}	t_entry;

char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
t_entry	*get_entry(t_entry *rep, const int fd);
void	append_entry(t_entry **entry, t_entry *new_entry);
t_entry	*new_entry(int fd);
#endif