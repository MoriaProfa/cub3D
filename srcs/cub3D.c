/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:34:19 by astehl            #+#    #+#             */
/*   Updated: 2026/04/03 14:36:33 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <mlx.h>

//just for parsing TESTING (beginning)
void parser_test_printing(t_game *game)
{
	printf("\n---Game data:---\n");
	int i = -1;
	while (game->data[++i])
		printf("%s\n", game->data[i]);
	printf("\n---Paths:---\nNorth: %s\nEast: %s\nSouth: %s\nWest: %s\n", game->paths.north, game->paths.east, game->paths.south, game->paths.west);
	printf("\n---Colors:---\nF: 0x%X\nC: 0x%X\n", game->colors.floor, game->colors.ceiling);
	printf("\n---Checks:---\nNorth: %i\nEast: %i\nSouth: %i\nWest: %i\nFloor: %i\nCeiling: %i\nComplete: %i\n", game->checks.north, game->checks.east, game->checks.south, game->checks.west, game->checks.floor, game->checks.ceiling, game->checks.complete);
	printf("\n---Game map data:---\n");
	i = -1;
	while (game->map.data[++i])
		printf("%s\n", game->map.data[i]);
	printf("\n---Player:---\nSpawn orientation: ");
	if (game->spawn_orientation == O_NONE)
		printf("None");
	else if (game->spawn_orientation == O_NORTH)
		printf("North");
	else if (game->spawn_orientation == O_EAST)
		printf("East");
	else if (game->spawn_orientation == O_SOUTH)
		printf("South");
	else if (game->spawn_orientation == O_WEST)
		printf("West\n");
	printf(" (Angle: %.1f°)\n", game->direction);
	printf("Spawn Position: x: %.0f, y: %.0f\n", game->player_x, game->player_y);
}//just for parsing TESTING (end)

/*
void	move_player(int new_x, int new_y, t_game *game)
{
//not sure if that works the same like in so_long though
	if (!new_x || !new_y || !game || game->map.data[new_y][new_x] == '1')
		return ;
	game->player_x = new_x;
	game->player_y = new_y;
}

int	handle_key(int key, t_game *game)
{
//this is for 2D - might need to get adapted for 3D,
	also not sure if this is correct for our usecase
	if (key == XK_Escape)
		close_game(game);
	else if (key == XK_w || key == XK_W)
		move_player(game->player_x, game->player_y - 1, game);
	else if (key == XK_a || key == XK_A)
		move_player(game->player_x - 1, game->player_y, game);
	else if (key == XK_s || key == XK_S)
		move_player(game->player_x, game->player_y + 1, game);
	else if (key == XK_d || key == XK_D)
		move_player(game->player_x + 1, game->player_y, game);
	//key == XK_Left -> for looking left
	//key == XK_Right -> for looking right
	return (0);
}

void	set_coordinates(t_game *game)
{
	int		x;
	int		y;
	char	*player_keyset;

//not sure if that works the same like in so_long though
	y = 0;
	player_keyset = "NESW";
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)//width of that line I guess? this needs to be adjusted if we keep it
		{
			if (ft_strchr(player_keyset, game->map.data[y][x]))
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}
*/

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
	read_extract_and_validate_file(&game, argv[1]); //not done yet, map validation is still incomplete
	parser_test_printing(&game);//TESTING ONLY FUNCTION
	game.mlx = init_mlx(&game);
	if (!game.mlx) {
		return (free_game(&game), 1);
	}
	mlx_loop(game.mlx->mlx_ptr);
	// execution part:
	/*
	//setting game.win_width and game.win_height is missing
	set_coordinates(&game);
	game.mlx = mlx_init();
	initialize_mlx_win_img(&game);
	//render_window(&game);//rendering of everything (ceiling, textures, floor) in the window - no idea how to do that yet, I guess thats your part
	mlx_key_hook(game.window, handle_key, &game);//handle_key needs to be modified by you, too, I guess
	mlx_hook(game.window, 17, 0, close_game, &game);
	return (mlx_loop(game.mlx), 0);
	*/
	free_game(&game);
	return (game.exit_ind);
}
