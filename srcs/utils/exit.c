/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:53:16 by astehl            #+#    #+#             */
/*   Updated: 2026/04/20 17:18:17 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	free_game(t_game *game)
{
	if (game && game->data)
		free_array(game->data);
	if (game && game->map.data)
		free_array(game->map.data);
	if (game && game->mlx)
		cleanup_mlx(&game->mlx);
	free_paths(game);
}

void	close_game(t_game *game)
{
	free_game(game);
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
