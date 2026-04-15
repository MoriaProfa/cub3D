/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:52:53 by astehl            #+#    #+#             */
/*   Updated: 2026/04/15 21:54:54 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	check_for_end(char *map, int i)
{
	bool	end;

	end = false;
	while (map[i] == ' ' || map[i] == '\n')
		i++;
	if (map[i] == '\0')
		end = true;
	return (end);
}

char	*find_map_start(char *buf)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			i++;
			continue;
		}
		lines++;
		while (buf[i] && buf[i] != '\n')
			i++;
		if (lines == 6)
		{
			while (buf[i] == '\n')
				i++;
			return (&buf[i]);
		}
	}
	return (NULL);
}

static void	check_surrounding_tiles(t_game *game, int i, int j, char *valid_chars)
{
	char	**map;
	
	map = game->map.data;
	if (j - 1 < 0 || !ft_strchr(valid_chars, map[i][j - 1]))
		error_exit(game, "2nd map validation part failed\n");
	if (j + 1 >= (int)ft_strlen(map[i]) 
		|| !ft_strchr(valid_chars, map[i][j + 1]))
		error_exit(game, "2nd map validation part failed\n");
	if (i - 1 < 0 || j >= (int)ft_strlen(map[i - 1]) 
		|| !ft_strchr(valid_chars, map[i - 1][j]))
		error_exit(game, "2nd map validation part failed\n");
	if (!map[i + 1] || j >= (int)ft_strlen(map[i + 1]) 
		|| !ft_strchr(valid_chars, map[i + 1][j]))
		error_exit(game, "2nd map validation part failed\n");
}//maybe write sth extra for first and last row of the map to be more specific

void	first_validity_check_map(t_game *game, char *map, char *buf)
{
	int		i;
	char	*valid_chars;
	bool	empty_line;

	i = -1;
	valid_chars = "10NESW \n";
	empty_line = false;
	while (map[++i])
	{
		if (!ft_strrchr(valid_chars, map[i]))
			(free(buf), error_exit(game, "Map has invalid character(s)\n"));
		if (map[i] == '\n')
		{
			if (empty_line && !check_for_end(map, i))
				(free(buf), error_exit(game, "Map has empty line(s)\n"));
			empty_line = true;
			game->map.height++;
		}
		else if (map[i] != ' ')
			empty_line = false;
	}
	if (map[i] == '\0')
		game->map.height++;
	printf("Map height: %i\n", game->map.height);//TESTING PRINTF
	if (game->map.height < 3)
		(free(buf), error_exit(game, "Map is too small\n"));
}

void	second_validity_check_map(t_game *game)
{
	int		i;
	int		j;
	int		len;
	char	**map;

	map = game->map.data;
	i = -1;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (len < game->map.min_width)
			game->map.min_width = len;
		if (len > game->map.max_width)
			game->map.max_width = len;
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
				check_surrounding_tiles(game, i, j, "01NESW");
			else if (ft_strchr("NESW", map[i][j]))	
				check_surrounding_tiles(game, i, j, "01");
		}
	}
	if (game->map.min_width < 2)
		error_exit(game, "At least one map-line is not long enough\n");
}
