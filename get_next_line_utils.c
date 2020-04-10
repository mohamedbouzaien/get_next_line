/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:39:47 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/01 18:44:31 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

int		ft_chrloc(const char *str, int ch)
{
	size_t	length;

	length = 0;
	if (str)
		while (str[length] != ch && str[length] != '\0')
			length++;
	if (length == 0 && str[0] != ch)
		return (-1);
	return (length);
}

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	char			*p;
	unsigned char	mychar;

	mychar = (unsigned char)c;
	p = (char *)b;
	i = 0;
	while ((size_t)i < len)
	{
		p[i] = mychar;
		i++;
	}
	return (b);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str =(char *) malloc(size + 1)))
		return (NULL);
	return (ft_memset(str, 0, size + 1));
}

char	*ft_strnjoin(const char *s1, const char *s2, size_t len)
{
	char	*s;
	char	*ret;

	if (!(s = ft_strnew(ft_chrloc(s1, '\0') + len)))
		return (NULL);
	ret = s;
	while (s1 && *s1)
		*s++ = *s1++;
	while (*s2 && s2 && len--)
		*s++ = *s2++;
	return (ret);
}

