/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:34:19 by astehl            #+#    #+#             */
/*   Updated: 2026/04/21 20:30:30 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nExactly one .cub file as argument is mandatory\n",
			2);
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	game.map.min_width = INT_MAX;
	read_extract_and_validate_file(&game, argv[1]);
	game.mlx = init_mlx(&game);
	if (!game.mlx)
	{
		return (free_game(&game), 1);
	}
	set_initial_direction(&game);
	mlx_loop(game.mlx->mlx_ptr);
	free_game(&game);
	return (game.exit_ind);
}

/*
//just for parsing TESTING (beginning)
void	parser_test_printing(t_game *game)
{
	printf("\n---Game data:---\n");
	int i = -1;
	while (game->data[++i])
		printf("%s\n", game->data[i]);
	printf("\n---Paths:---\nNorth: %s\nEast: %s\nSouth: %s\nWest: %s\n",
		game->paths.north, game->paths.east, game->paths.south,
		game->paths.west);
	printf("\n---Colors:---\nF: 0x%X\nC: 0x%X\n", game->colors.floor,
		game->colors.ceiling);
	printf("\n---Checks:---\nNorth: %i\nEast: %i\nSouth: %i\nWest: %i\nFloor:
		%i\nCeiling: %i\nComplete: %i\n", game->checks.north, game->checks.east,
		game->checks.south, game->checks.west, game->checks.floor,
		game->checks.ceiling, game->checks.complete);
	printf("\n---Game map data:---\n");
	i = -1;
	while (game->map.data[++i])
		printf("%s\n", game->map.data[i]);
	printf("\n---Player:---\nSpawn orientation: ");
	if (game->spawn_orientation == O_NONE)
		printf("None");
	else if (game->spawn_orientation == O_NORTH)
		printf("North\n");
	else if (game->spawn_orientation == O_EAST)
		printf("East\n");
	else if (game->spawn_orientation == O_SOUTH)
		printf("South\n");
	else if (game->spawn_orientation == O_WEST)
		printf("West\n");
	printf("Spawn Position: x: %.0f, y: %.0f\n", game->player_x,
		game->player_y);
}//just for parsing TESTING (end)
*/
