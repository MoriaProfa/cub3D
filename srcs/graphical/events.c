#include "cub3D.h"
#include <bits/types/struct_timeval.h>
#include <mlx.h>
#include <sys/time.h>

static long time_diff(struct timeval *old, struct timeval *new)
{
  return ((new->tv_sec - old->tv_sec) * 1000000 + new->tv_usec - old->tv_usec);
}

int key_hook(int keycode, void *param)
{
  t_game *game;

  game = (t_game *)param;
  if (keycode == XK_Escape)
    mlx_loop_end(game->mlx->mlx_ptr);
  return (0);
}

int loop_hook(void *param)
{
  t_game *game;
  static struct timeval last_update;
  struct timeval current_time;
  
  game = (t_game *)param;
  if (gettimeofday(&current_time, NULL) == -1)
    return (game->exit_ind = 1, perror("cub3D: gettimeofday"), mlx_loop_end(param), 1);
  if (last_update.tv_sec != 0 && time_diff(&last_update, &current_time) < 1000000 / FRAMES_PER_SECOND)
    return (0);
  // TODO: Handle movement
  draw_background(game);
  // TODO: Raycasting
  mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->window, game->mlx->main_img.image, 0, 0);
  last_update = current_time;
  return (0);
}
