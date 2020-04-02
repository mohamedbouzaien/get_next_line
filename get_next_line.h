/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 18:51:31 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/02 17:56:54 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define BUFF_SIZE 100

int	get_next_line(const int fd, char **line);
int	ft_chrloc(char *str, int ch);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strnjoin(const char *s1, const char *s2, size_t len);
#endif
