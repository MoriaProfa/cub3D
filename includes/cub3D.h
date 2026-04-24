/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:17:35 by astehl            #+#    #+#             */
/*   Updated: 2026/04/24 19:44:16 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900

# define FRAMES_PER_SECOND 60

# define ROTATE_SPEED 0.0000015
# define MOVE_SPEED 0.000003
# define TEXTURE_FLIP 0

# include "../libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>

typedef enum e_orientation
{
	O_NONE,
	O_NORTH,
	O_EAST,
	O_SOUTH,
	O_WEST
}						t_orientation;

typedef enum e_keys
{
	O_TURN_LEFT = 1,
	O_TURN_RIGHT = 1 << 1,
	O_MOVE_FORWARD = 1 << 2,
	O_MOVE_BACKWARD = 1 << 3,
	O_MOVE_LEFT = 1 << 4,
	O_MOVE_RIGHT = 1 << 5,
}						t_keys;

typedef struct s_checks
{
	bool				north;
	bool				east;
	bool				south;
	bool				west;
	bool				floor;
	bool				ceiling;
	bool				complete;
}						t_checks;

typedef struct s_map
{
	char				**data;
	int					min_width;
	int					height;
}						t_map;

typedef struct s_paths
{
	char				*north;
	char				*east;
	char				*south;
	char				*west;
}						t_paths;

typedef struct s_colors
{
	int					floor;
	int					ceiling;
}						t_colors;

typedef struct s_mlx_image
{
	void				*image;
	char				*data_addr;
	int					width;
	int					height;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_mlx_image;

typedef struct s_textures
{
	t_mlx_image			north;
	t_mlx_image			east;
	t_mlx_image			south;
	t_mlx_image			west;
}						t_textures;

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*window;
	t_mlx_image			main_img;
	t_textures			textures;
	bool				wayland;
}						t_mlx;

typedef struct s_game
{
	t_mlx				*mlx;
	char				**data;
	t_paths				paths;
	t_checks			checks;
	t_colors			colors;
	double				player_x;
	double				player_y;
	double				dx;
	double				dy;
	double				plane_x;
	double				plane_y;
	double				direction;
	t_orientation		spawn_orientation;
	int					keys_pressed;
	int					exit_ind;
	t_map				map;
	bool				mouse_enabled;
}						t_game;

typedef enum e_axis
{
	X_AXIS,
	Y_AXIS
}						t_axis;

typedef struct s_ray
{
	double				length;
	t_orientation		wall_hit;
	double				hit_point;
}						t_ray;

typedef struct s_ray_props
{
	double				direction;
	double				coordinate;
	double				delta_dist;
	double				side_dist;
	int					step;
	int					map;
}						t_ray_props;

typedef struct s_line
{
	const t_mlx_image	*tex_img;
	int					texture_x;
	int					*main_img_data;
	size_t				draw_height;
	size_t				skip;
	size_t				start_line;
}						t_line;

// srcs/parsing/checks.c
bool					check_for_double(t_game *game, char c);
void					checks_complete(t_game *game);

// srcs/parsing/colors.c
void					convert_and_add_color(t_game *game, char *line, char c);

// srcs/parsing/map.c
char					*find_map_start(t_game *game, char *buf);
void					first_validity_check_map(t_game *game, char *map,
							char *buf);
void					second_validity_check_map(t_game *game);

// srcs/parsing/parsing.c
void					read_extract_and_validate_file(t_game *game, char *fn);

// srcs/parsing/paths.c
char					*handle_lead_trail_spaces(char *line);
void					check_and_add_path(t_game *game, char *path, char c);

// srcs/parsing/player.c
void					check_player(t_game *game);

// srcs/utils/array_helpers.c
void					*grow_array(void *old_array, size_t old_capacity,
							size_t new_capacity, size_t size);
size_t					get_array_size(char **array);
void					free_array(char **array);

// srcs/utils/exit.c
void					free_game(t_game *game);
void					close_game(t_game *game);
void					error_exit(t_game *game, char *message);

// srcs/utils/cub3d_atoi.c
int						cub3d_atoi(const char *nptr);

// srcs/graphical/init.c
t_mlx					*init_mlx(t_game *game, char **envp);
void					cleanup_mlx(t_mlx **ptr);
void					set_initial_direction(t_game *game);

// srcs/graphical/events.c
int						key_press_hook(int keycode, void *param);
int						key_release_hook(int keycode, void *param);
int						mouse_move_hook(int x, int y, void *param);
int						loop_hook(void *param);

// srcs/graphical/rendering.c
void					draw_background(t_game *game);
void					draw_cubes(t_game *game);

// src/graphical/raycasting.c
t_ray					cast_ray(const t_game *game, double dx, double dy);

// src/graphical/move_rotate.c
void					handle_rotation(t_game *game, long loop_time);
void					handle_movement(t_game *game, int keys_pressed,
							long loop_time);
void					rotate_vector(double *x, double *y, double angle);

#endif
