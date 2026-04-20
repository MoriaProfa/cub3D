/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 03:14:43 by bgebetsb          #+#    #+#             */
/*   Updated: 2026/04/20 03:14:47 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_ray_props		init_ray_props(double rayDir, double coordinate);
static t_axis			dda_loop(char **map, t_ray_props *ray_props_x,
							t_ray_props *ray_props_y);
static double			calc_hit_point(const t_ray_props *ray_props,
							double ray_length, bool flip);
static t_orientation	assign_wall(double dir, t_orientation negative,
							t_orientation positive);

t_ray	cast_ray(const t_game *game, double dx, double dy)
{
	t_ray_props	ray_props_x;
	t_ray_props	ray_props_y;
	t_axis		axis;
	t_ray		rays;

	ray_props_x = init_ray_props(dx, game->player_x);
	ray_props_y = init_ray_props(dy, game->player_y);
	axis = dda_loop(game->map.data, &ray_props_x, &ray_props_y);
	if (axis == X_AXIS)
	{
		rays.length = ray_props_x.side_dist - ray_props_x.delta_dist;
		rays.hit_point = calc_hit_point(&ray_props_y, rays.length, (dx < 0));
		rays.wall_hit = assign_wall(dx, O_EAST, O_WEST);
	}
	else
	{
		rays.length = ray_props_y.side_dist - ray_props_y.delta_dist;
		rays.hit_point = calc_hit_point(&ray_props_x, rays.length, (dy > 0));
		rays.wall_hit = assign_wall(dy, O_SOUTH, O_NORTH);
	}
	return (rays);
}

static t_ray_props	init_ray_props(double ray_dir, double coordinate)
{
	t_ray_props	ray_props;

	ray_props.direction = ray_dir;
	ray_props.coordinate = coordinate;
	ray_props.delta_dist = fabs(1 / ray_dir);
	ray_props.map = (int)coordinate;
	if (ray_dir < 0)
	{
		ray_props.step = -1;
		ray_props.side_dist = (coordinate - ray_props.map)
			* ray_props.delta_dist;
	}
	else
	{
		ray_props.step = 1;
		ray_props.side_dist = (ray_props.map + 1 - coordinate)
			* ray_props.delta_dist;
	}
	return (ray_props);
}

static t_axis	dda_loop(char **map, t_ray_props *ray_props_x,
		t_ray_props *ray_props_y)
{
	t_axis	axis;

	axis = X_AXIS;
	while (map[ray_props_y->map][ray_props_x->map] != '1')
	{
		if (ray_props_x->side_dist < ray_props_y->side_dist)
		{
			ray_props_x->side_dist += ray_props_x->delta_dist;
			ray_props_x->map += ray_props_x->step;
			axis = X_AXIS;
		}
		else
		{
			ray_props_y->side_dist += ray_props_y->delta_dist;
			ray_props_y->map += ray_props_y->step;
			axis = Y_AXIS;
		}
	}
	return (axis);
}

static double	calc_hit_point(const t_ray_props *ray_props, double ray_length,
		bool flip)
{
	double	hit_point;

	hit_point = ray_props->coordinate + ray_length * ray_props->direction;
	hit_point -= floor(hit_point);
	if (flip)
		hit_point = 1 - hit_point;
	return (hit_point);
}

static t_orientation	assign_wall(double dir, t_orientation negative,
		t_orientation positive)
{
	if (dir < 0)
		return (negative);
	return (positive);
}
