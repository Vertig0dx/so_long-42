/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:05:05 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/01/10 13:38:18 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_game
{
	int			width;
	int			height;
	int			collectable_num;
	t_data		collectable;
	t_data		player_passive;
	t_data		player_active;
	int			player_num;
	int			player_check;
	int			player_x;
	int			player_y;
	t_data		exit;
	int			exit_num;
	int			exit_x;
	int			exit_y;
	t_data		floor;
	t_data		wall;
	int			exit_check;
	int			collectable_check;
	int			move_num;
	int			**visited;
	char		**map;
	t_data		img;
}				t_game;

typedef struct s_mlxdata
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	int			width;
	int			height;
	t_data		*data;
	t_game		*game;
}				t_mlx;

//INT
int		handle_movement(int keysym, t_mlx *parse);
int		kill_mlx(t_mlx	*parse);
int		render_image(t_mlx *parse);
//CHAR
char	**read_map(int fd, int i);
//VOID
void	check_params(t_game *game);
void	check_path(t_game *game);
void	get_coords(t_game *game);
void	init_collectable(t_mlx *parse);
void	init_exit(t_mlx	*parse);
void	init_floor(t_mlx *parse);
void	init_player(t_mlx *parse);
void	init_textures(t_mlx *parse);
void	init_wall(t_mlx *parse);
void	kill_map(t_game *game);
void	kill_matrix(t_game *game);
void	kill_program(char *errmsg, int errnum);
void	map_height(t_game *game);
void	map_init(t_game *game, char *filename);
void	map_width(t_game *game);
void	mlx_start(t_mlx *parse, t_game *game);
void	validate_map(t_game *game);
void	window_init(t_mlx *parse, t_game *game);

#endif
