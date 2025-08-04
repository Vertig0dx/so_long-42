/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:58:22 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/01/14 18:24:51 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_init(t_mlx *parse, t_game *game)
{
	parse->game = game;
	parse->width = (game->width + 1) * 64;
	parse->height = (game->height + 1) * 64;
	parse->mlx = mlx_init();
	parse->mlx_win = mlx_new_window(parse->mlx, 
			parse->width, parse->height, "So_Long");
}

void	render_sprite(t_mlx *parse, int x, int y)
{
	if (parse->game->map[y][x] == '1')
		mlx_put_image_to_window(parse->mlx, parse->mlx_win, 
			parse->game->wall.img, x * 64, y * 64);
	else if (parse->game->map[y][x] == '0')
		mlx_put_image_to_window(parse->mlx, parse->mlx_win, 
			parse->game->floor.img, x * 64, y * 64);
	else if (parse->game->map[y][x] == 'C')
		mlx_put_image_to_window(parse->mlx, parse->mlx_win, 
			parse->game->collectable.img, x * 64, y * 64);
	else if (parse->game->map[y][x] == 'P' && parse->game->collectable_num != 0)
		mlx_put_image_to_window(parse->mlx, parse->mlx_win, 
			parse->game->player_passive.img, x * 64, y * 64);
	else if (parse->game->map[y][x] == 'P' && parse->game->collectable_num == 0)
		mlx_put_image_to_window(parse->mlx, parse->mlx_win, 
			parse->game->player_active.img, x * 64, y * 64);
	else if (parse->game->map[y][x] == 'E')
		mlx_put_image_to_window(parse->mlx, parse->mlx_win, 
			parse->game->exit.img, x * 64, y * 64);
}

int	render_image(t_mlx *parse)
{
	int		x;
	int		y;
	char	*moves;

	moves = ft_itoa(parse->game->move_num);
	y = 0;
	while (parse->game->map[y])
	{
		x = 0;
		while (parse->game->map[y][x])
		{
			render_sprite(parse, x, y);
			x++;
		}
		y++;
	}
	mlx_string_put(parse->mlx, parse->mlx_win, 10, 10, 
		0xFFFFFFFF, "Number of Moves:");
	mlx_string_put(parse->mlx, parse->mlx_win, 110, 
		10, 0xFFFFFFFF, moves);
	free(moves);
	return (0);
}

void	mlx_start(t_mlx *parse, t_game *game)
{
	window_init(parse, game);
	init_textures(parse);
	render_image(parse);
	mlx_hook(parse->mlx_win, 17, 1L << 0, kill_mlx, parse);
	mlx_key_hook(parse->mlx_win, handle_movement, parse);
	mlx_loop_hook(parse->mlx, render_image, parse);
	mlx_loop(parse->mlx);
}
