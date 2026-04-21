/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 03:48:40 by bgebetsb          #+#    #+#             */
/*   Updated: 2026/04/20 03:48:42 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <bits/types/struct_timeval.h>
#include <mlx.h>
#include <sys/time.h>

static long	time_diff(void);

int	key_release_hook(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_Escape)
		mlx_loop_end(game->mlx->mlx_ptr);
	else if (keycode == XK_Left)
		game->keys_pressed ^= O_TURN_LEFT;
	else if (keycode == XK_Right)
		game->keys_pressed ^= O_TURN_RIGHT;
	else if (keycode == XK_w)
		game->keys_pressed ^= O_MOVE_FORWARD;
	else if (keycode == XK_a)
		game->keys_pressed ^= O_MOVE_LEFT;
	else if (keycode == XK_s)
		game->keys_pressed ^= O_MOVE_BACKWARD;
	else if (keycode == XK_d)
		game->keys_pressed ^= O_MOVE_RIGHT;
	return (0);
}

int	key_press_hook(int keycode, void *param)
{
	t_game	*game;

	game = param;
	if (keycode == XK_Left)
		game->keys_pressed |= O_TURN_LEFT;
	else if (keycode == XK_Right)
		game->keys_pressed |= O_TURN_RIGHT;
	else if (keycode == XK_w)
		game->keys_pressed |= O_MOVE_FORWARD;
	else if (keycode == XK_a)
		game->keys_pressed |= O_MOVE_LEFT;
	else if (keycode == XK_s)
		game->keys_pressed |= O_MOVE_BACKWARD;
	else if (keycode == XK_d)
		game->keys_pressed |= O_MOVE_RIGHT;
	return (0);
}

int	mouse_move_hook(int x, int y, void *param)
{
	t_game		*game;
	static int	prev_x = -1;
	int			diff_x;
	double		angle;

	(void)y;
	game = param;
	if (prev_x != -1)
	{
		diff_x = x - prev_x;
		angle = diff_x / (double)WINDOW_WIDTH * M_PI;
		rotate_vector(&game->dx, &game->dy, angle);
		rotate_vector(&game->plane_x, &game->plane_y, angle);
	}
	prev_x = x;
	return (0);
}

int	loop_hook(void *param)
{
	t_game	*game;
	long	loop_time;

	game = (t_game *)param;
	loop_time = time_diff();
	if (loop_time == -1)
		return (game->exit_ind = 1, perror("cub3D: gettimeofday"),
			mlx_loop_end(param), 1);
	if (loop_time < 1000000 / FRAMES_PER_SECOND)
		return (0);
	handle_movement(game, game->keys_pressed, loop_time);
	handle_rotation(game, loop_time);
	draw_background(game);
	draw_cubes(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->window,
		game->mlx->main_img.image, 0, 0);
	return (0);
}

static long	time_diff(void)
{
	static struct timeval	last_update;
	struct timeval			current_time;
	long					time_diff;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	if (last_update.tv_sec == 0)
		return (last_update = current_time, LONG_MAX);
	time_diff = (current_time.tv_sec - last_update.tv_sec) * 1000000
		+ current_time.tv_usec - last_update.tv_usec;
	if (time_diff > 1000000 / FRAMES_PER_SECOND)
		last_update = current_time;
	return (time_diff);
}
