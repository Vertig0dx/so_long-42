/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:02:44 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 13:52:36 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill_map(t_game *game)
{
	int		i;

	i = 0;
	if (!game->map)
		return ;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	return ;
}
