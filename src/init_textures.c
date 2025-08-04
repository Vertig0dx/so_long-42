/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:01:43 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/02/16 13:16:30 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_wall(t_mlx *parse)
{
	parse->game->wall.img = mlx_xpm_file_to_image(parse->mlx, 
			"./textures/Wall.xpm", &parse->game->wall.width, 
			&parse->game->wall.height);
	if (parse->game->wall.img == NULL)
		kill_program("Failure while loading wall textures...", 0);
	parse->game->wall.addr = mlx_get_data_addr(parse->game->wall.img,
			&parse->game->wall.bits_per_pixel, 
			&parse->game->wall.line_length, &parse->game->wall.endian);
}

void	init_floor(t_mlx *parse)
{
	parse->game->floor.img = mlx_xpm_file_to_image(parse->mlx, 
			"./textures/Background.xpm",
			&parse->game->floor.width, &parse->game->floor.height);
	if (parse->game->floor.img == NULL)
		kill_program("Failure while loading floor textures...", 0);
	parse->game->floor.addr = mlx_get_data_addr(parse->game->floor.img, 
			&parse->game->floor.bits_per_pixel, &parse->game->floor.line_length,
			&parse->game->floor.endian);
}

void	init_exit(t_mlx	*parse)
{
	parse->game->exit.img = mlx_xpm_file_to_image(parse->mlx, 
			"./textures/Exit.xpm", &parse->game->exit.width, 
			&parse->game->exit.height);
	if (parse->game->exit.img == NULL)
		kill_program("Failure while loading exit textures...", 0);
	parse->game->exit.addr = mlx_get_data_addr(parse->game->exit.img,
			&parse->game->exit.bits_per_pixel, 
			&parse->game->exit.line_length, &parse->game->exit.endian);
}

void	init_collectable(t_mlx *parse)
{
	parse->game->collectable.img = mlx_xpm_file_to_image(parse->mlx,
			"./textures/Sprite_Wisp_Right.xpm", &parse->game->collectable.width,
			&parse->game->collectable.height);
	if (parse->game->collectable.img == NULL)
		kill_program("Failure while loading collectable textures...", 0);
	parse->game->collectable.addr = 
		mlx_get_data_addr(parse->game->collectable.img,
			&parse->game->collectable.bits_per_pixel, 
			&parse->game->collectable.line_length,
			&parse->game->collectable.endian);
}

void	init_player(t_mlx *parse)
{
	parse->game->player_passive.img = mlx_xpm_file_to_image(parse->mlx, 
			"./textures/Mask_Passive.xpm",
			&parse->game->player_passive.width, 
			&parse->game->player_passive.height);
	if (parse->game->player_passive.img == NULL)
		kill_program("Failure while loading passive mask textures...", 0);
	parse->game->player_passive.addr = 
		mlx_get_data_addr(parse->game->player_passive.img,
			&parse->game->player_passive.bits_per_pixel, 
			&parse->game->player_passive.line_length,
			&parse->game->player_passive.endian);
	parse->game->player_active.img = mlx_xpm_file_to_image(parse->mlx, 
			"./textures/Mask_Active.xpm",
			&parse->game->player_active.width, 
			&parse->game->player_active.height);
	if (parse->game->player_active.img == NULL)
		kill_program("Failure while loading collectable textures...", 0);
	parse->game->player_active.addr = 
		mlx_get_data_addr(parse->game->player_active.img,
			&parse->game->player_active.bits_per_pixel, 
			&parse->game->player_active.line_length,
			&parse->game->player_active.endian);
}
