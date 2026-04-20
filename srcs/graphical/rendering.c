/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 03:48:33 by bgebetsb          #+#    #+#             */
/*   Updated: 2026/04/20 03:48:36 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <assert.h>
#include <math.h>

static void			draw_vertical(t_game *game, size_t column,
						const t_ray *ray);
static t_line		fill_line_props(t_game *game, const t_ray *ray,
						size_t column);

void	draw_background(t_game *game)
{
	size_t	i;
	int		*ceiling;
	int		*floor;

	ceiling = (int *)game->mlx->main_img.data_addr;
	floor = (int *)(game->mlx->main_img.data_addr + (WINDOW_WIDTH
				* WINDOW_HEIGHT * 2));
	i = 0;
	while (i < WINDOW_WIDTH * WINDOW_HEIGHT / 2)
	{
		*ceiling++ = game->colors.ceiling;
		*floor++ = game->colors.floor;
		i++;
	}
}

void	draw_cubes(t_game *game)
{
	double	camera_x;
	t_ray	ray;
	size_t	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		camera_x = 2 * i / (double)WINDOW_WIDTH - 1;
		ray = cast_ray(game, game->dx + game->plane_x * camera_x, game->dy
				+ game->plane_y * camera_x);
		draw_vertical(game, i, &ray);
		i++;
	}
}

static t_mlx_image	*select_texture(const t_game *game, const t_ray *ray)
{
	assert(ray->wall_hit != O_NONE);
	if (ray->wall_hit == O_NORTH)
		return (&game->mlx->textures.north);
	else if (ray->wall_hit == O_SOUTH)
		return (&game->mlx->textures.south);
	else if (ray->wall_hit == O_WEST)
		return (&game->mlx->textures.west);
	else
		return (&game->mlx->textures.east);
}

static void	draw_vertical(t_game *game, size_t column, const t_ray *ray)
{
	t_line	line;
	int		*xpm_offset;
	int		texture_y;
	size_t	i;

	line = fill_line_props(game, ray, column);
	i = line.skip / 2;
	while (i < line.draw_height - line.skip / 2)
	{
		texture_y = line.tex_img->height * i / line.draw_height;
		xpm_offset = (int *)line.tex_img->data_addr + line.texture_x + texture_y
			* line.tex_img->width;
		*line.main_img_data = *xpm_offset;
		line.main_img_data += WINDOW_WIDTH;
		i++;
	}
}

static t_line	fill_line_props(t_game *game, const t_ray *ray, size_t column)
{
	t_line	line;

	line.tex_img = select_texture(game, ray);
	line.texture_x = (int)(ray->hit_point * line.tex_img->width);
	line.draw_height = floor((double)WINDOW_HEIGHT / ray->length);
	if (line.draw_height > WINDOW_HEIGHT)
		line.skip = line.draw_height - WINDOW_HEIGHT;
	else
		line.skip = 0;
	line.start_line = ((WINDOW_HEIGHT - line.draw_height + line.skip) / 2)
		* WINDOW_WIDTH * 4;
	line.main_img_data = (int *)(game->mlx->main_img.data_addr + line.start_line
			+ column * 4);
	return (line);
}
