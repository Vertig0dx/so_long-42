/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:24:11 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/03/04 14:28:54 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_width(t_game *game)
{
	int		x;

	x = 0;
	while (game->map[0][x] && game->map[0][x] != '\n')
	{
		if (game->map[0][x] != '1')
		{
			kill_map(game);
			kill_program("Your map's first line is suspicious...", 0);
		}
		game->width = x;
		x++;
	}
	if (game->width == 0 || game->map[0][x] == 0 ||
		game->map[0][0] == '\0')
	{
		kill_map(game);
		kill_program("Your first line's width is suspicious...", 0);
	}
}
