#include "../cub3D.h"

bool	check_for_double(t_game *game, char c)
{
	if (c == 'N' && game->checks.north)
		return (true);
	if (c == 'E' && game->checks.east)
		return (true);
	if (c == 'S' && game->checks.south)
		return (true);
	if (c == 'W' && game->checks.west)
		return (true);
	if (c == 'F' && game->checks.floor)
		return (true);
	if (c == 'C' && game->checks.ceiling)
		return (true);
	return (false);
}

void	checks_complete(t_game *game)
{
	if (!game->checks.complete && game->checks.north && game->checks.east && 
			game->checks.south && game->checks.west && game->checks.ceiling && 
			game->checks.floor)
		game->checks.complete = true;
}
