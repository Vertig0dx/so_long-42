/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:36:24 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/03/05 13:03:12 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	border_check(t_game *game, int x, int y)
{
	if (x == 0 || x == game->width || y == 0 || y == game->height)
		return (1);
	return (0);
}

static void	map_check(t_game *game, int x, int y)
{
	if (game->map[y][x] != 'P' && game->map[y][x] != 'E' && 
		game->map[y][x] != 'C' && game->map[y][x] != '1' && 
		game->map[y][x] != '0')
	{
		kill_map(game);
		kill_program("Your map structure has an impostor...", 0);
	}
	if (game->map[y][x] == 'P')
		game->player_num++;
	else if (game->map[y][x] == 'E')
		game->exit_num++;
	else if (game->map[y][x] == 'C')
		game->collectable_num++;
	else if (game->map[y][x] == '1' || game->map[y][x] == '0')
		return ;
	else
	{
		kill_map(game);
		kill_program("Your map structure is missing something...", 0);
	}
}

void	check_params(t_game *game)
{
	if (game->player_num != 1)
	{
		kill_map(game);
		kill_program("Your number of players is suspicious...", 0);
	}
	else if (game->exit_num != 1)
	{
		kill_map(game);
		kill_program("Your number of exits is suspicious...", 0);
	}
	else if (game->collectable_num < 1)
	{
		kill_map(game);
		kill_program("Your number of collectables is suspicious...", 0);
	}
	return ;
}

void	validate_map(t_game *game)
{
	int		x;
	int		y;

	x = -1;
	y = 0;
	while (game->map[y][++x] != '\0')
	{
		if (game->map[y][x] == '\n')
		{
			if (y == game->height)
				break ;
			y++;
			x = -1;
			continue ;
		}
		if (border_check(game, x, y) == 1)
		{
			if (game->map[y][x] != '1')
			{
				kill_map(game);
				kill_program("Your map isn't surrounded by walls...", 0);
			}
		}
		map_check(game, x, y);
	}
}
