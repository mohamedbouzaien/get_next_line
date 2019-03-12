/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:54:38 by mbouzaie          #+#    #+#             */
/*   Updated: 2019/03/05 19:54:19 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int			chrloc(char *str, int ch)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ch)
	{
		i++;
	}
	if (str[i] == ch)
		return (i);
	return (-1);
}

char		*ft_strjointillbsn(char *line, char *buff)
{
	char	*str;
	int		lebbuff;

	lebbuff = chrloc(buff, '\n');
	if (lebbuff == -1)
		lebbuff = ft_strlen(buff);
	if (!(str = ft_strnew(ft_strlen(line) + lebbuff)))
		return (NULL);
	ft_strcpy(str, line);
	ft_strdel(&line);
	ft_strlcat(str, buff, ft_strlen(str) + lebbuff + 1);
	return (str);
}

char		*get_rest_buffer(char *buff)
{
	int			i;
	char		*p;
	char		*str;

	i = 0;
	p = NULL;
	while (i <= BUFF_SIZE)
	{
		if ((i < BUFF_SIZE) && (buff[i] == '\n') && buff[i + 1] != '\n')
		{
			p = &buff[i + 1];
			break ;
		}
		i++;
	}
	if (p != NULL)
	{
		i = ft_strlen(p);
		str = ft_strnew(i);
		ft_strcpy(str, p);
		ft_strclr(buff);
		return (str);
	}
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			errororsize;
	static char *str;
	char		*tmp;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	ft_memset(buff, '\0', BUFF_SIZE);
	*line = ft_strnew(0);
	if (str != NULL)
	{
		*line = ft_strjointillbsn(*line, str);
		tmp = str;
		str = get_rest_buffer(str);
		ft_strdel(&tmp);
	}
	while ((errororsize = read(fd, buff, BUFF_SIZE)))
	{
		*line = ft_strjointillbsn(*line, buff);
		if ((ft_strchr(buff, '\n')))
		{
			str = get_rest_buffer(buff);
			break ;
		}
		ft_strclr(buff);
	}
	return ((errororsize < BUFF_SIZE && !ft_strlen(*line)) ? 0 : 1);
}
