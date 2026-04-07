#include "cub3D.h"
#include <mlx.h>
#include <X11/X.h>

static bool init_texture(void *mlx_ptr, t_mlx_image *image, char *path);
static bool init_image(void *mlx_ptr, t_mlx_image *image);
static void free_image(void *mlx, t_mlx_image *image);

t_mlx *init_mlx(t_game *game)
{
  t_mlx *mlx;
  t_paths *paths;

  paths = &game->paths;
  mlx = ft_calloc(1, sizeof(t_mlx));
  if (!mlx)
    return (perror("cub3D: malloc"), NULL);
  mlx->mlx_ptr = mlx_init();
  if (!mlx->mlx_ptr)
    return (perror("cub3D: mlx_init"), free(mlx), NULL);
  if (!init_texture(mlx->mlx_ptr, &mlx->textures.north, paths->north))
    return (perror("cub3D: north texture"), cleanup_mlx(&mlx), NULL);
  if (!init_texture(mlx->mlx_ptr, &mlx->textures.east, paths->east))
    return (perror("cub3D: east texture"), cleanup_mlx(&mlx), NULL);
  if (!init_texture(mlx->mlx_ptr, &mlx->textures.south, paths->south))
    return (perror("cub3D: south texture"), cleanup_mlx(&mlx), NULL);
  if (!init_texture(mlx->mlx_ptr, &mlx->textures.west, paths->west))
    return (perror("cub3D: west texture"), cleanup_mlx(&mlx), NULL);
  if (!init_image(mlx->mlx_ptr, &mlx->main_img))
    return (perror("cub3D: init image"), cleanup_mlx(&mlx), NULL);
  mlx->window = mlx_new_window(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
  if (!mlx->window)
    return (perror("cub3D: mlx_new_window"), cleanup_mlx(&mlx), NULL);
	mlx_key_hook(mlx->window, key_hook, game);
	mlx_hook(mlx->window, DestroyNotify, 0, mlx_loop_end, mlx->mlx_ptr);
	mlx_loop_hook(mlx->mlx_ptr, loop_hook, game);
  return (mlx);
}

static bool init_texture(void *mlx_ptr, t_mlx_image *image, char *path)
{
  image->image = mlx_xpm_file_to_image(mlx_ptr, path, &image->width, &image->height);
  if (!image->image)
    return (false);
  image->data_addr = mlx_get_data_addr(image->image, &image->bits_per_pixel, &image->size_line, &image->endian);
  return (true);
}

static bool init_image(void *mlx_ptr, t_mlx_image *image)
{
  image->image = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
  if (!image->image)
    return (false);
  image->width = WINDOW_WIDTH;
  image->height = WINDOW_HEIGHT;
  image->data_addr = mlx_get_data_addr(image->image, &image->bits_per_pixel, &image->size_line, &image->endian);
  return (true);
}

void cleanup_mlx(t_mlx **ptr)
{
  t_mlx *mlx;

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

static void free_image(void *mlx_ptr, t_mlx_image *image)
{
  if (image->image) {
    mlx_destroy_image(mlx_ptr, image->image);
    image->image = NULL;
  }
}
