/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:39:41 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/02/22 15:00:51 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_visits(t_game *game)
{
	int		count_x;
	int		count_y;

	count_y = 0;
	while (count_y < game->height)
	{
		count_x = 0;
		while (count_x < game->width)
		{
			game->visited[count_y][count_x] = 0;
			count_x++;
		}
		count_y++;
	}
}

int	allocate_visits(t_game *game)
{
	int		count;

	game->visited = malloc (sizeof(int *) * (game->height + 2));
	if (game->visited == NULL)
		return (0);
	game->visited[game->height + 1] = NULL;
	count = game->height + 1;
	while (count--)
	{
		game->visited[count] = malloc (sizeof(int) * game->width + 1);
		if (game->visited[count] == NULL)
		{
			while (count < game->width + 1)
				free(game->visited[count++]);
			free(game->visited);
			kill_map(game);
			kill_program("Your flood fill is suspicious...", 1);
		}
	}
	initialize_visits(game);
	return (1);
}

int	flood_fill(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'E' 
			|| game->visited[y][x] == 1)
	{
		if (game->map[y][x] == 'E' && game->visited[y][x] == 0)
		{
			game->exit_check++;
			game->visited[y][x] = 1;
		}
		return (0);
	}
	else
		game->visited[y][x] = 1;
	if (game->map[y][x] == 'C')
		game->collectable_check++;
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
	return (1);
}

void	check_path(t_game *game)
{
	allocate_visits(game);
	flood_fill(game, game->player_x, game->player_y);
	if (game->exit_check != game->exit_num 
		|| game->collectable_check != game->collectable_num)
	{
		kill_matrix(game);
		kill_map(game);
		kill_program("Your map's layout is suspicious...", 0);
	}
	kill_matrix(game);
}
