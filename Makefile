NAME 		= so_long
CC 			= cc 
FLAGS 		= -Wall -Wextra -Werror -g
MLX			= /mlx/Makefile.gen
MLX_OBJ_DIR	= ./mlx
LIBFT		= /libft/libft.a
INCLUDE 	= -I ./src -I ./libft -I ./mlx
LIB			= -L ./libft -lft -L ./mlx -lX11 -lXext -lm -lmlx -lbsd
OBJ			= $(SRC:.c=.o)
SRC			= 	src/handle_movement.c	\
				src/init_textures.c		\
				src/init_textures2.c	\
				src/kill_map.c			\
				src/kill_matrix.c		\
				src/kill_mlx.c			\
				src/kill_program.c		\
				src/map_height.c		\
				src/map_init.c			\
				src/map_width.c			\
				src/read_map.c			\
				src/validate_map.c		\
				src/get_coords.c		\
				src/so_long.c			\
				src/check_path.c		\
				src/mlx_start.c			\
				
all:		$(MLX) $(LIBFT) $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)
$(MLX):
			@make -C mlx
$(LIBFT):
			@make -C libft

src/%.o:	src/%.c
			$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ)
			@$(MAKE) -C $(MLX_OBJ_DIR) clean

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re 

#-fsanitize=address 