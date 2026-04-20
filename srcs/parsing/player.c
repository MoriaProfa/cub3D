/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:53:04 by astehl            #+#    #+#             */
/*   Updated: 2026/04/20 17:21:43 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

static void	set_orientation(t_game *game, char c)
{
	if (c == 'N')
	{
		game->spawn_orientation = O_NORTH;
		game->direction = M_PI / 2.0;
	}
	else if (c == 'E')
	{
		game->spawn_orientation = O_EAST;
		game->direction = 0;
	}
	else if (c == 'S')
	{
		game->spawn_orientation = O_SOUTH;
		game->direction = M_PI * 1.5;
	}
	else if (c == 'W')
	{
		game->direction = M_PI;
		game->spawn_orientation = O_WEST;
	}
}

void	check_player(t_game *game)
{
	int				i;
	unsigned int	j;
	unsigned int	player_count;
	char			*orientation_set;

	i = -1;
	player_count = 0;
	orientation_set = "NESW";
	while (game->map.data[++i])
	{
		j = 0;
		while (game->map.data[i][j])
		{
			if (ft_strchr(orientation_set, game->map.data[i][j]))
			{
				player_count++;
				set_orientation(game, game->map.data[i][j]);
				game->player_y = i + 0.5;
				game->player_x = j + 0.5;
			}
			j++;
		}
	}
	if (player_count != 1)
		error_exit(game, "Exactly one player is mandatory\n");
}
