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
	int i;

	i = 0;
	while (src[i] != '\0' && (size_t)i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while ((size_t)i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

int	ft_chrloc(char *str, int ch)
{
	size_t	length;

	length = 0;
	if (str)
		while (str[length] != ch && str[length] != '\0')
			length++;
	return (length);
}

char	*ft_strnjoin(const char *s1, const char *s2, size_t len)
{
	char	*s;
	char	*ret;

	if (!(s = (char *)malloc(ft_chrloc(s1,'\0') + len + 1)))
		return (NULL);
	ret = s;
	while (s1 && *s1)
		*s++ = *s1++;
	while (*s2 && s2 && len--)
		*s++ = *s2++;
	return (ret);
}

void	ft_strclr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
}
