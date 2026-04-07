/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:17:35 by astehl            #+#    #+#             */
/*   Updated: 2026/04/07 20:48:09 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900

# define FRAMES_PER_SECOND 60

# include "../libft/libft.h"
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>

typedef enum    e_orientation
{
    O_NONE,
    O_NORTH,
    O_EAST,
    O_SOUTH,
    O_WEST
}   t_orientation;

typedef struct	s_checks
{
	bool	north;
	bool	east;
	bool	south;
	bool	west;
	bool	floor;
	bool	ceiling;
	bool	complete;
}			t_checks;

typedef struct s_map
{
	char	**data;
	int		min_width;
	int		max_width;//not sure if we actually need that though
	int		height;
}			t_map;

typedef struct s_paths
{
	char	*north;
	char	*east;
	char	*south;
	char	*west;
}			t_paths;

typedef struct s_colors
{
	int	floor; //mlx needs it as an int in (T)RGB form -> https://harm-smits.github.io/42docs/libs/minilibx/colors.html (T = 0, so it can be left out) -> (r << 16) | (g << 8) | b
	int	ceiling;
}		t_colors;

typedef struct s_mlx_image
{
	void *image;
	void *data_addr;
	int width;
	int height;
	int bits_per_pixel;
	int size_line;
	int endian;
} t_mlx_image;

typedef struct s_textures {
	t_mlx_image north;
	t_mlx_image east;
	t_mlx_image south;
	t_mlx_image west;
}	t_textures;

typedef struct s_mlx {
	void *mlx_ptr;
	void *window;
	t_mlx_image main_img;
	t_textures textures;
}	t_mlx;

typedef struct s_game
{
	t_mlx *mlx;
	char			**data;
	t_paths			paths;
	t_checks		checks;
	t_colors		colors;
  double player_x;
	double player_y;
	double direction;
  t_orientation   spawn_orientation;
	int		        exit_ind;
	t_map	        map;
}			        t_game;

// srcs/parsing/checks.c
bool	check_for_double(t_game *game, char c);
void	checks_complete(t_game *game);

// srcs/parsing/colors.c
void convert_and_add_color(t_game *game, char *line, char c);

// srcs/parsing/map.c
char	*find_map_start(char *buf);
void	first_validity_check_map(t_game *game, char *map, char *buf);
void	second_validity_check_map(t_game *game);

// srcs/parsing/parsing.c
void	read_extract_and_validate_file(t_game *game, char *fn);

// srcs/parsing/paths.c
void	check_and_add_path(t_game *game, char *path, char c);

// srcs/parsing/player.c
void	check_player(t_game *game);

// srcs/utils/array_helpers.c
void	*grow_array(void *old_array, size_t old_capacity, size_t new_capacity, size_t size);
size_t	get_array_size(char **array);
void	free_array(char **array);

// srcs/utils/exit.c
void free_game(t_game *game);
void	close_game(t_game *game);
void	error_exit(t_game *game, char *message);

// srcs/graphical/init.c
t_mlx *init_mlx(t_game *game);
void cleanup_mlx(t_mlx **ptr);

// srcs/graphical/events.c
int key_hook(int keycode, void *param);
int loop_hook(void *param);

// srcs/graphical/rendering.c
void draw_background(t_game *game);


#endif
