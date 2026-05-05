/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:53:04 by astehl            #+#    #+#             */
/*   Updated: 2026/05/05 20:57:24 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*handle_lead_trail_spaces(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	while (line[i] == ' ')
		i++;
	while (line[len - 1] == ' ')
		len--;
	line[len] = '\0';
	return (&line[i]);
}

static bool	compare_pathfiles(t_game *game)
{
	char	*n;
	char	*e;
	char	*s;
	char	*w;

	n = game->paths.north;
	e = game->paths.east;
	s = game->paths.south;
	w = game->paths.west;
	if (n && e && !ft_strncmp(n, e, ft_strlen(n) + 1))
		return (true);
	if (n && s && !ft_strncmp(n, s, ft_strlen(n) + 1))
		return (true);
	if (n && w && !ft_strncmp(n, w, ft_strlen(n) + 1))
		return (true);
	if (e && s && !ft_strncmp(e, s, ft_strlen(e) + 1))
		return (true);
	if (e && w && !ft_strncmp(e, w, ft_strlen(e) + 1))
		return (true);
	if (s && w && !ft_strncmp(s, w, ft_strlen(s) + 1))
		return (true);
	return (false);
}

static void	add_path(t_game *game, char *path, char c)
{
	if (c == 'N' && !game->checks.north)
	{
		game->paths.north = ft_strdup(path);
		game->checks.north = true;
	}
	else if (c == 'E' && !game->checks.east)
	{
		game->paths.east = ft_strdup(path);
		game->checks.east = true;
	}
	else if (c == 'S' && !game->checks.south)
	{
		game->paths.south = ft_strdup(path);
		game->checks.south = true;
	}
	else if (c == 'W' && !game->checks.west)
	{
		game->paths.west = ft_strdup(path);
		game->checks.west = true;
	}
}

void	check_and_add_path(t_game *game, char *path, char c)
{
	int	len;

	if (check_for_double(game, c))
		error_exit(game, "Already existing path for a direction found\n");
	len = ft_strlen(path);
	if (len < 5)
		error_exit(game, "Path is too short\n");
	if (path[len - 5] == '/')
		error_exit(game, "Path is not valid\n");
	if (ft_strncmp(&path[len - 4], ".xpm", 5) != 0)
		error_exit(game, "Path needs to be a .xpm file\n");
	add_path(game, path, c);
	if (compare_pathfiles(game))
		error_exit(game, "Every path needs to be unique\n");
}
