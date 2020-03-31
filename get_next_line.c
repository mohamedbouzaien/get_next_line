/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:54:38 by mbouzaie          #+#    #+#             */
/*   Updated: 2019/05/15 21:41:32 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int				chrloc(char *str, int ch)
{
	size_t		length;

	length = 0;
	if (str)
	{
		while (str[length] != ch && str[length] != '\0')
			length++;
	}
	return (length);
}

char			*ft_strnjoin(const char *s1, const char *s2, size_t len)
{
	char	*s;
	char	*ret;

	if (!(s = ft_strnew(ft_strlen(s1) + len)))
		return (NULL);
	ret = s;
	while (s1 && *s1)
		*s++ = *s1++;
	while (*s2 && s2 && len--)
		*s++ = *s2++;
	return (ret);
}

static int		get_rest_buffer(char buf[BUFF_SIZE + 1], size_t len, char *line)
{
	if (!buf[0] && line[0])
		buf[0] = '\0';
	else
	{
		ft_strncpy(buf, &buf[len + 1], BUFF_SIZE + 1);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int			b_read;
	char		*tmp;
	size_t		len;
	static char	buf[OPEN_MAX][BUFF_SIZE + 1];

	if (BUFF_SIZE <= 0 || fd < 0 || !line || !(*line = ft_strnew(1))
			|| fd > OPEN_MAX)
		return (-1);
	b_read = 1;
	while (b_read > 0)
	{
		if (!buf[fd][0])
			b_read = read(fd, &buf[fd], BUFF_SIZE);
		if (b_read < 0)
			return (b_read);
		len = chrloc(buf[fd], '\n');
		tmp = *line;
		*line = ft_strnjoin(tmp, buf[fd], len);
		ft_strdel(&tmp);
		if ((*line && buf[fd][len]) || (!buf[fd][0] && *line[0]))
			return (get_rest_buffer(buf[fd], len, *line));
		ft_strclr((char *)&buf[fd]);
	}
	return (0);
}
