/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:52:47 by astehl            #+#    #+#             */
/*   Updated: 2026/04/20 17:38:17 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	numcheck(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

static int	signcheck(char c)
{
	if (c == 45)
		return (-1);
	else
		return (1);
}

static int	cub3d_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == 43 || nptr[i] == 45))
	{
		sign = signcheck(nptr[i]);
		i++;
	}
	while (numcheck(nptr[i]) != 0)
	{
		result *= 10;
		if (result > 255)
			return (result);
		result += (nptr[i] - '0');
		if (numcheck(nptr[i + 1]) == 0)
			break ;
		i++;
	}
	return (result * sign);
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

void	convert_and_add_color(t_game *game, char *line, char c)
{
	char	**tmp;

	if (check_for_double(game, c))
		error_exit(game, "No double colors allowed\n");
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
		game->colors.floor = (cub3d_atoi(tmp[0]) << 16) | (cub3d_atoi(tmp[1])
				<< 8) | cub3d_atoi(tmp[2]);
		game->checks.floor = true;
		return (free_array(tmp));
	}
	game->colors.ceiling = (cub3d_atoi(tmp[0]) << 16) | (cub3d_atoi(tmp[1])
			<< 8) | cub3d_atoi(tmp[2]);
	game->checks.ceiling = true;
	free_array(tmp);
}
