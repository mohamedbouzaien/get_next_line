/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:00:46 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/12 16:32:11 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int i;
	int j;

	if (argc == 0)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], 'r');
	else
		return (2);
	j = 0;
	while (j < 100 && (i = get_next_line(fd, &line)) != -1)
	{
		printf("return : %d | %s\n", i, line);
		free(line);
		j++;
	}
	if (argc == 2)
		close(fd);
	return (0);
}
