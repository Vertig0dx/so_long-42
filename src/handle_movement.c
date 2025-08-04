/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:39:46 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/01/28 13:49:57 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mlx *parse)
{
	if (parse->game->map[parse->game->player_y - 1]
		[parse->game->player_x] != '1' 
		&& parse->game->map[parse->game->player_y - 1]
		[parse->game->player_x] != 'E')
	{
		parse->game->map[parse->game->player_y]
		[parse->game->player_x] = '0';
		if (parse->game->map[parse->game->player_y - 1]
			[parse->game->player_x] == 'C')
			parse->game->collectable_num--;
		parse->game->map[parse->game->player_y - 1]
		[parse->game->player_x] = 'P';
		parse->game->player_y--;
		parse->game->move_num++;
	}
	else if (parse->game->map[parse->game->player_y - 1]
		[parse->game->player_x] == 'E'
		&& parse->game->collectable_num == 0)
	{
		parse->game->move_num++;
		kill_mlx(parse);
	}
}

void	move_down(t_mlx *parse)
{
	if (parse->game->map[parse->game->player_y + 1]
		[parse->game->player_x] != '1' 
		&& parse->game->map[parse->game->player_y + 1]
		[parse->game->player_x] != 'E')
	{
		parse->game->map[parse->game->player_y]
		[parse->game->player_x] = '0';
		if (parse->game->map[parse->game->player_y + 1]
			[parse->game->player_x] == 'C')
			parse->game->collectable_num--;
		parse->game->map[parse->game->player_y + 1]
		[parse->game->player_x] = 'P';
		parse->game->player_y++;
		parse->game->move_num++;
	}
	else if (parse->game->map[parse->game->player_y + 1]
		[parse->game->player_x] == 'E'
		&& parse->game->collectable_num == 0)
	{
		parse->game->move_num++;
		kill_mlx(parse);
	}
}

void	move_left(t_mlx *parse)
{
	if (parse->game->map[parse->game->player_y]
		[parse->game->player_x - 1] != '1' 
		&& parse->game->map[parse->game->player_y]
		[parse->game->player_x - 1] != 'E')
	{
		parse->game->map[parse->game->player_y]
		[parse->game->player_x] = '0';
		if (parse->game->map[parse->game->player_y]
			[parse->game->player_x - 1] == 'C')
			parse->game->collectable_num--;
		parse->game->map[parse->game->player_y]
		[parse->game->player_x - 1] = 'P';
		parse->game->player_x--;
		parse->game->move_num++;
	}
	else if (parse->game->map[parse->game->player_y]
		[parse->game->player_x - 1] == 'E'
		&& parse->game->collectable_num == 0)
	{
		parse->game->move_num++;
		kill_mlx(parse);
	}
}

void	move_right(t_mlx *parse)
{
	if (parse->game->map[parse->game->player_y]
		[parse->game->player_x + 1] != '1' 
		&& parse->game->map[parse->game->player_y]
		[parse->game->player_x + 1] != 'E')
	{
		parse->game->map[parse->game->player_y]
		[parse->game->player_x] = '0';
		if (parse->game->map[parse->game->player_y]
			[parse->game->player_x + 1] == 'C')
			parse->game->collectable_num--;
		parse->game->map[parse->game->player_y]
		[parse->game->player_x + 1] = 'P';
		parse->game->player_x++;
		parse->game->move_num++;
	}
	else if (parse->game->map[parse->game->player_y]
		[parse->game->player_x + 1] == 'E'
		&& parse->game->collectable_num == 0)
	{
		parse->game->move_num++;
		kill_mlx(parse);
	}
}

int	handle_movement(int keysym, t_mlx *parse)
{
	if (keysym == XK_Escape)
		kill_mlx(parse);
	if (keysym == 119 || keysym == XK_Up)
		move_up(parse);
	if (keysym == 115 || keysym == XK_Down)
		move_down(parse);
	if (keysym == 97 || keysym == XK_Left)
		move_left(parse);
	if (keysym == 100 || keysym == XK_Right)
		move_right(parse);
	return (0);
}
