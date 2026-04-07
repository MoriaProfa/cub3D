#include "cub3D.h"

void draw_background(t_game *game) {
  size_t i;
  int *ceiling;
  int *floor;

  ceiling = game->mlx->main_img.data_addr;
  floor = game->mlx->main_img.data_addr + (WINDOW_WIDTH * WINDOW_HEIGHT * 2); // * 2 because 4 Bytes per Pixel, but only half of the screen
  i = 0;
  while (i < WINDOW_WIDTH * WINDOW_HEIGHT / 2)
  {
    *ceiling++ = game->colors.ceiling;
    *floor++= game->colors.floor;
    i++;
  }
}
