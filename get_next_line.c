/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 22:37:14 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/01 17:19:10 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	get_rest_buffer(buff[BUFF_SIZE + 1], size_t len, char *line)
{
	if (!buff[0] && line[0])
		buff[0] = '\0';
	else
	{
		ft_strncpy(buff, &buff[len + 1], BUFF_SIZE + 1);
	}
	return(1);
}

int		get_next_line(int const fd, char **line)
{
	int		errorsize;
	char		*str;
	size_t		len;
	static char	buff[OPEN_MAX][BUFF_SIZE + 1];

	if (BUFF_SIZE <= 0 || fd < 0 || !(*line = (char *)malloc(2)) 
		|| fd > OPEN_MAX)
		return (-1);
	errorsize = 1;
	while (errorsize > 0)
	{
		if (!buff[fd][0])
			errorsize = read(fd, &buff[fd], BUFF_SIZE);
		if (errorsize < 0) 
			return (errorsize);
		len = ft_chrloc(buff[fd], '\n');
		str = *line;
		*line = ft_strnjoin(str, buff[fd], len);
		free(str);
		str = NULL;
		if ((*line && buff[fd][len]) || (!buff[fd][0] && *line[0]))
			return (get_rest_buffer(buff[fd], len, *line));
		ft_strclr((char *)&buf[fd]);-
		return (0);
	}
}
