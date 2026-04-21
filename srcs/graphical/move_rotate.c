/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:41:55 by bgebetsb          #+#    #+#             */
/*   Updated: 2026/04/20 04:41:56 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	calculate_angle(int keys_pressed, double *angle_ptr);
static void	step_movement(t_game *game, double dx, double dy);

void	handle_rotation(t_game *game, long loop_time)
{
	int		left_right_pressed;
	double	angle;

	angle = (double)loop_time * ROTATE_SPEED;
	left_right_pressed = (game->keys_pressed & O_TURN_LEFT)
		+ (game->keys_pressed & O_TURN_RIGHT);
	if (left_right_pressed == 0)
		return ;
	if (left_right_pressed == O_TURN_LEFT)
		angle = -angle;
	rotate_vector(&game->dx, &game->dy, angle);
	rotate_vector(&game->plane_x, &game->plane_y, angle);
}

void	handle_movement(t_game *game, int keys_pressed, long loop_time)
{
	double	angle;
	double	dx;
	double	dy;
	double	move_speed;

	dx = game->dx;
	dy = game->dy;
	if (!calculate_angle(keys_pressed, &angle))
		return ;
	rotate_vector(&dx, &dy, angle);
	move_speed = (double)loop_time * MOVE_SPEED;
	step_movement(game, dx * move_speed, dy * move_speed);
}

static bool	calculate_angle(int keys_pressed, double *angle_ptr)
{
	int		w_s_pressed;
	int		a_d_pressed;
	double	angle;

	w_s_pressed = (keys_pressed & O_MOVE_FORWARD)
		+ (keys_pressed & O_MOVE_BACKWARD);
	a_d_pressed = (keys_pressed & O_MOVE_LEFT) + (keys_pressed & O_MOVE_RIGHT);
	if (w_s_pressed == O_MOVE_FORWARD + O_MOVE_BACKWARD)
		w_s_pressed = 0;
	if (a_d_pressed == O_MOVE_LEFT + O_MOVE_RIGHT)
		a_d_pressed = 0;
	if (w_s_pressed + a_d_pressed == 0)
		return (false);
	angle = 0;
	if (w_s_pressed == O_MOVE_FORWARD && a_d_pressed == O_MOVE_LEFT)
		angle += 2 * M_PI;
	else if (w_s_pressed == O_MOVE_BACKWARD)
		angle += M_PI;
	if (a_d_pressed == O_MOVE_LEFT)
		angle += 3 * M_PI / 2;
	else if (a_d_pressed == O_MOVE_RIGHT)
		angle += M_PI / 2;
	if (w_s_pressed != 0 && a_d_pressed != 0)
		angle /= 2;
	return (*angle_ptr = angle, true);
}

static void	step_movement(t_game *game, double dx, double dy)
{
	size_t	steps;
	size_t	i;
	double	wall_offset_x;
	double	wall_offset_y;

	steps = (size_t)(hypot(dx, dy) / 0.2) + 1;
	dx /= steps;
	dy /= steps;
	wall_offset_x = 0.1;
	if (dx < 0)
		wall_offset_x = -wall_offset_x;
	wall_offset_y = 0.1;
	if (dy < 0)
		wall_offset_y = -wall_offset_y;
	i = 0;
	while (i < steps)
	{
		if (game->map.data[(int)(game->player_y + dy
				+ wall_offset_y)][(int)game->player_x] != '1')
			game->player_y += dy;
		if (game->map.data[(int)game->player_y][(int)(game->player_x + dx
			+ wall_offset_x)] != '1')
			game->player_x += dx;
		i++;
	}
}

void	rotate_vector(double *x, double *y, double angle)
{
	double	new_x;
	double	new_y;

	new_x = *x * cos(angle) - *y * sin(angle);
	new_y = *x * sin(angle) + *y * cos(angle);
	*x = new_x;
	*y = new_y;
}
