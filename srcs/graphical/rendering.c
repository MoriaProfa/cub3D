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

static void			draw_vertical(t_game *game, size_t column, t_ray *ray);

void	draw_background(t_game *game)
{
	size_t	i;
	int		*ceiling;
	int		*floor;

	ceiling = game->mlx->main_img.data_addr;
	floor = game->mlx->main_img.data_addr + (WINDOW_WIDTH * WINDOW_HEIGHT * 2);
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

	for (size_t i = 0; i < WINDOW_WIDTH; i++)
	{
		camera_x = 2 * i / (double)WINDOW_WIDTH - 1;
		ray = cast_ray(game, game->dx + game->plane_x * camera_x, game->dy
				+ game->plane_y * camera_x);
		draw_vertical(game, i, &ray);
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

// TODO: Make this norm compliant
static void	draw_vertical(t_game *game, size_t column, t_ray *ray)
{
	unsigned char	*xpm_offset;
	t_mlx_image		*img;
	int				texture_x;
	unsigned char	*img_data;
	size_t			height;
	size_t			skip;
	size_t			start_line;
	int				texture_y;
	size_t			offset;

	img = select_texture(game, ray);
	texture_x = (int)(ray->hit_point * img->width);
	img_data = game->mlx->main_img.data_addr;
	height = floor((double)WINDOW_HEIGHT / ray->length);
	skip = (height > WINDOW_HEIGHT) ? height - WINDOW_HEIGHT : 0;
	start_line = ((WINDOW_HEIGHT - height + skip) / 2) * WINDOW_WIDTH * 4;
	for (size_t i = skip / 2; i < height - skip / 2; i++)
	{
		texture_y = img->height * i / height;
		xpm_offset = img->data_addr + (texture_x * 4) + (texture_y * img->width
				* 4);
		offset = start_line + column * 4;
		img_data[offset] = xpm_offset[0];
		img_data[offset + 1] = xpm_offset[1];
		img_data[offset + 2] = xpm_offset[2];
		img_data[offset + 3] = xpm_offset[3];
		start_line += WINDOW_WIDTH * 4;
	}
}
