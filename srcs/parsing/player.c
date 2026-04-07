#include "../../cub3D.h"

static void	set_orientation(t_game *game, char c)
{
	if (c == 'N')
		game->orientation = O_NORTH;
	else if (c == 'E')
		game->orientation = O_EAST;
	else if (c == 'S')
		game->orientation = O_SOUTH;
	else if (c == 'W')
		game->orientation = O_WEST;
}

void	check_player(t_game *game)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	player_count;
	char			*orientation_set;

	i = 0;
	player_count = 0;
	orientation_set = "NESW";
	while (game->map.data[i])
	{
		j = 0;
		while (game->map.data[i][j])
		{
			if (ft_strchr(orientation_set, game->map.data[i][j]))
			{
				player_count++;
				set_orientation(game, game->map.data[i][j]);
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
		error_exit(game, "Exactly one player is mandatory\n");
}
