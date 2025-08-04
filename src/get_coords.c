/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:34:20 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/02/15 17:05:13 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_coords(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
	{
		game->player_x = x;
		game->player_y = y;
	}
	else if (game->map[y][x] == 'E')
	{
		game->exit_x = x;
		game->exit_y = y;
	}
}

void	get_coords(t_game *game)
{
	int		x;
	int		y;

	x = -1;
	y = 0;
	while (game->map[y][++x] && y < game->height)
	{
		if (game->map[y][x] == '\n')
		{
			y++;
			x = -1;
			continue ;
		}
		set_coords(game, x, y);
	}
}
