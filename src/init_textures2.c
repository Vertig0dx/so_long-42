/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:12:20 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/02/15 14:30:39 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_mlx *parse)
{
	init_wall(parse);
	init_exit(parse);
	init_floor(parse);
	init_collectable(parse);
	init_player(parse);
}
