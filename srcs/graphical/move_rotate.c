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
static void	rotate_vector(double *x, double *y, double angle);

void	handle_rotation(t_game *game, long loop_time)
{
	int		left_right_pressed;
	double	move_speed;

	// TODO: do sth with loop time
	(void)loop_time;
	move_speed = M_PI / 111;
	left_right_pressed = (game->keys_pressed & O_TURN_LEFT)
		+ (game->keys_pressed & O_TURN_RIGHT);
	if (left_right_pressed == O_TURN_LEFT)
	{
		rotate_vector(&game->dx, &game->dy, -move_speed);
		rotate_vector(&game->plane_x, &game->plane_y, -move_speed);
	}
	else if (left_right_pressed == O_TURN_RIGHT)
	{
		rotate_vector(&game->dx, &game->dy, move_speed);
		rotate_vector(&game->plane_x, &game->plane_y, move_speed);
	}
}

void	handle_movement(t_game *game, int keys_pressed, long loop_time)
{
	char	**map;
	double	angle;
	double	dx;
	double	dy;

	// TODO do sth with loop_time
	(void)loop_time;
	map = game->map.data;
	dx = game->dx;
	dy = game->dy;
	if (!calculate_angle(keys_pressed, &angle))
		return ;
	rotate_vector(&dx, &dy, angle);
	if (map[(int)(game->player_y + dy / 5)][(int)game->player_x] != '1')
		game->player_y += dy / 15;
	if (map[(int)game->player_y][(int)(game->player_x + dx / 5)] != '1')
		game->player_x += dx / 15;
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

static void	rotate_vector(double *x, double *y, double angle)
{
	double	new_x;
	double	new_y;

	new_x = *x * cos(angle) - *y * sin(angle);
	new_y = *x * sin(angle) + *y * cos(angle);
	*x = new_x;
	*y = new_y;
}
