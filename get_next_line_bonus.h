/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:13:26 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/22 12:13:45 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stddef.h>


size_t		ft_strlen(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*get_next_line(int fd);
char		*ft_substr(const char *s, unsigned int start, size_t len);
#endif
