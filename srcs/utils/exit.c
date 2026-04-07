#include "../../cub3D.h"

static void	free_paths(t_game *game)
{
	if (game && game->paths.north)
		free(game->paths.north);
	if (game && game->paths.south)
		free(game->paths.south);
	if (game && game->paths.east)
		free(game->paths.east);
	if (game && game->paths.west)
		free(game->paths.west);
}

void	close_game(t_game *game)
{
	if (game && game->data)
		free_array(game->data);
	if (game && game->map.data)
		free_array(game->map.data);
	if (game && game->mlx && game->window && game->texture_north)
		mlx_destroy_image(game->mlx, game->texture_north);
	if (game && game->mlx && game->window && game->texture_south)
		mlx_destroy_image(game->mlx, game->texture_south);
	if (game && game->mlx && game->window && game->texture_east)
		mlx_destroy_image(game->mlx, game->texture_east);
	if (game && game->mlx && game->window && game->texture_west)
		mlx_destroy_image(game->mlx, game->texture_west);
	if (game && game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game && game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_paths(game);
	exit(game->exit_ind);
}

void	error_exit(t_game *game, char *message)
{
	if (message)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(message, 2);
		game->exit_ind = 1;
	}
	close_game(game);
}
