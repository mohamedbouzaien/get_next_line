/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 18:51:31 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/17 17:09:28 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

int		get_next_line(const int fd, char **line);
int		ft_chrloc(const char *str, int ch);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strnjoin(const char *s1, const char *s2, int len);
char	*ft_strnew(int size);
void	*ft_memset(void *b, int c, size_t len);
#endif
