/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:55:06 by mbouzaie          #+#    #+#             */
/*   Updated: 2019/03/06 19:47:04 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>

# define BUFF_SIZE 4
# define MALLCHECK(x) if (!x) return (-1);

int		get_next_line(const int fd, char **line);
#endif
