/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:08:55 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/03/04 14:06:24 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_ber(char *filename)
{
	int		len;

	len = ft_strlen(filename);
	if (len == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp((filename + len - 4), ".ber") != 0)
		return (0);
	return (1);
}

int	main(int argc, char *av[])
{
	static t_game	game;
	t_mlx			parse;

	if (argc != 2)
		kill_program("Your number of arguments is suspicious...", 0);
	if (check_ber(av[1]) == 0)
		kill_program("Your argument is suspicious...", 0);
	map_init(&game, av[1]);
	mlx_start(&parse, &game);
	return (0);
}
