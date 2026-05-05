/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:52:47 by astehl            #+#    #+#             */
/*   Updated: 2026/05/05 21:01:35 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*handle_trailing_spaces(char *line)
{
	int	len;

	len = ft_strlen(line);
	while (line[len - 1] == ' ')
		len--;
	line[len] = '\0';
	return (line);
}

static void	check_color_validity(t_game *game, char **tmp)
{
	int	i;
	int	j;

	i = -1;
	while (tmp[++i])
	{
		j = 0;
		while (tmp[i][j] == ' ')
			j++;
		handle_trailing_spaces(tmp[i]);
		if (tmp[i][j] == '+')
			j++;
		while (tmp[i][j])
		{
			if (!ft_isdigit(tmp[i][j]))
			{
				free_array(tmp);
				error_exit(game, "Color: Non-digit character found\n");
			}
			j++;
		}
		if (cub3d_atoi(tmp[i]) < 0 || cub3d_atoi(tmp[i]) > 255)
			(free_array(tmp), error_exit(game,
					"Color: Number out of range (0-255) found\n"));
	}
}

static void	check_commas(t_game *game, char *line)
{
	int	i;
	int	commas;

	i = -1;
	commas = 0;
	while (line[++i])
	{
		if (line[i] == ',')
			commas++;
	}
	if (commas != 2)
		error_exit(game, "Color code contains more/less than 2 commas\n");
}

void	convert_and_add_color(t_game *game, char *line, char c)
{
	char	**tmp;

	if (check_for_double(game, c))
		error_exit(game, "Exactly 1 RGB code for ceiling/floor is mandatory\n");
	check_commas(game, line);
	tmp = ft_split(line, ',');
	if (!tmp)
		error_exit(game, "Color tmp memory allocation failed\n");
	if (get_array_size(tmp) != 3)
	{
		free_array(tmp);
		error_exit(game, "Color: 3 numbers separated by commas are required\n");
	}
	check_color_validity(game, tmp);
	if (c == 'F')
	{
		game->colors.floor = (cub3d_atoi(tmp[0]) << 16)
			| (cub3d_atoi(tmp[1]) << 8) | cub3d_atoi(tmp[2]);
		game->checks.floor = true;
		return (free_array(tmp));
	}
	game->colors.ceiling = (cub3d_atoi(tmp[0]) << 16)
		| (cub3d_atoi(tmp[1]) << 8) | cub3d_atoi(tmp[2]);
	game->checks.ceiling = true;
	free_array(tmp);
}
