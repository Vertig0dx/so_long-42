/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:14:24 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 14:59:53 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd, int i)
{
	char	*line;
	char	**map;

	line = get_next_line(fd);
	if (line != NULL)
		map = read_map(fd, i + 1);
	else
	{
		map = (char **) malloc (sizeof (char *) * (i + 1));
		if (map == NULL)
			return (NULL);
	}
	close(fd);
	if (map)
		map[i] = line;
	else
		free(line);
	return (map);
}
