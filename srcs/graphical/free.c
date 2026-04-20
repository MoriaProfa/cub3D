/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 04:46:39 by bgebetsb          #+#    #+#             */
/*   Updated: 2026/04/20 04:46:47 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_image(void *mlx_ptr, t_mlx_image *image);

void	cleanup_mlx(t_mlx **ptr)
{
	t_mlx	*mlx;

	mlx = *ptr;
	if (mlx->window)
		mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	free_image(mlx->mlx_ptr, &mlx->main_img);
	free_image(mlx->mlx_ptr, &mlx->textures.north);
	free_image(mlx->mlx_ptr, &mlx->textures.east);
	free_image(mlx->mlx_ptr, &mlx->textures.south);
	free_image(mlx->mlx_ptr, &mlx->textures.west);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	*ptr = NULL;
}

static void	free_image(void *mlx_ptr, t_mlx_image *image)
{
	if (image->image)
	{
		mlx_destroy_image(mlx_ptr, image->image);
		image->image = NULL;
	}
}
