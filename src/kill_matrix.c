/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:35:02 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/02/16 13:16:58 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill_matrix(t_game *game)
{
	int	i;

	i = 0;
	while (game->visited[i])
		free (game->visited[i++]);
	free (game->visited);
	return ;
}
