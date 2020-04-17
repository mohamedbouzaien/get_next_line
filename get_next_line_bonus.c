/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 22:37:14 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/17 17:09:20 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int				check_errors(int const fd, char **line)
{
	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL ||
			fd > OPEN_MAX || !(*line = ft_strnew(1)))
		return (-1);
	return (0);
}

static	int		get_rest_buffer(char buff[BUFFER_SIZE + 1], int len, char *line)
{
	if (!buff[0] && line[0])
		buff[0] = '\0';
	else
	{
		if (ft_chrloc(buff, '\n') != -1)
		{
			ft_strncpy(buff, &buff[len + 1], BUFFER_SIZE + 1);
			return (1);
		}
		else
			ft_memset(buff, 0, ft_chrloc(buff, '\0'));
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int			errorsize;
	int			len;
	char		*str;
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1];

	if (check_errors(fd, line) == -1)
		return (-1);
	errorsize = 1;
	while (errorsize > 0)
	{
		if (!buff[fd][0])
			errorsize = read(fd, &buff[fd], BUFFER_SIZE);
		if (errorsize < 0)
			return (errorsize);
		len = ft_chrloc(buff[fd], '\n');
		str = *line;
		if (!(*line = ft_strnjoin(str, buff[fd], len)))
			return (-1);
		free(str);
		str = NULL;
		if ((*line && buff[fd][len]) || (!buff[fd][0] && *line[0]))
			return (get_rest_buffer(buff[fd], len, *line));
		ft_memset(buff[fd], 0, ft_chrloc(buff[fd], '\0'));
	}
	return (0);
}
