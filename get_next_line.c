/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:54:38 by mbouzaie          #+#    #+#             */
/*   Updated: 2019/02/11 20:23:57 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
size_t	chrloc(char *str, int ch)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ch)
	{
		i++;
	}
	if (str[i] == ch)
		return (i);
	return (0);
}
char	*ft_strjointillbsn(char *line, char *buff)
{
	char *str;
	size_t lebbuff;

	lebbuff = chrloc(buff, '\n');
	if (lebbuff == 0)
		lebbuff = ft_strlen(buff);
	if (!(str = ft_strnew(ft_strlen(line) + lebbuff)))
		return (NULL);
	ft_strcpy(str, line);
	ft_strlcat(str, buff, lebbuff);
	return (str);
}

int	get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	size_t	errororsize;
	static char *str;
	
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	MALLCHECK((*line = ft_strnew(1)));
	while ((errororsize = read(fd, buff, BUFF_SIZE)))
	{
		buff[errororsize] = '\0';
		MALLCHECK(( *line = ft_strjointillbsn(*line, buff)));
		if ((str = ft_strchr(buff, '\n')))
			break ;
	}
	if (errororsize < BUFF_SIZE)
		return (0);
	return (1);
}
