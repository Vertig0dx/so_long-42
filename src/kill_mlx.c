/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:29:11 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/02/22 15:00:17 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	kill_mlx(t_mlx	*parse)
{
	mlx_destroy_image(parse->mlx, parse->game->wall.img);
	mlx_destroy_image(parse->mlx, parse->game->floor.img);
	mlx_destroy_image(parse->mlx, parse->game->exit.img);
	mlx_destroy_image(parse->mlx, parse->game->collectable.img);
	mlx_destroy_image(parse->mlx, parse->game->player_passive.img);
	mlx_destroy_image(parse->mlx, parse->game->player_active.img);
	mlx_destroy_window(parse->mlx, parse->mlx_win);
	mlx_destroy_display(parse->mlx);
	free (parse->mlx);
	kill_map(parse->game);
	exit (1);
}
