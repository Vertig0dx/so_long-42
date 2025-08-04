/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:56:28 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/03/04 15:33:56 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_game *game, char *filename)
{
	int		fd;

	fd = open (filename, O_RDONLY);
	if (fd == -1)
		kill_program("your map can't be read...", 0);
	game->map = read_map(fd, 0);
	if (!game->map || !game->map[0])
	{
		kill_map(game);
		close(fd);
		kill_program("your map is invalid...", 0);
	}
	close(fd);
	map_width(game);
	map_height(game);
	validate_map(game);
	check_params(game);
	get_coords(game);
	check_path(game);
}
